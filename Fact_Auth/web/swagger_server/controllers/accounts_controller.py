import connexion, os, json, hashlib, random, secrets
from datetime import date, datetime
from typing import List, Dict
from six import iteritems
from ..util import deserialize_date, deserialize_datetime
from flask import jsonify
from flask_api import status
from pymongo import MongoClient
from flask import request
from datetime import datetime, timedelta


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
            token = create_new_token_secrets()
            credentials = {"username": auth.username,
                           "password": hashlib.md5((auth.password).encode('utf-8')).hexdigest(),
                           "token": token,
                           "expires": str(datetime.now() + timedelta(days=2))}
            pass_posts.insert_one(credentials)
            print("---------------------------------------------------------------")
            return Response("Created Account", token), status.HTTP_200_OK

        else:

            print("Username '" + auth.username + "' already taken")
            print("---------------------------------------------------------------")
            return Response("Username already exists", "N/A"), status.HTTP_409_CONFLICT

    else:

        print("Missing Authentication Header")
        print("---------------------------------------------------------------")
        return Response("Authentication header required","N/A"), status.HTTP_401_UNAUTHORIZED


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
            return Response("Incorrect Username or Password", "N/A"), status.HTTP_401_UNAUTHORIZED

        else:

            if found_user["password"] == hashlib.md5((auth.password).encode('utf-8')).hexdigest():

                print("Checking token")

                if datetime.strptime(found_user["expires"], "%Y-%m-%d %H:%M:%S.%f") < datetime.now():

                    print("Token outdated. Creating new token.")
                    print(found_user)
                    update_token(auth.username)
                    found_user = pass_posts.find_one(
                        {"username": auth.username})
                    print(found_user)

                else:
                    print("Token still valid")

                # If the token is valid it will return it, if it's outdated it
                # will return the new one
                print("Username '" + auth.username + "' logged in")
                print("---------------------------------------------------------------")
                return Response("Successful Login", found_user["token"]), status.HTTP_200_OK

            else:

                print("Username '" + auth.username +
                      "' entered incorrect password")
                print("---------------------------------------------------------------")
                return Response("Incorrect Username or Password","N/A"), status.HTTP_401_UNAUTHORIZED

    else:

        print("Missing Authentication Header")
        print("---------------------------------------------------------------")
        return Response("Authentication header required", "N/A"), status.HTTP_401_UNAUTHORIZED

def create_new_token():
    token = ""
    for i in range(16):
        token = token + str(random.randrange(10))
    return hashlib.md5((token).encode('utf-8')).hexdigest()

def create_new_token_secrets():
    token = secrets.token_urlsafe(64)
    return token


def update_token(username):
    new_token = create_new_token_secrets()
    pass_posts.update({"username": username}, {"$set": {
                      "token": new_token, "expires": str(datetime.now() + timedelta(days=2))}})
    return new_token

def Response(status,token):
    return jsonify({"Status": status, "Token": token})
