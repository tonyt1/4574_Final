# coding: utf-8

from __future__ import absolute_import

from . import BaseTestCase
from six import BytesIO
from flask import json


class TestFactsController(BaseTestCase):
    """ FactsController integration test stubs """

    def test_get_fact_random(self):
        """
        Test case for get_fact_random

        Generates a random fact about a random subject
        """
        response = self.client.open('/facts/facts/random',
                                    method='GET')
        self.assert200(response, "Response body is : " + response.data.decode('utf-8'))

    def test_get_fact_subject(self):
        """
        Test case for get_fact_subject

        Generates a random fact about a particular topic
        """
        query_string = [('topic', 'topic_example')]
        response = self.client.open('/facts/facts/subject',
                                    method='GET',
                                    query_string=query_string)
        self.assert200(response, "Response body is : " + response.data.decode('utf-8'))


if __name__ == '__main__':
    import unittest
    unittest.main()
