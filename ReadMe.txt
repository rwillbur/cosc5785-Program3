Shaya Wolf
Program 3 Files
cosc5785 - Compilers
10/17/2017

attributes.cpp 
--> File containing method to update token attributes

attributes.h 
--> Header file for attributes.cpp containing the attributes
    data structure and macros for lex to use

lex.h
--> Header file containing external variable atts

program3.lpp
--> Lex file to read in input from standard in and return 
    tokens for Bison file

program3.y
--> Bison file for parsing and recovering from syntactic errors 

program3.odt
--> Document describing error recovery strategy implemented
    in program3.y 

program3.cpp
--> Main program that calls yyparse/program3.y

Makefile
--> Make and clean functions 
