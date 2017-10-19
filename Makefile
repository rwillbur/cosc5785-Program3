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
YACC=bison
YACCFLAGS=--report=state -W -d

.PHONY: clean

program3: program3.tab.c program3.tab.h program3_lex.cpp program3.cpp attributes.h node.hpp 
	${CXX} ${CXXFLAGS} program3.cpp program3.tab.c program3_lex.cpp attributes.cpp -o program3

program3.tab.c : program3.y node.hpp attributes.h
	${YACC} ${YACCFLAGS} program3.y

program3_lex.cpp: program3.lpp node.hpp
	${LEX} ${LEXFLAGS} program3.lpp

clean: 
	/bin/rm -f *.o a.out core.* program3 program3_lex.cpp program3.tab.*
