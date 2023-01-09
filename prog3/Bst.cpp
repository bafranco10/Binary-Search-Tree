// FILE: Bst.cpp
// Brian Franco, Transy U
// CS 2444, Fall 2021
//
// implementation Binary Search Tree
//
#include "Bst.h"
// constructor,destructor
Bst::Bst (void) {
	treeRoot = 0; 
 }
Bst::~Bst (void) { 
postOrder (treeRoot); 
}
//
// mutator
// calls private overload function
bool Bst::put (const ValueType& newItem) {
	return put (treeRoot, newItem); 
}
// private overload recursive function 
// put calls itself and recursively inserts new nodes
bool Bst::put (Node*&root, const ValueType& newItem) {
	// base case
	if (root == 0) {
		root = new Node; 
		root -> data = newItem;
		root -> right = 0;
		root -> left = 0;
		return true; 
	}
	// base case
	if (root -> data == newItem) {
		return false; 
	}
	// decides where to insert new item
	if (newItem < root -> data) {
	return put (root -> left, newItem);
	}
	return put (root -> right, newItem); 
}
// accessors
// gets item in the list
// calls private overload
bool Bst::get (const KeyType& searchKey, ValueType& foundItem) const {
	return get (treeRoot,searchKey,foundItem); 
}
// private overload recursive function 
// get calls itself and recursively gets new nodes
bool Bst::get (Node*root, const KeyType& searchKey, ValueType& foundItem) const {
	// base case
	if (root == 0 ) {
		return false; 
	}
	// base case
	if (root -> data == searchKey) { 
		foundItem = root -> data; 
		return true; 
	}
	// check where to get item from
	if (searchKey < root -> data) {
	return get (root -> left, searchKey, foundItem);
	}
	else  {
	return get (root -> right, searchKey, foundItem); 
	}
}

// print Debug 
void Bst::printDEBUG (void) const {
	// if list is empty say it is empty
	if (treeRoot == 0) {
		cout << endl << " No contents in BST";
	}
	// print list in preorder
	preOrder (treeRoot); 
}
// recursively goes down the list order
// preorder traversal
bool Bst::preOrder (Node *treeRoot) const {
	// if there is nothing then return false
	if (treeRoot == 0) {
		return false; 
	}
	// calls print function so we can see what is called
	printNode(treeRoot);
	// go down the left first
	preOrder (treeRoot -> left);
	// then go down the right 
	preOrder (treeRoot -> right); 
	return true; 
}

#define DB
/// print Node
// display the current contents of a Node
// [includes DB debugging option]
//
void Bst::printNode (Node *treeRoot) const {
#ifndef DB 
	cout << treeRoot -> data << ' '; 
#else 
	cout << endl << "data; " << treeRoot -> data; 
	cout << endl << "\tleft: ";
	if (treeRoot -> left) {
		cout << treeRoot -> left -> data;
	}
	else {
		cout << "[EXTERNAL]";
	}
	cout << endl << "\tright: ";
	if (treeRoot -> right) {
		cout << treeRoot -> right -> data; 
	}
	else {
		cout << "[EXTERNAL]";
	}
	cout << endl; 
	#endif 
}
// post order traversal for destructor where visiting a node deletes it
bool Bst::postOrder (Node *root) const {
	if (root == 0) {
		return false; 
	}
	postOrder (root -> left);
	postOrder (root -> right);
	delete root; 
	return true; 
}