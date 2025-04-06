PROJECT = cw

CORE = src/
HEADERS = ./headers/
TMP = .tmp/
BIN = bin/

CPPC = g++
CPPFLAGS = -I${HEADERS} -std=c++17

SRC_CORE = $(wildcard ${CORE}*.cpp)

SRC_OBJ = $(patsubst ${CORE}%.cpp, ${TMP}%.o, ${SRC_CORE})

OBJECTS = ${SRC_OBJ} ${TMP}main.o


all: setup ${PROJECT} clean


setup:
	mkdir ${TMP}

${PROJECT}: ${OBJECTS}
	${CPPC} ${CPPFLAGS} $^ -o ${BIN}$@ -lpng -lm

${TMP}%.o: %.cpp
	${CPPC} ${CPPFLAGS} -c $< -o $@

${TMP}%.o: ${CORE}%.cpp
	${CPPC} ${CPPFLAGS} -c $< -o $@


clean:
	rm -rf ${TMP}

run_test:
	g++ test.cpp -o test
	./test
	rm test

