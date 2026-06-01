FROM ubuntu:18.04

RUN apt update && apt install -yy gcc g++ cmake

COPY . /app
WORKDIR /app

RUN rm -rf _build && \
    cmake -H. -B_build -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=_install && \
    cmake --build _build && \
    cmake --build _build --target install

ENV LOG_PATH=/logs/log.txt

VOLUME /logs

WORKDIR /app/_install/bin

CMD ["./demo"]
