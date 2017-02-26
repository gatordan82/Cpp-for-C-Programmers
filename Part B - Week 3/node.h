#ifndef _NODE_H
#define _NODE_H

#include <iostream>
#include "Tree.h"

class node
{
private:
	friend class Tree;
	friend std::ostream& operator<<(std::ostream& os, const Tree& t);
	int use;

protected:
	node();

	virtual ~node();

	virtual void print(std::ostream& os) = 0;
	virtual int eval() = 0;
};

#endif // !_NODE_H