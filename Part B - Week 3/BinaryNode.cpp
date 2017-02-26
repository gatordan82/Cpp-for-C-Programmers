#include "BinaryNode.h"



BinaryNode::BinaryNode(char* a, Tree b, Tree c)
	: op{ a },
	left{ b },
	right{ c }
{
}

void BinaryNode::print(std::ostream& os)
{
	os << "(" << left << op << right << ")";
}


BinaryNode::~BinaryNode()
{
}

int BinaryNode::eval()
{
	switch (op[0])
	{
	case '-':
		return (left.eval() - right.eval());
	case '+':
		return (left.eval() + right.eval());
	case '*':
		return (left.eval() * right.eval());
	default:
		std::cerr << "no operand\n" << std::endl;
		return 0;
	}
}
