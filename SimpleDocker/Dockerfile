FROM nginx

COPY server/server.c /
COPY server/nginx/nginx.conf /etc/nginx
COPY server.sh /

RUN apt-get update && \
    apt-get install -y gcc && \
    apt-get install -y spawn-fcgi && \
    apt-get install -y libfcgi-dev && \
    rm -rf /var/lib/apt/lists && \
    gcc ./server.c -o miniserver -lfcgi && \
    chmod +x server.sh; \
    chown -R nginx:nginx /etc/nginx/nginx.conf; \
    chown -R nginx:nginx /var/cache/nginx; \
    chown -R nginx:nginx /home; \
    touch /var/run/nginx.pid; \
    chown -R nginx:nginx /var/run/nginx.pid; \
    chmod u-s /usr/bin/gpasswd; \
    chmod u-s /usr/bin/newgrp; \
    chmod u-s /bin/su; \
    chmod u-s /bin/mount; \
    chmod u-s /bin/umount; \
    chmod u-s /usr/bin/chsh; \
    chmod u-s /usr/bin/chfn; \
    chmod u-s /usr/bin/chsh; \
    chmod 255 /usr/bin/expiry; \
    chmod 255 /usr/bin/wall; \
    chmod 255 /sbin/unix_chkpwd; \
    chmod 255 /usr/bin/chage; \
    chmod 755 /usr/bin/passwd

USER nginx
HEALTHCHECK --interval=5m --timeout=3s CMD curl -f http://localhost:80/ || exit 1
ENTRYPOINT [ "./server.sh" ]

