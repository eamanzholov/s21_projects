FROM nginx
WORKDIR /home/
COPY ./nginx.conf /etc/nginx/nginx.conf
COPY ./server.c .
COPY ./run.sh .
RUN apt-get update && apt-get -y upgrade
RUN apt-get install -y gcc spawn-fcgi libfcgi-dev && apt-get clean
ENTRYPOINT ["/bin/sh", "./run.sh"]