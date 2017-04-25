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

client = MongoClient(os.environ.get("DB_PORT_27017_TCP_ADDR"), 27017)
pass_db = client.passdb
pass_posts = pass_db.posts


def create_account():
    """
    Creates an account for user
    Allows user to create an account for future logins

    :rtype: int
    """
    print("\n---------------------------------------------------------------")
    print("Create Account")
    print("Getting Authentication Headers")
    auth = request.authorization
    if auth is not None:
        print("Searching for user '" + auth.username + "'")
        found_username = pass_posts.find_one({"username": auth.username})
        if not found_username:
            print("Creating account for user '" + auth.username + "'")
            credentials = {"username": auth.username,
                           "password": auth.password}
            pass_posts.insert_one(credentials)
            print("---------------------------------------------------------------")
            return jsonify({"Status": "Created Account"}), status.HTTP_200_OK
        else:
            print("Username '" + auth.username + "' already taken")
            print("---------------------------------------------------------------")
            return jsonify({"Status": "Username already exists"}), status.HTTP_409_CONFLICT
    else:
        print("Missing Authentication Header")
        print("---------------------------------------------------------------")
        return jsonify({"Status": "Authentication header required"}), status.HTTP_401_UNAUTHORIZED


def login_account():
    """
    Attempts to log a user in
    Given a username and password checks the database to see if those are the proper credentials to get access

    :rtype: int
    """
    print("\n---------------------------------------------------------------")
    print("Login to  Account")
    print("Getting Authentication Headers")
    auth = request.authorization
    if auth is not None:
        print("Searching for user '" + auth.username + "'")
        found_user = pass_posts.find_one({"username": auth.username})
        if not found_user:
            print("Could not find user '" + auth.username + "'")
            print("---------------------------------------------------------------")
            return jsonify({"Status": "Incorrect Username or Password"}), status.HTTP_401_UNAUTHORIZED
        else:
            if found_user["password"] == auth.password:
                print("Username '" + auth.username + "' logged in")
                print("---------------------------------------------------------------")
                return jsonify({"Status": "Successful Login", "Token" : encoded}), status.HTTP_200_OK
            else:
                print("Username '" + auth.username + "' entered incorrect password")
                print("---------------------------------------------------------------")
                return jsonify({"Status": " "}), status.HTTP_401_UNAUTHORIZED
    else:
        print("Missing Authentication Header")
        print("---------------------------------------------------------------")
        return jsonify({"Status": "Authentication header required"}), status.HTTP_401_UNAUTHORIZED
