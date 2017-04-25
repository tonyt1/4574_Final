FROM ubuntu:latest
RUN apt-get update && apt-get install -y \
    python3-pip \
    python3.4

RUN pip3 install --upgrade pip
RUN apt-get install -y python-pip python-dev build-essential 

RUN pip3 install Flask-API
RUN pip install  Flask-API
RUN pip3 install flask
RUN pip3 install flask-httpauth
RUN pip3 install requests

RUN apt-get install -y mongodb
RUN pip install pymongo

COPY . /web
WORKDIR /web
RUN pip3 install -r requirements.txt

EXPOSE 8000
CMD python3 -m swagger_server