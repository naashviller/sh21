#!/bin/bash
export DOCKER_CONTENT_TRUST=1
sudo docker build -t miniserver:new ../
sudo docker images
sudo docker run -d -p 80:81 --name tmp miniserver:new

sudo dockle miniserver:new
