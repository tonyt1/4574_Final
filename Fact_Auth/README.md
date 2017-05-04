# Authentication and Fact Generator Server

This contribution to the team project contains the Python-Flask server that serves the API for fact generation and authentication. The front-end for facts contains only two entrypoints, both GET commands. One command will return a random fact, and another will attempt to find a fact about the topic that is input by the user. The front-end for authentication contains two endpoints, a GET and a POST. The GET is used to login and retrieve a token for an existing account. The POST is used to create a new account on the server database.

## Running the Code
There are two Docker images currently available to run:

### Without Authentication
To run an image without authentication, either download the [Docker Image](https://hub.docker.com/r/jondef95/fact-gen-server) by running the commands:

`sudo docker run -p 8080:8080 jondef95/fact-gen-server`

### With Authentication
To run an image of the fact generator with authentication, use the Docker-Compose file while in this directory:

`sudo docker-compose up`

The image for the API with authentication can be found on [Docker Hub](https://hub.docker.com/r/jondef95/factauth_web). However, this image will not work without the Docker Compose file because it requires a MongoDB instance, which is not included in the Dockerfile that constructed the API image. 

## Running the Tests
To run the internal and external tests on the API, use the Docker-Compose in the `testing` directory:

`sudo docker-compose up testing/ 