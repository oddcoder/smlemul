CC = gcc #compiler
CDEBUGFLAGS = -ggdb3 -Wall -Werror -Wno-unused-variable
#compiler debugging options
CRELEASEFLAGS = -O3
all: main.o sio.o	
	${CC} ${CRELEASEFLAGS} main.o sio.o -o smlemul
main.o: main.c
	${CC} -c  ${CRELEASEFLAGS} main.c
sio.o: sio.c
	 ${CC} -c ${CRELEASEFLAGS} sio.c
debug:
	${CC} ${CDEBUGFLAGS} main.c sio.c -o smlemul
clean:
	rm -rf SML
