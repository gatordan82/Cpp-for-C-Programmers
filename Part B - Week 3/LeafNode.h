#ifndef _LEAF_NODE_H
#define _LEAF_NODE_H

#include "node.h"
#include <iostream>

class LeafNode :
	public node
{
private:
	friend class Tree;
	void print(std::ostream& os) = 0;
	virtual int eval() = 0;

public:
	virtual ~LeafNode();
};


#endif // !_LEAF_NODE_H