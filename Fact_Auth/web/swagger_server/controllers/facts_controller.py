import connexion
from datetime import date, datetime
from typing import List, Dict
from six import iteritems
from ..util import deserialize_date, deserialize_datetime
from flask import jsonify
from flask import request
from flask_api import status
import fact_generator as FG
from pymongo import MongoClient
import os

client = MongoClient(os.environ.get("DB_PORT_27017_TCP_ADDR"), 27017)
pass_db = client.passdb
pass_posts = pass_db.posts

def get_fact_random():
    """
    Generates a random fact about a random subject
    
    :rtype: int
    """

    print("\n---------------------------------------------------------------")
    print("Getting Random Fact")
    print("Getting Authentication Headers")
    auth = request.authorization
    if auth is not None:
        print("Searching for user '" + auth.username + "'")
        found_user = pass_posts.find_one({"username": auth.username})
        if not found_user:
            print("Could not find user '" + auth.username + "'")
            print("---------------------------------------------------------------")
            return Response("Incorrect Username or Password", "N/A"), status.HTTP_401_UNAUTHORIZED
        else:
            # Client should be passing in token
            if found_user["token"] == auth.password:
                print("Checking token expiration date")
                if datetime.strptime(found_user["expires"], "%Y-%m-%d %H:%M:%S.%f") < datetime.now():
                    print("Token expired")
                    return Response("Token expired", "Renew")
                else:
                    print("Token still valid")
                    try:
                        subject, facts = FG.get_fact_random()
                    except:
                        return {"error": "An internal error occurred while attempting to contact Wikipedia"}, status.HTTP_502_BAD_GATEWAY
                    response = {}
                    if (subject is not "error"):
                        response["subject"] = subject
                        response["facts"] = facts
                        code = status.HTTP_200_OK
                    else:
                        response["error"] = facts
                        code = status.HTTP_404_NOT_FOUND
                    print("---------------------------------------------------------------")
                    return jsonify(response), code
            else:
                print("Username '" + auth.username +
                      "' entered incorrect token")
                print("---------------------------------------------------------------")
                return Response("Incorrect Username or Password","N/A"), status.HTTP_401_UNAUTHORIZED
    else:
        print("Missing Authentication Header")
        print("---------------------------------------------------------------")
        return Response("Authentication header required", "N/A"), status.HTTP_401_UNAUTHORIZED


def get_fact_subject(topic):
    """
    Generates a random fact about a particular topic
    
    :param topic: The topic that a fact should be related to
    :type topic: str
    :rtype: int
    """
    print("\n---------------------------------------------------------------")
    print("Getting Subject Fact")
    print("Getting Authentication Headers")
    auth = request.authorization
    if auth is not None:
        print("Searching for user '" + auth.username + "'")
        found_user = pass_posts.find_one({"username": auth.username})
        if not found_user:
            print("Could not find user '" + auth.username + "'")
            print("---------------------------------------------------------------")
            return Response("Incorrect Username or Password", "N/A"), status.HTTP_401_UNAUTHORIZED
        else:
            # Client should be passing in token
            if found_user["token"] == auth.password:
                print("Checking token expiration date")
                if datetime.strptime(found_user["expires"], "%Y-%m-%d %H:%M:%S.%f") < datetime.now():
                    print("Token expired")
                    return Response("Token expired", "Renew")
                else:
                    print("Token still valid")
                    try:
                        subject, facts = FG.get_fact_subject(topic)
                    except:
                        return {"error": "An internal error occurred while attempting to contact Wikipedia"}, status.HTTP_502_BAD_GATEWAY
                    response = {}
                    if (subject is not "error"):
                        response["subject"] = subject
                        response["facts"] = facts
                        code = status.HTTP_200_OK
                    else:
                        response["error"] = facts
                        code = status.HTTP_404_NOT_FOUND
                    print("---------------------------------------------------------------")
                    return jsonify(response), code
            else:
                print("Username '" + auth.username +
                      "' entered incorrect token")
                print("---------------------------------------------------------------")
                return Response("Incorrect Username or Password","N/A"), status.HTTP_401_UNAUTHORIZED
    else:
        print("Missing Authentication Header")
        print("---------------------------------------------------------------")
        return Response("Authentication header required", "N/A"), status.HTTP_401_UNAUTHORIZED








def Response(status,token):
    return jsonify({"Status": status, "Token": token})