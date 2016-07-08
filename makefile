CFLAGS=-Wall
LIBS=-lcheck -lm -lpthread -lrt

all: romanNumber

romanNumber: RomanMain.o implementation.o
	gcc -o romanNumber RomanMain.o implementation.o

RomanMain.o: RomanMain.c implementation.h
	gcc $(CFLAGS) -c RomanMain.c

implementation.o: implementation.c implementation.h
	gcc $(CFLAGS) -c implementation.c


test: romanNumber-test
	./romanNumber-test

romanNumber-test: implementation-test.o implementation.o
	gcc -o romanNumber-test implementation.o implementation-test.o $(LIBS)

implementation-test.o: implementation-test.c implementation.h
	gcc $(CFLAGS) -c implementation-test.c

implementation-test.c: implementation-test.check

	checkmk implementation-test.check >implementation-test.c


clean:
	rm *.o romanNumber romanNumber-test implementation-test.c