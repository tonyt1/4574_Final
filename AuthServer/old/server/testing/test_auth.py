from nose.tools import assert_true
import requests
import json
import random
import md5
import time
import socket

# Docker Testing
ip = socket.gethostbyname(socket.gethostname())
ip = '172.17.0.2'
BASE_URL = 'http://' + ip + ':5000'

print('BASE_URL: ', BASE_URL)


def test_create_login_account():
    # Creates an account with a random number in username
    # Since it's random it should get a 200 code

    randInt = random.randint(0, 1000)
    username = 'test-account-' + str(randInt)
    password = 'password-' + str(randInt)
    hash_pass = md5.new(password).hexdigest()
    response = requests.get(
        BASE_URL + '/create', auth=(username, hash_pass))
    assert(response.ok)
    time.sleep(5)
    response = requests.get(BASE_URL + '/login',
                            auth=(username, hash_pass))
    assert(response.ok)


def test_create_account_duplicate_username():
    # Attempts to create an account with a username that exists
    #hash_pass = md5.new('tolstykh').hexdigest()
    response = requests.get(
        BASE_URL + '/create', auth=('tony', 'tolstykh'))
    assert(response.status_code == 409)


def test_login_without_auth():
    # Attempts to login without sending authentication header

    response = requests.get(
        BASE_URL + '/login')
    assert(response.status_code == 401)
