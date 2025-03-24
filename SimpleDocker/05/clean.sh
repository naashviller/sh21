#!/bin/bash

sudo docker stop tmp
sudo docker rm tmp
sudo docker rmi -f miniserver:new
sudo docker rmi -f nginx