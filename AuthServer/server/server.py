#!/flask/bin/python
from flask import Flask, request, Response
from flask_httpauth import HTTPBasicAuth
import pymongo
import hashlib
import os
from functools import wraps
from pymongo import MongoClient


client = MongoClient(os.environ.get('DB_PORT_27017_TCP_ADDR'),27017)


pass_db = client.passdb
pass_posts = pass_db.posts

app = Flask(__name__)
auth = HTTPBasicAuth()


def check_auth(username, password):
    print('Finding User ', username)
    found_user = pass_posts.find_one({'username': username})
    print(found_user['password'])
    print(password)
    if found_user is not None:
        print("Found User")
        if password == found_user['password']:
            print("Successful Authentication")
            return True
    print('Failed Authentication')
    return False


def authenticate():
    """Sends a 401 response that enables basic auth"""
    return Response(
        'Could not verify your access level for that URL.\n'
        'You have to login with proper credentials', 401,
        {'WWW-Authenticate': 'Basic realm="Login Required"'})


def requires_auth(f):
    @wraps(f)
    def decorated(*args, **kwargs):
        auth = request.authorization
        if not auth or not check_auth(auth.username, auth.password):
            return authenticate()
        return f(*args, **kwargs)
    return decorated


@auth.get_password
def get_pw(username):
    found_username = pass_posts.find_one({'username': auth.username})
    if not found_username:
        return pass_posts.find_one({'username': username})
    return None


@app.route('/create')
@requires_auth
def create():
    auth = request.authorization
    print(auth)
    if auth is not None:
        found_username = pass_posts.find_one({'username': auth.username})
        if not found_username:
            #hash_pw = md5.new(auth.password).hexdigest()
            credentials = {'username': auth.username,
                           'password': auth.password}
            pass_posts.insert_one(credentials)
            return Response('Created account!', 200)
        else:
            return Response('Username already exists', 409)
    else:
        return Response('Authentication requried', 400)


@app.route('/login')
@requires_auth
def index():
    return Response('Successful Login!', 200)


if __name__ == '__main__':
    print('Starting Server!')
    app.run(host='0.0.0.0')
