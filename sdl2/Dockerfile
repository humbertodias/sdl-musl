FROM alpine
#FROM muslcc/i686:aarch64-linux-musl
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
#&& ln -sf /usr/local/${ARCH}-linux-musl-${TYPE}/lib/libc.so /lib/ld-musl-i386.so.1
ENV PATH="/usr/local/${ARCH}-linux-musl-${TYPE}/bin:$PATH"


# allegro 5 - gcc a5.c -o a5 `pkg-config --cflags --libs --static allegro_monolith-static-5`
ARG ALLEGRO5_VERSION=5.2.8.0
RUN mkdir -p /tmp/a5 ; cd /tmp/a5 \
&& git clone https://github.com/liballeg/allegro5 -b ${ALLEGRO5_VERSION} .
RUN cd /tmp/a5 \
&& cmake -DCMAKE_C_FLAGS="-static -Os" -DCMAKE_C_COMPILER=gcc -DCMAKE_CXX_COMPILER=g++ -DCMAKE_BUILD_TYPE=Debug \
-DSHARED=OFF \
-DWANT_X11=OFF -DWANT_PRIMITIVES=OFF \
-DWANT_DOCS=OFF -DWANT_DOCS_HTML=OFF -DWANT_DOCS_MAN=OFF \
-DWANT_EXAMPLES=OFF -DWANT_DEMO=OFF -DWANT_TESTS=OFF \
&& make -j`nproc` && make install

# RUN cd /tmp/a5 \
# && cmake -DCMAKE_C_FLAGS="-static -Os" -DCMAKE_C_COMPILER=gcc -DCMAKE_CXX_COMPILER=g++ -DCMAKE_BUILD_TYPE=Release \
# -DSHARED=OFF \
# -DWANT_X11=OFF -DWANT_X11_XF86VIDMODE=OFF -DWANT_X11_XINERAMA=OFF -DWANT_X11_XRANDR=OFF -DWANT_X11_XSCREENSAVER=OFF \
# -DWANT_D3D=OFF -DWANT_D3D9EX=OFF -DWANT_OPENGL=OFF -DWANT_SHADERS_GL=OFF -DWANT_SHADERS_D3D=OFF \
# -DWANT_DOCS=OFF -DWANT_DOCS_HTML=OFF -DWANT_DOCS_MAN=OFF \
# -DWANT_EXAMPLES=OFF -DWANT_DEMO=OFF -DWANT_TESTS=OFF \
# -DWANT_PRIMITIVES=OFF \
# -DWANT_STATIC_RUNTIME=ON -DPREFER_STATIC_DEPS=ON -DWANT_MONOLITH=ON . \
# && make -j`nproc` && make install

ENV LD_LIBRARY_PATH="/usr/local/${ARCH}-linux-musl-${TYPE}/lib:/usr/local/lib"
