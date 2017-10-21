Shaya Wolf
Program 3 Files
cosc5785 - Compilers
10/17/2017

Some Notes:
  I didn't change much of the grammar. This was mostly an act of 
  selfishness. We basically got two reduce/reduce errors from the
  rules as they stand without implementing the whole language. It
  was easier just to add a "[]" to the lpp file to get rid of the
  first reduce error, and to do the first rule in the statement
  production to get rid of the other. This meant no changes to the
  lanugage, less backtracking when we start program 4, and being
  able to implement the full simpleType production in this iteration
  of the compiler construction. That being said, sorry it's going 
  to be a pain to test. I included the test file I used just in case
  this is at all helpful. I know it said not to print leafs in
  the instructions, but I printed them in parentheses so that I 
  could tell what the tree was doing. 

attributes.cpp 
--> File containing method to update token attributes

attributes.h 
--> Header file for attributes.cpp containing the attributes
    data structure and macros for lex to use

grammar.txt
--> Grammar implemented in this iteration 

grammarTest.txt
--> Test file that *should* completely test the grammar

Makefile
--> Make and clean functions

node.hpp
--> Node class that uses a base class to implement different
    type of nodes with specific print functions. Might expand
    later to one node per terminal.

program3.cpp
--> Main program that calls yyparse and prints the parse tree

program3.lpp
--> Lex file to read in input from standard in and return 
    tokens for Bison file. This does not pass white space/comments
    to Bison but does print lexical word/char errors to std::out.

program3.odt
--> Document describing error recovery strategy implemented
    in program3.y 
    
program3.y
--> Bison file for parsing and recovering from syntactic errors 


