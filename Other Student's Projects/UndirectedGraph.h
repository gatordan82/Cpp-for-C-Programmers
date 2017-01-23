#ifndef UNORIENTEDGRAPH_H
#define UNORIENTEDGRAPH_H

#include <vector>

using namespace std;

//additional structures are represent nodes and edges of graph
struct Edge;
struct Node;

class UndirectedGraph {
public:
    UndirectedGraph(std::string &filename);

    UndirectedGraph(int numNodes, double density, pair<double, double> distRange);

    ~UndirectedGraph();

    bool isAdjacent(int nodeOnePos, int nodeTwoPos) const;

    vector<Node *> neighborsAt(int nodePos) const;

    double findShortestPath(int nodeOne, int nodeTwo) const;

    double findKruskalMST(vector<Edge *> &) const;

    inline int verticesCount() const {
        return (int) nodes.size();
    }

    inline int edgesCount() const {
        return (int) edges.size();
    }

private:
    vector<Node *> nodes;
    vector<Edge *> edges;

    bool isConnected(vector<Edge *>&, Node*, Node*) const;
};

struct Node {
    Node(int id) : nodeId(id) {}

    vector<Edge *> linkedEdges;
    pair<double, Node *> shortestPath;          //pair<overall distance, connected throu>
    const int nodeId;
};

struct Edge {
    Edge(Node *nodeOne, Node *nodeTwo, double distance) :
            nodes(nodeOne, nodeTwo),
            distance(distance) {
        Edge *self = this;
        nodeOne->linkedEdges.push_back(self);
        nodeTwo->linkedEdges.push_back(self);
    }

    Node *oppositeTo(Node *node) {
        return oppositeTo(node->nodeId);
    }

    Node *oppositeTo(int nodeId) {
        if (nodes.first->nodeId == nodeId)
            return nodes.second;
        else if (nodes.second->nodeId == nodeId)
            return nodes.first;
        else
            throw "Illegal argument";
    };

    bool contains(int nodeId) const {
        return nodes.first->nodeId == nodeId || nodes.second->nodeId == nodeId;
    }

    pair<Node *, Node *> nodes;
    double distance;
};

#endif //UNORIENTEDGRAPH_H
