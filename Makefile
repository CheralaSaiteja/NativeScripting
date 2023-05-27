# make flags
MAKEFLAGS = --no-print-directory

# flags
CC = g++
OFLAGS = -c
FLAGS = -fPIC -g -ggdb
SHARED_FLAGS = -rdynamic -shared

OBJ_DIR = obj
SHARED_DIR = bin

%.o: %.cpp
	@${CC} ${FLAGS} ${OFLAGS} -o ${OBJ_DIR}/$@ $<

libmain.so: lib.o
	@${CC} ${FLAGS} ${SHARED_FLAGS} ${OBJ_DIR}/lib.o -o ${SHARED_DIR}/libmain.so
	@nm -gD ${SHARED_DIR}/libmain.so | grep " T " > ${SHARED_DIR}/libmain.txt

main: main.o
	@${CC} ${OBJ_DIR}/main.o -o main

build: libmain.so main

rebuild:
	@rm -rf ${OBJ_DIR}/*.o *.so
	@make build
