#ifndef _INT_NODE_H
#define _INT_NODE_H

#include "LeafNode.h"



class IntNode :
	public LeafNode
{
private:
	friend class Tree;
	int n;

	void print(std::ostream& os);

public:
	IntNode(int k);

	~IntNode();

	int eval();
};


#endif // !_INT_NODE_H