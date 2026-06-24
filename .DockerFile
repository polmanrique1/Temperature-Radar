
FROM ubuntu:22.04

RUN apt-get update && apt-get install -y \
    gcc \
    make \
    && rm -rf /var/lib/apt/lists/*


WORKDIR /app

COPY temperature.c .

RUN gcc -o temperature temperature.c

CMD ["./temperature"]