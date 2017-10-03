INC_DIR = include

all: hw2

hw2: mainHw2.o atom.o Number.o var.o
ifeq (${OS}, Windows_NT)
	g++ -o hw2 mainHw2.o atom.o Number.o var.o -lgtest
else
	g++ -o hw2 mainHw2.o atom.o Number.o var.o -lgtest -lpthread
endif
	
mainHw2.o: mainHw2.cpp utTerm.h
	g++ -std=gnu++0x -c mainHw2.cpp
atom.o: atom.cpp atom.h
	g++ -std=gnu++0x -c atom.cpp

Number.o: Number.cpp Number.h
	g++ -std=gnu++0x -c Number.cpp

var.o: var.cpp var.h
	g++ -std=gnu++0x -c var.cpp

clean:	
ifeq (${OS}, Windows_NT)
	del *.o *.exe
else
	rm -f *.o hw2
endif