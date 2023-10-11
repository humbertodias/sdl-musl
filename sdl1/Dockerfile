FROM alpine

RUN apk update && apk add git cmake make pkgconfig file nano zip unzip bash

# bash as default
SHELL ["/bin/bash", "-c"]

# Musl
ARG ARCH=aarch64
#ARG ARCH=i686
#ARG ARCH=x86_64
ARG TYPE=native

RUN cd /tmp ; wget https://musl.cc/${ARCH}-linux-musl-${TYPE}.tgz \
&& cd /usr/local ; tar -zxf /tmp/${ARCH}-linux-musl-${TYPE}.tgz \
&& ln -sf /usr/local/${ARCH}-linux-musl-${TYPE}/lib/libc.so /usr/local/${ARCH}-linux-musl-${TYPE}/bin/ldd \
&& ln -sf /usr/local/${ARCH}-linux-musl-${TYPE}/lib/libc.so /lib/ld-musl-${ARCH}.so.1
#&& ln -sf /usr/local/${ARCH}-linux-musl-${TYPE}/lib/libc.so /lib/ld-musl-i386.so.1 \
ENV PATH="/usr/local/${ARCH}-linux-musl-${TYPE}/bin:$PATH"

# allegro 4 - gcc a4.c -o a4 --static `pkg-config --libs --cflags --static allegro`
ARG ALLEGRO4_VERSION=4.4.3.1
RUN mkdir /tmp/a4 && cd /tmp/a4 \
&& git clone https://github.com/liballeg/allegro5 -b ${ALLEGRO4_VERSION} . \
&& cmake -DCMAKE_C_FLAGS="-static -Os" -DCMAKE_C_COMPILER=gcc -DCMAKE_CXX_COMPILER=g++ -DSHARED=OFF -DWANT_EXAMPLES=OFF -DWANT_TESTS=OFF -DCMAKE_BUILD_TYPE=Debug . \
&& make -j`nproc` && make install \
&& cmake -DCMAKE_C_FLAGS="-static -Os" -DCMAKE_C_COMPILER=gcc -DCMAKE_CXX_COMPILER=g++ -DSHARED=OFF -DWANT_EXAMPLES=OFF -DWANT_TESTS=OFF -DCMAKE_BUILD_TYPE=Release . \
&& make -j`nproc` && make install

ENV LD_LIBRARY_PATH="/usr/local/${ARCH}-linux-musl-${TYPE}/lib:/usr/local/lib"
