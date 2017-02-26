#ifndef _BINARY_NODE_H
#define _BINARY_NODE_H


#include "node.h"


class BinaryNode :
	public node
{
private:
	friend class Tree;
	char* op;
	Tree left;
	Tree right;

	BinaryNode(char* a, Tree b, Tree c);
	void print(std::ostream& os);

public:
	~BinaryNode();

	int eval();
};

#endif // !_BINARY_NODE_H