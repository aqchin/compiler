/* File: ast.cc
 * ------------
 */

#include "ast.h"
#include "ast_type.h"
#include "ast_decl.h"
#include <string.h> // strdup
#include <stdio.h>  // printf

//List<Symbol*> *Node::st_list = new List<Symbol*>();
SymTab *Node::symtab = new SymTab();
IRGenerator *Node::irgen = new IRGenerator();
List<llvm::BasicBlock*> *Node::brstk = new List<llvm::BasicBlock*>();
List<llvm::BasicBlock*> *Node::contstk = new List<llvm::BasicBlock*>();

Node::Node(yyltype loc) {
    location = new yyltype(loc);
    parent = NULL;
}

Node::Node() {
    location = NULL;
    parent = NULL;
}

/* The Print method is used to print the parse tree nodes.
 * If this node has a location (most nodes do, but some do not), it
 * will first print the line number to help you match the parse tree 
 * back to the source text. It then indents the proper number of levels 
 * and prints the "print name" of the node. It then will invoke the
 * virtual function PrintChildren which is expected to print the
 * internals of the node (itself & children) as appropriate.
 */
void Node::Print(int indentLevel, const char *label) { 
    const int numSpaces = 3;
    printf("\n");
    if (GetLocation()) 
        printf("%*d", numSpaces, GetLocation()->first_line);
    else 
        printf("%*s", numSpaces, "");
    printf("%*s%s%s: ", indentLevel*numSpaces, "", 
           label? label : "", GetPrintNameForNode());
   PrintChildren(indentLevel);
} 
	 
Identifier::Identifier(yyltype loc, const char *n) : Node(loc) {
    name = strdup(n);
} 

void Identifier::PrintChildren(int indentLevel) {
    printf("%s", name);
}

void Symbol::insert(char* c, llvm::Value* n) {
  string str(c);
  if(exists(c)) {
    st_map.at(str) = n;
  }
  else st_map.insert(pair<string, llvm::Value*>(str, n));
}

llvm::Value* Symbol::lookup(char* c) const {
  if(exists(c)) {
    string str(c);
    return st_map.at(str);
  }
  return NULL;
}

bool Symbol::exists(char* c) const {
  string str(c);
  return (st_map.count(str) > 0);
}
