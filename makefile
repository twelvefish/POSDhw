INC_DIR = include

all: hw8

hw8: main.o
ifeq (${OS}, Windows_NT)
	g++ -o hw8 main.o -lgtest
else
	g++ -o hw8 main.o -lgtest -lpthread
endif
	
main.o: main.cpp exception.h expression.h atom.h number.h variable.h struct.h list.h scanner.h
	g++ -std=gnu++0x -c main.cpp

clean:	
ifeq (${OS}, Windows_NT)
	del *.o *.exe
else
	rm -f *.o hw8
endif