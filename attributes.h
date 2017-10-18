// Shaya Wolf
// COSC5785 - Compilers 
// Program 3
// attributes.h
// 10/20/2017

#ifndef ATTRIBUTES_H
#define ATTRIBUTES_H

#include<iostream>
#include<string.h>

#define COMM 1

#define OR 3

#define PLUS 3
#define MINUS 3

#define BANG 5

#define MULT 4
#define DIVD 4
#define MOD 4
#define AND 4

#define LBRACK 6
#define RBRACK 6
#define LBRACE 6
#define RBRACE 6
#define LPAREN 6
#define RPAREN 6
#define DSLASH 6
#define SEMI 6
#define COMMA 6
#define EQ 6
#define DOT 6

#define IDEN 7
#define NUM 8

#define IF 9
#define INT 9
#define NEW 9
#define VOID 9
#define READ 9
#define ELSE 9
#define THIS 9
#define CLASS 9
#define PRINT 9
#define WHILE 9
#define RETURN 9

#define WSPC 10
#define CHRERR 11
#define WRDERR 12
#define MAXERR 13
#define ERROR 14

using namespace std; 

struct attributes{
  int lNum;
  int cNum;
  int leng;
  string token;
  string value;
};

void updateAtts(int lNum, int cNum, int leng, string token, string value);

#endif
