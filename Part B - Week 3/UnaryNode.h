#ifndef _UNARY_NODE_H
#define _UNARY_NODE_H

#include "node.h"


class UnaryNode :
	public node
{
private:
	friend class Tree;
	char* op;
	Tree opnd;

	UnaryNode(char* a, Tree b);
	void print(std::ostream& os);

public:
	~UnaryNode();

	int eval();
};


#endif // !_UNARY_NODE_H