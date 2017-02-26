#ifndef _TREE_H
#define _TREE_H

#include <iostream>
#include "node.h"

class Tree
{
private:
	friend class node;
	friend std::ostream& operator<<(std::ostream& os, const Tree& t);
	node* p;

public:
	Tree(int n);
	Tree(char id);
	Tree(char* op, Tree t);
	Tree(char* op, Tree left, Tree right);
	Tree(const Tree& t);

	~Tree();

	void operator=(const Tree& t);
	int eval();
};

#endif // !_TREE_H