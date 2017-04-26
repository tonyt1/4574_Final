# coding: utf-8

import sys
from setuptools import setup, find_packages

NAME = "swagger_server"
VERSION = "1.0.0"

# To install the library, run the following
#
# python setup.py install
#
# prerequisite: setuptools
# http://pypi.python.org/pypi/setuptools

REQUIRES = ["connexion"]

setup(
    name=NAME,
    version=VERSION,
    description="User Authentication Fact Generator",
    author_email="",
    url="",
    keywords=["Swagger", "User Authentication Fact Generator"],
    install_requires=REQUIRES,
    packages=find_packages(),
    package_data={'': ['swagger/swagger.yaml']},
    include_package_data=True,
    long_description="""\
    Generates a random fact based on the unofficial Wikipedia API  and Natural Language Toolkit modules. API&#39;s use authentication with either Username and Password, or Token.
    """
)

