INC_DIR = include

all: hw2

hw2: mainHw2.o atom.o Number.o variable.o
ifeq (${OS}, Windows_NT)
	g++ -o hw2 mainHw2.o atom.o Number.o variable.o -lgtest
else
	g++ -o hw2 mainHw2.o atom.o Number.o variable.o -lgtest -lpthread
endif
	
mainHw2.o: mainHw2.cpp utTerm.h
	g++ -std=gnu++0x -c mainHw2.cpp
atom.o: atom.cpp atom.h
	g++ -std=gnu++0x -c atom.cpp

Number.o: Number.cpp Number.h
	g++ -std=gnu++0x -c Number.cpp

variable.o: variable.cpp variable.h
	g++ -std=gnu++0x -c variable.cpp

clean:	
ifeq (${OS}, Windows_NT)
	del *.o *.exe
else
	rm -f *.o hw2
endif