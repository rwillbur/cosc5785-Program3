#
# $Author: kbuckner $
# $ID$
#
# $Log: Makefile,v $
# Revision 1.1  2017-10-04 13:20:53-06  kbuckner
# Finally working version
#
#
###############################################################

CXX=g++
CXXFLAGS=-ggdb -std=c++11 -Wall
YACC=bison
YFLAGS=--report=state -W -d
LEX=flex
LEXXX=flex++
LFLAGS=--warn

.PHONY: clean

tester: simple.tab.c simple.tab.h simple_lex.cpp tester.cpp node.hpp
	$(CXX) $(CXXFLAGS) tester.cpp simple.tab.c simple_lex.cpp -o tester

simple.tab.c : simple.y node.hpp
	$(YACC) $(YFLAGS) simple.y

simple_lex.cpp: simple.lpp node.hpp
	$(LEXXX) $(LFLAGS) simple.lpp

tidy:
	/bin/rm -f a.out core.* simple.tab.* simple.output \
	  simple_lex.cpp

clean: tidy
	/bin/rm -f tester 
