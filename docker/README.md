# HLS4ML Docker Setup

Please first install docker and the run the following steps

## Create Image

Create hls4ml docker image by running within this directory. 
` docker build -f "<name of image>" .`

This can take a couple minutes.

## Deploy, pause and start, container

1. To start container
` docker run -ti "<name of image>" bash`
2. Navigate to /root directory and you should see the hls4ml directory there.
3. To pause container, ctrl + p, then ctrl + q.
4. To restart container. First list containers, `docker container ls`, Then `docker container start <container id>`
