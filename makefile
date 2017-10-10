#Program Name: LangAnt Makefile
#Author: Uday Trivedi 
#Date: 7/9/2017
#Description: Makefile for LangtonAnt. This file will compile
#             the objects files into an executable file by
#             default

output: Ant.o Array.o Board.o IntErrorCheck.o Main.o Menu.o 
	g++ -std=c++0x Ant.o Array.o Board.o IntErrorCheck.o Main.o Menu.o \
	-o a.out

Ant.o: Ant.cpp Ant.hpp Board.hpp IntErrorCheck.hpp 
	g++ -std=c++0x -c Ant.cpp Ant.hpp Board.hpp IntErrorCheck.hpp

Array.o: Array.cpp Array.hpp
	g++ -std=c++0x -c Array.cpp Array.hpp

Board.o: Board.cpp Board.hpp
	g++ -std=c++0x -c Board.cpp Board.hpp

Main.o: Main.cpp Menu.hpp
	g++ -std=c++0x -c Main.cpp Menu.hpp

Menu.o: Menu.cpp Menu.hpp  
	g++ -std=c++0x -c Menu.cpp

clean: 
	rm *.o a.out *.gch 
