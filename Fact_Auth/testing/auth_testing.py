import unittest
import mock
import requests
import time

api_url = "http://127.0.0.1:8000/facts"


class TestExternalMethods(unittest.TestCase):

    def test_create_account(self):
        # THis test is to see if we can successfully create a new account
        str_time = str(time.time())
        username = "user" + str_time[:-8] + str_time[-7:]
        password = "unittest"
        print("\nCreating account: \n\tUsername: " +
              username + "\n\tPassword: " + password)
        response = requests.post(api_url + "/accounts",
                                 auth=(username, password))
        self.assertEqual(200, response.status_code)
        json_response = response.json()
        response_status = json_response["Status"]
        self.assertEqual("Created Account", response_status)

    def test_create_duplicate_account(self):
        # This test is to see if we cannot create two accounts with the same
        # username
        str_time = str(time.time())
        username = "user" + str_time[:-8] + str_time[-7:]
        password = "unittest"
        print("\nCreating account: \n\tUsername: " +
              username + "\n\tPassword: " + password)
        response = requests.post(api_url + "/accounts",
                                 auth=(username, password))
        self.assertEqual(200, response.status_code)
        json_response = response.json()
        response_status = json_response["Status"]
        self.assertEqual("Created Account", response_status)
        print("Attempting to recreate the same user")
        response = requests.post(api_url + "/accounts",
                                 auth=(username, password))
        json_response = response.json()
        response_status = json_response["Status"]
        self.assertEqual("Username already exists", response_status)

    def test_login_with_password(self):
        # This test is to see if we can login with a username and password
        str_time = str(time.time())
        username = "user" + str_time[:-8] + str_time[-7:]
        password = "unittest"
        print("\nCreating account: \n\tUsername: " +
              username + "\n\tPassword: " + password)
        response = requests.post(api_url + "/accounts",
                                 auth=(username, password))
        self.assertEqual(200, response.status_code)
        json_response = response.json()
        response_status = json_response["Status"]
        self.assertEqual("Created Account", response_status)
        print("Attempting to login with password")
        response = requests.get(api_url + "/accounts",
                                auth=(username, password))
        self.assertEqual(200, response.status_code)
        json_response = response.json()
        response_status = json_response["Status"]
        self.assertEqual("Successful Login", response_status)

    def test_login_with_missing_username(self):
        # This test is to see if we cannot login with a fake account
        print("\nAttempting to login with no such username: slkgsdlfkghlsfk")
        response = requests.get(api_url + "/accounts",
                                auth=("slkgsdlfkghlsfk", "password"))
        json_response = response.json()
        response_status = json_response["Status"]
        self.assertEqual("Incorrect Username or Password", response_status)

    def test_login_with_wrong_password(self):
        # This is a test to see if we cannot login with a wrong password
        str_time = str(time.time())
        username = "user" + str_time[:-8] + str_time[-7:]
        password = "unittest"
        print("\nCreating account: \n\tUsername: " +
              username + "\n\tPassword: " + password)
        response = requests.post(api_url + "/accounts",
                                 auth=(username, password))
        self.assertEqual(200, response.status_code)
        json_response = response.json()
        response_status = json_response["Status"]
        self.assertEqual("Created Account", response_status)
        print("Attempting to login with wrong password")
        response = requests.get(api_url + "/accounts",
                                auth=(username, "password"))
        json_response = response.json()
        response_status = json_response["Status"]
        self.assertEqual("Incorrect Username or Password", response_status)


if __name__ == '__main__':
    unittest.main()

