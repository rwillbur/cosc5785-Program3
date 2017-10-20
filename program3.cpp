// Shaya Wolf
// COSC5785 - Compilers   
// Program 3
// program3.cpp
// 10/20/2017

#include<FlexLexer.h>

#include<stdio.h>
#include<iostream>
#include<fstream>
#include<string.h>
#include<iomanip>

#include "attributes.h"
#include "node.hpp"
#include "program3.tab.h"

using namespace std;

attributes *atts;
yyFlexLexer myScanner;
vector<Node*> forest;

int main() { 
  // Initialize Attributes Struct
  atts = new attributes{0,0,0,""};
    
  // Make call for Bison
  yyparse();
  
  // Print the Parse Tree
  for(unsigned int i = 0; i < forest.size(); i++) {
    forest[i]->printNode();
    delete forest[i];
  }

  delete atts;
  return 0 ;
}
