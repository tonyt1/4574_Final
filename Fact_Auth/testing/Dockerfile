FROM ubuntu:latest

RUN apt-get update && apt-get install -y \
	git \
	python3-dev \
	python3-pip \
	locales

RUN locale-gen en_US.UTF-8

ENV LANG en_US.UTF-8  
ENV LANGUAGE en_US:en  
ENV LC_ALL en_US.UTF-8

COPY . /home/testing
WORKDIR /home/testing

RUN pip3 install --upgrade pip
RUN pip3 install -r requirements.txt
RUN python3 -m nltk.downloader punkt


ENTRYPOINT ["python3"]
CMD ["-u", "api_testing.py", "-v"]