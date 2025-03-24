#!/bin/bash

sudo docker pull nginx
sudo docker run -d -p 81:81 --name tmp nginx
sudo docker exec tmp apt-get update
sudo docker exec tmp apt-get install -y gcc spawn-fcgi libfcgi-dev
sudo docker cp ../server/server.c tmp:etc/nginx/
sudo docker cp ../server/nginx/nginx.conf tmp:/etc/nginx/
sudo docker exec tmp gcc /etc/nginx/server.c -o /etc/nginx/miniserver -lfcgi
sudo docker exec tmp spawn-fcgi -a 127.0.0.1 -p 8080 /etc/nginx/miniserver
sudo docker exec tmp nginx -s reload