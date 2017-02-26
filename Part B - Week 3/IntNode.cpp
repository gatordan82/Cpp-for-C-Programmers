#include "IntNode.h"



void IntNode::print(std::ostream& os)
{
	os << n;
}


IntNode::IntNode(int k)
	: n{ k }
{
}


IntNode::~IntNode()
{
}

int IntNode::eval()
{
	return n;
}
