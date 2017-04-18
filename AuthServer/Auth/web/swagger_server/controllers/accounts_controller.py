import connexion
from datetime import date, datetime
from typing import List, Dict
from six import iteritems
from ..util import deserialize_date, deserialize_datetime
import json
from flask import jsonify
from flask_api import status
from pymongo import MongoClient
from flask import request
import os

client = MongoClient(os.environ.get("DB_PORT_27017_TCP_ADDR"),27017)
pass_db = client.passdb
pass_posts = pass_db.posts

def create_account():
    """
    Creates an account for user
    Allows user to create an account for future logins

    :rtype: None
    """
    auth = request.authorization
    if auth is not None:
        found_username = pass_posts.find_one({"username": auth.username})
        if not found_username:

            credentials = {"username": auth.username,
                           "password": auth.password}
            pass_posts.insert_one(credentials)
            return Response("Created account!", 200)
        else:
            return Response("Username already exists", 409)
    else:
        return Response("Authentication requried", 400)
    print(auth)


def login_account():
    """
    Attempts to log a user in
    Given a username and password checks the database to see if those are the proper credentials to get access

    :rtype: None
    """
    print("Getting authorization headers")
    auth = request.authorization
    if auth is not None:
        print("Finding User ", username)
        found_user = pass_posts.find_one({"username": username})
        if found_user is not None:
            print("Found User")
            if password == found_user["password"]:
                print("Successful Authentication")
                return Response("Successful Authentication",200)
            else:
                print("Failed Authentication (Password)")
                return Response("Invalid credentials", 401)
        else:
            print("Failed Authentication (Username")
            return Response("Invalid credentials", 401)   
    else:
        return Response("Authentication requried", 400)
        

