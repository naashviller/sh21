#!/bin/bash

sudo docker build -t miniserver:new ../
sudo docker run -d -p 80:81 --name tmp miniserver:new
