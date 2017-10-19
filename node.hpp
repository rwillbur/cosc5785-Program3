// Shaya Wolf
// Program 3
// cosc5785 - Compilers
// 10/20/2017
// Based on node.hpp in Dr.Buckners
//   example on WyoCourses

#ifndef NODE_HPP
#define NODE_HPP

#include<iostream>
#include<string>
#include<vector>

using std::string;
using std::endl;
using std::ostream;
using std::vector;
using std::cout;

// Base Class
class Node 
{
  public:
  // Constructor
  Node() {
    reset();
    ival = 0;
    dval = 0;
  }

  // Destructor
  virtual ~Node() {
    while(!children.empty()) {
      children.pop_back();
    }
  }

  // Get Functions
  int    getint() const { return ival; }

  double getdbl() const { return dval; }

  string getstr() const { return sval; }

  // Set Functions
  void setVal(int i)          { ival = i; }

  void setVal(double d)       { dval = d; }

  void setVal(const string s) { sval = s; }

  void setVal(const char * c) { sval = c; }

  // Reset
  void reset() {
    lnum = 1;
    cnum = 1;
    sval.clear();
  } 
  
  // Get a Child
  Node* getChild(unsigned index) {
    return children[index];
  }

  // Set a Child
  void setChild(Node *c, unsigned index){
    children[index] = c;
    return;
  }
  
  void addChild(Node *c) {
    children.push_back(c);
    return;
  }

  // Print Node
  virtual void printNode(ostream * out = 0) {
    *out << sval;
    for(unsigned i = 0; i < children.size(); i++) {
      children[i]->printNode(out);
    }
    return;
  }

  protected:
    int lnum;
    int cnum;

    int ival;
    double dval;
    string sval;

    vector<Node*> children;
};

// Node Types ////////////////////////////////////////////
class nodeClass : public Node 
{
  public:
    nodeClass() : Node () {
      // set someID
    } 

    virtual void printNode(ostream * out = 0) {
      // Some stuff
    }
  private:
    string someId;
}; 
/////////// inheritence template //////////////////////////////////

// Expression Op Node where t tells us what kind of expression it is
class expNode : public Node 
{
  public:
    expNode(string t) : Node () {
      expType = t;
    } 

    virtual void printNode(ostream * out = 0) {
      if(expType == "relop") {
        cout << "<Expression> -> <Expression>";
        children[1]->printNode();
        cout << "<Expression>";
        cout << endl;
        children[0]->printNode();
        children[2]->printNode();
      }
    }
  private:
    string expType;
}; 

// Relation Op Node where t tells us what kind of operator it is
class relopNode : public Node 
{
  public:
    relopNode(string t) : Node () {
      type = t;
    } 

    virtual void printNode(ostream * out = 0) {
      cout << " " << type << " ";
    }
    
  private:
    string type;
}; 

// Number Node
class numNode : public Node 
{
  public:
    numNode(string n) : Node () {
      num = atoi(n.c_str());
    } 

    virtual void printNode(ostream * out = 0) {
      cout << "<Expression> -> Number (" << num << ")" << endl;
    }
  private:
    int num;
}; 

#endif
