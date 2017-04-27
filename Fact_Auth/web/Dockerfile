FROM ubuntu:latest

RUN apt-get update && apt-get install -y \
    python-pip \
    python3.4 \
    python3-dev \
    build-essential \
    locales \
    python3-pip

RUN locale-gen en_US.UTF-8
RUN update-locale LANG en_US.UTF-8
RUN dpkg-reconfigure locales  
ENV LANG en_US.UTF-8  
ENV LANGUAGE en_US:en
ENV LC_ALL en_US.UTF-8
ENV LC_CTYPE en_US.UTF-8

RUN bash -c  'echo locale' 

ENV PYTHON_PIP_VERSION 9.0.1

RUN pip3 install --upgrade pip

WORKDIR web

RUN pip3 install -r requirements.txt
RUN python3 -m nltk.downloader punkt

EXPOSE 8000
CMD python3 -m swagger_server