# coding: utf-8

from __future__ import absolute_import

from . import BaseTestCase
from six import BytesIO
from flask import json


class TestAccountsController(BaseTestCase):
    """ AccountsController integration test stubs """

    def test_create_account(self):
        """
        Test case for create_account

        Creates an account for user
        """
        response = self.client.open('/accounts/create',
                                    method='GET')
        self.assert200(response, "Response body is : " + response.data.decode('utf-8'))

    def test_login_account(self):
        """
        Test case for login_account

        Attempts to log a user in
        """
        response = self.client.open('/accounts/login',
                                    method='GET')
        self.assert200(response, "Response body is : " + response.data.decode('utf-8'))


if __name__ == '__main__':
    import unittest
    unittest.main()
