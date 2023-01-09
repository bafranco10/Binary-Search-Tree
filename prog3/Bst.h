// FILE: Rbt.h
// Brian Franco, Transy U
// CS 2444, Fall 2021
//
// interface Red Black tree 
//
#ifndef		RBT_H
#define		RBT_H

#include <iostream>
#include "DataType.h"
using namespace std; 

class Bst {
//public member functions
public: 
	// constructor and destructor
	Rbt (void);
	~Rbt (void);
	// mutator
	bool put (const ValueType& newItem);
	// accessors
	bool get (const KeyType& searchKey, ValueType& foundItem) const;
	void printDEBUG (void) const;
private: 
	// private structure 
	struct Node {
		ValueType 	data; 
		Node	*left;
		Node	*right; 
		bool isRed; 
	};
	// private recursive functions
	// private mutator 
	bool put (Node*&root, const ValueType&newItem); 
	// private accessors
	void printNode (Node *treeRoot) const; 
	bool preOrder (Node *treeRoot) const; 
	bool get (Node*root, const KeyType& searchKey,ValueType& foundItem) const; 
	bool postOrder (Node *root) const; 

	// private variables 
	Node *treeRoot; 
};
#endif 
