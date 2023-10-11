.PHONY: shell-sdl1, shell-sdl2

#ARCH=$(shell uname -m)
ARCH=i686
ARCH=aarch64
TYPE=native
DOCKERFILE=Dockerfile

archs:
	curl https://musl.cc

shell-sdl1:	build-sdl1
	docker run -it --rm -v ${PWD}/sdl1:/workdir \
	-w /workdir \
	-u `id -u`:`id -g` \
	-e CC=gcc \
	-e CXX=g++ \
	sdl1:${TYPE}-${ARCH} \
	bash

shell-sdl2:	build-sdl2
	docker run -it --rm -v ${PWD}/sdl2:/workdir \
	-w /workdir \
	-u `id -u`:`id -g` \
	-e CC=gcc \
	-e CXX=g++ \
	sdl2:${TYPE}-${ARCH} \
	bash

build-sdl1:
	cd sdl1 && docker build . \
	--build-arg ARCH=${ARCH} \
	--build-arg TYPE=${TYPE} \
	-f ${DOCKERFILE} \
	-t sdl1:${TYPE}-${ARCH}

build-sdl2:
	cd sdl2 && docker build . \
	--build-arg ARCH=${ARCH} \
	--build-arg TYPE=${TYPE} \
	-f ${DOCKERFILE} \
	-t sdl2:${TYPE}-${ARCH}
