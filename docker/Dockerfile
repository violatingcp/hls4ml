FROM python:2.7 

RUN apt-get update

RUN apt-get install -y \ 
    git \
    python-pip \
    wget \
    vim \
    && \
    rm -rf /var/lib/apt/lists/*

RUN cd /root \
    && git clone https://github.com/violatingcp/hls4ml.git \ 
    && cd /root/hls4ml \
    && git checkout sc20_test \
    && pip install -e .

