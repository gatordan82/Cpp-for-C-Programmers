#ifndef _ID_NODE_H
#define _ID_NODE_H


#include "LeafNode.h"
#include <unordered_map>

static std::unordered_map<char, int> valtab;

class IdNode :
	public LeafNode
{
private:
	friend class Tree;
	char name;
	void print(std::ostream& os);


public:
	IdNode(char id);

	~IdNode();

	int eval();


};

#endif // !_ID_NODE_H