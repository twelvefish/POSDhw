all: hw8

hw8: main.o atom.o struct.o list.o

ifeq (${OS}, Windows_NT)
	g++ -o hw8 main.o atom.o list.o struct.o -lgtest
else
	g++ -o hw8 main.o atom.o list.o struct.o -lgtest -lpthread
endif

atom.o: atom.cpp atom.h variable.h
	g++ -std=gnu++0x -c atom.cpp
list.o:list.cpp list.h
		g++ -std=gnu++0x -c list.cpp
struct.o:struct.cpp struct.h
		g++ -std=gnu++0x -c struct.cpp
#exp: mainExp.o
#	g++ -o exp mainExp.o -lgtest -lpthread
#mainExp.o: mainExp.cpp exp.h global.h
#	g++ -std=gnu++0x -c mainExp.cpp

main.o: main.cpp utExpression.h utException.h 
	g++ -std=gnu++0x -c main.cpp


#utTerm: mainTerm.o term.o struct.o var.o list.o
#	g++ -o utTerm mainTerm.o term.o var.o struct.o list.o -lgtest -lpthread
#mainTerm.o: mainTerm.cpp utTerm.h term.h var.h utStruct.h struct.h list.h utList.h
#	g++ -std=gnu++0x -c mainTerm.cpp
#term.o: term.h term.cpp
#	g++ -std=gnu++0x -c term.cpp
#struct.o: struct.h struct.cpp
#	g++ -std=gnu++0x -c struct.cpp
#var.o: var.h var.cpp
#g++ -std=gnu++0x -c var.cpp
#list.o: list.h list.cpp term.h var.h
#	g++ -std=gnu++0x -c list.cpp
clean:
ifeq (${OS}, Windows_NT)
	del *.o *.exe
else
	rm -f *.o hw8
endif

stat:
	wc *.h *.cpp
