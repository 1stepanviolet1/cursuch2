PROJECT = cw

CORE = src/
HEADERS = ./headers/
TMP = .tmp/
BIN = bin/

CC = g++
CPPFLAGS = -I${HEADERS} -std=c++17

SRC_CORE = $(wildcard ${CORE}*.cpp)

SRC_OBJ = $(patsubst ${CORE}%.cpp, ${TMP}%.o, ${SRC_CORE})

OBJECTS = ${SRC_OBJ} ${TMP}main.o


all: setup ${PROJECT} clean


setup:
	mkdir ${TMP}

${PROJECT}: ${OBJECTS}
	${CC} ${CPPFLAGS} $^ -o ${BIN}$@

${TMP}%.o: %.cpp
	${CC} ${CPPFLAGS} -c $< -o $@

${TMP}%.o: ${CORE}%.cpp
	${CC} ${CPPFLAGS} -c $< -o $@


clean:
	rm -rf ${TMP}
