#include "IdNode.h"



void IdNode::print(std::ostream& os)
{
	os << name;
}

IdNode::IdNode(char id)
	: name{ id }
{
}


IdNode::~IdNode()
{
}

int IdNode::eval()
{
	return valtab[name];
}
