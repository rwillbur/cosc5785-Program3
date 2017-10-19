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
    if(c != 0) {
      children.push_back(c);
    }
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
    nodeClass(string t) : Node () {
      type = t;
    } 

    virtual void printNode(ostream * out = 0) {
      // Some stuff
    }
  private:
    string type;
}; 
/////////// inheritence template //////////////////////////////////

// Statement Node ... for now just a simple statement
class statementNode : public Node 
{
  public:
    statementNode() : Node () {
      type = "";
    } 

    virtual void printNode(ostream * out = 0) {
      cout << "<Statement> -> <Name> = <Expression> semi" << endl;
      children[0]->printNode();
      children[1]->printNode();
    }
  private:
    string type;
};

// Type node where t defines either a simpleType or a 
// recursive type [] 
class typeNode : public Node 
{
  public:
    typeNode(string t) : Node () {
      type = t;
    } 

    virtual void printNode(ostream * out = 0) {
      cout << "<Type> -> ";
      if(type == "simpleType") {
        cout << "<SimpleType>" << endl;
        children[0]->printNode();
      } else if (type == "type") {
        cout << "<Type> []" << endl;
        children[0]->printNode();
      } else {
        cout << "This was unexpected" << endl;
      }
    }
  private:
    string type;
}; 

// VarDec Node which just needs to print <VarDec>
class varDecNode : public Node 
{
  public:
    varDecNode(string i) : Node () {
      identifier = i;
    } 

    virtual void printNode(ostream * out = 0) {
      cout << "<VarDeclaration> -> <Type> identifier (" << identifier << ") semi" << endl;
      children[0]->printNode();
    }
  private:
    string identifier;
}; 

// SimpleType Node which right now is just int
class simpleTypeNode : public Node 
{
  public:
    simpleTypeNode(string t, string i) : Node () {
      type = t;
      id = i;
    } 

    virtual void printNode(ostream * out = 0) {
      if(type == "int") {
        cout << "<SimpleType> -> " << type << endl; 
      } else if (type == "id") {
        cout << "<SimpleType> -> identifier (" << id << ")" << endl;
      } else {
        cout << "This is bad" << endl;
      }
    }
  private:
    string type;
    string id;
}; 

// Name Node
class nameNode : public Node 
{
  public:
    nameNode(string t, string i) : Node () {
      type = t;
      id = i;
    } 

    virtual void printNode(ostream * out = 0) {
      cout << "<Name> -> ";
      if(type == "this") {
        cout << "this" << endl;
      } else if (type == "id") {
        cout << "identifier (" << id << ")" << endl;
      } else if (type == "dotid") {
        cout << "<Name> . identifier (" << id << ")" << endl;
        children[0]->printNode();
      } else if (type == "exp") {
        cout << "<Name> [ <Expression> ]" << endl;
        children[0]->printNode();
        children[1]->printNode();
      } else {
        cout << "Bad news bears" << endl;
      }
    }
  private:
    string type;
    string id;
}; 

// Expression Op Node where t tells us what kind of expression it is
class expNode : public Node 
{
  public:
    expNode(string t) : Node () {
      expType = t;
    } 

    virtual void printNode(ostream * out = 0) {
      if(expType == "relop" || expType == "sumop"
           || expType == "proop") {
        cout << "<Expression> -> <Expression>";
        children[1]->printNode();
        cout << "<Expression>";
        cout << endl;
        children[0]->printNode();
        children[2]->printNode();
      } else if (expType == "unyop") {
        cout << "<Expression> -> ";
        children[0]->printNode();
        cout << " <Expression>";
        cout << endl;
        children[1]->printNode();
      } else if (expType == "name") {
        cout << "<Exression> -> <Name>" << endl;
        children[0]->printNode();
      } else if (expType == "newexp") {
        cout << "<Expression> -> <NewExpression>" << endl;
        children[0]->printNode();
      } else {
        cout << "Something really bad happened :'(" << endl;
      }
    }
  private:
    string expType;
}; 

// NewExpression node 
class newexpNode : public Node 
{
  public:
    newexpNode(string t, string i) : Node () {
      type = t;
      id = i;
    } 

    virtual void printNode(ostream * out = 0) {
      if(type == "parens") {
        cout << "<NewExpression> -> new identifier (" << id << ") ()" << endl;
      } else if (type == "bracks") {
        cout << "<NewExpression> -> new identifier (" << id << ") ";
        /*for (unsigned int i = 0; i < children.size(); i++) {
          cout << "[FIX]";
        }
        cout << endl;*/
        for (unsigned int i = 0; i < children.size(); i++) {
        //if(children.size() > 0){
          children[i]->printNode();
        }
        cout << endl;
      } else {
        cout << "oh my god holy hell what is happening with my liiiiife" << endl;
      }
    }
  private:
    string type;
    string id;
}; 

// expstar node because fancy feast
class expstarNode : public Node 
{
  public:
    expstarNode() : Node () {
      type = "";
    } 

    virtual void printNode(ostream * out = 0) {
      cout << "[Expression] ";
      if(children.size() > 0) {
        children[0]->printNode();
      }
    }
  private:
    string type;
}; 

// brackstar node because fancy feast
class brackstarNode : public Node 
{
  public:
    brackstarNode() : Node () {
      type = "";
    } 

    virtual void printNode(ostream * out = 0) {
      cout << "[] ";
      if(children.size() > 0) {
        children[0]->printNode();
      }
    }
  private:
    string type;
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

// Sum Op Node where t tells us what kind of operator it is
class sumopNode : public Node 
{
  public:
    sumopNode(string t) : Node () {
      type = t;
    } 

    virtual void printNode(ostream * out = 0) {
      cout << " " << type << " ";
    }
    
  private:
    string type;
};

// Product Op Node where t tells us what kind of operator it is
class proopNode : public Node 
{
  public:
    proopNode(string t) : Node () {
      type = t;
    } 

    virtual void printNode(ostream * out = 0) {
      cout << " " << type << " ";
    }
    
  private:
    string type;
};

// Unary Op Node where t tells us what kind of operator it is
class unyopNode : public Node 
{
  public:
    unyopNode(string t) : Node () {
      type = t;
    } 

    virtual void printNode(ostream * out = 0) {
      cout << type;
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
