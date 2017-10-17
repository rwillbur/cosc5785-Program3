##
# Shaya Wolf
# Makefile
# Compilers - Program3
# 10/20/2017
##

CXX=g++
CXXFLAGS=-std=c++11 -ggdb -Wall
LEX=flex++
LEXFLAGS=--warn

.PHONY: clean

program3: program3.cpp program3_lex.cpp attributes.h 
	${CXX} ${CXXFLAGS} -o program3 program3.cpp program3_lex.cpp attributes.cpp

program3_lex.cpp: program3.lpp lex.h 
	${LEX} ${LEXFLAGS} program3.lpp

clean: 
	/bin/rm -f *.o a.out core.* program3 program3_lex.cpp
