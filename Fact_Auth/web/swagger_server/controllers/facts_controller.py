import connexion
from datetime import date, datetime, timedelta
from typing import List, Dict
from six import iteritems
from ..util import deserialize_date, deserialize_datetime
from flask import jsonify
from flask import request
from flask_api import status
import fact_generator as FG
from pymongo import MongoClient
import os
import hashlib

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
            token = None

            if found_user["token"] == auth.password:
                print("Checking token expiration date")

                if datetime.strptime(found_user["expires"], "%Y-%m-%d %H:%M:%S.%f") < datetime.now():
                    print("Token expired")
                    return Response("Token expired; please use password again", "Renew")

            elif found_user["password"] == hashlib.md5((auth.password).encode('utf-8')).hexdigest():

                if datetime.strptime(found_user["expires"], "%Y-%m-%d %H:%M:%S.%f") < datetime.now():
                    token = update_token(auth.username)
                    print("Token expired")


            else:
                print("Username '" + auth.username +
                      "' entered incorrect token")
                print("---------------------------------------------------------------")
                return Response("Incorrect Username or Password","N/A"), status.HTTP_401_UNAUTHORIZED

            try:
                subject, facts = FG.get_fact_random()

            except:
                return {"error": "An internal error occurred while attempting to contact Wikipedia"}, status.HTTP_502_BAD_GATEWAY
            
            response = {}

            if (subject is not "error"):
                response["subject"] = subject
                response["facts"] = facts
                code = status.HTTP_200_OK

                if token is not None:
                    response["token"] = token

            else:
                response["error"] = facts
                response["subject"] = subject
                code = status.HTTP_404_NOT_FOUND

                if token is not None:
                    response["token"] = token

            print("---------------------------------------------------------------")
            return jsonify(response), code

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
        
        return_token = False

        if not found_user:
            print("Could not find user '" + auth.username + "'")
            print("---------------------------------------------------------------")
            return Response("Incorrect Username or Password", "N/A"), status.HTTP_401_UNAUTHORIZED
        
        else:

            if found_user["token"] == auth.password:
                print("Checking token expiration date")

                if datetime.strptime(found_user["expires"], "%Y-%m-%d %H:%M:%S.%f") < datetime.now():
                    print("Token expired")
                    return Response("Token expired; please use password again", "Renew")

            elif found_user["password"] == hashlib.md5((auth.password).encode('utf-8')).hexdigest():
                
                if datetime.strptime(found_user["expires"], "%Y-%m-%d %H:%M:%S.%f") < datetime.now():
                    update_token(auth.username)
                    return_token = True

            else:
                print("Username '" + auth.username +
                      "' entered incorrect token")
                print("---------------------------------------------------------------")
                return Response("Incorrect Username or Password","N/A"), status.HTTP_401_UNAUTHORIZED

            try:
                subject, facts = FG.get_fact_subject(topic)
            
            except:
                return {"error": "An internal error occurred while attempting to contact Wikipedia"}, status.HTTP_502_BAD_GATEWAY
            
            response = {}

            if (subject is not "error"):
                response["subject"] = subject
                response["facts"] = facts
                code = status.HTTP_200_OK

                if return_token:
                    response["token"] = found_user["token"]

            else:
                response["error"] = facts
                response["subject"] = subject
                code = status.HTTP_404_NOT_FOUND
                
                if return_token:
                    response["token"] = found_user["token"]

            print("---------------------------------------------------------------")
            return jsonify(response), code

    else:
        print("Missing Authentication Header")
        print("---------------------------------------------------------------")
        return Response("Authentication header required", "N/A"), status.HTTP_401_UNAUTHORIZED


def Response(status,token):
    return jsonify({"Status": status, "Token": token})

def update_token(username):
    new_token = ""
    for i in range(16):
         new_token = new_token + str(random.randrange(10))
    new_token =  hashlib.md5((token).encode('utf-8')).hexdigest()
    pass_posts.update({"username": username}, {"$set": {
                      "token": new_token, "expires": str(datetime.now() + timedelta(days=2))}})
    return new_token