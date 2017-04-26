FROM ubuntu:latest

RUN locale-gen en_US.UTF-8  
ENV LANG en_US.UTF-8  
ENV LANGUAGE en_US:en  
ENV LC_ALL en_US.UTF-8 

RUN apt-get update && apt-get install -y \
	git \
	python3-dev \
	python3-pip 

RUN git clone https://github.com/jondef95/5574_final

WORKDIR Fact_Auth
RUN pip3 install --upgrade pip
RUN pip3 install -r requirements.txt
RUN python3 -m nltk.downloader punkt

WORKDIR api-server
RUN python3 -m swagger_server &

WORKDIR ../testing

ENTRYPOINT ["python3"]
CMD ["api_testing.py", "-v"]