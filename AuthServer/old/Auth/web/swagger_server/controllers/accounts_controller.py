import connexion
from datetime import date, datetime
from typing import List, Dict
from six import iteritems
from ..util import deserialize_date, deserialize_datetime
import json
from flask import jsonify
from flask.ext.api import status
from pymongo import MongoClient


def create_account():
    """
    Creates an account for user
    Allows user to create an account for future logins

    :rtype: None
    """
    return 'do some magic!'


def login_account():
    """
    Attempts to log a user in
    Given a username and password checks the database to see if those are the proper credentials to get access

    :rtype: None
    """
    return 'do some magic!'
