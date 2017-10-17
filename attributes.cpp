// Shaya Wolf
// COSC5785 - Compilers   
// Program 3
// attributes.cpp
// 10/20/2017

#include<string.h>
#include "lex.h"

using namespace std;

void updateAtts(int lNum, int cNum, int leng, string token, string value) {
  atts->lNum = lNum;
  atts->cNum = cNum;
  atts->leng = leng;
  atts->token = token;
  atts->value = value; 
  return;
}

