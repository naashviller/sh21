#!/bin/bash

service nginx start
spawn-fcgi -p 8080 ./miniserver
nginx -s reload
tail -f /dev/null

