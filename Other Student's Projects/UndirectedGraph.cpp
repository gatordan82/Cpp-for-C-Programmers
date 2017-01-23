#include <chrono>
#include <random>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <iterator>
#include "UndirectedGraph.h"

UndirectedGraph::UndirectedGraph(int numNodes, double density, pair<double, double> distRange) {
    //generating nodes
    for (int i = 0; i < numNodes; i++) {
        nodes.push_back(new Node(i));
    }

    unsigned int seed = (unsigned int) chrono::system_clock::now().time_since_epoch().count();
    default_random_engine generator(seed);
    uniform_real_distribution<double> densityDistribution(0.0, 1.0);
    uniform_real_distribution<double> edgeDistDistribution(distRange.first, distRange.second);

    for (int i = 0; i < numNodes - 1; i++) {
        for (int j = i + 1; j < numNodes; j++) {
            if (densityDistribution(generator) < density) {
                edges.push_back(new Edge(nodes.at(i), nodes.at(j), edgeDistDistribution(generator)));
            }
        }
    }
}

UndirectedGraph::UndirectedGraph(std::string &filename) {
    std::ifstream filestream(filename);
//    ifstream filestream;
//    filestream.open ("test.txt");

    std::string line;
    std::getline(filestream, line);
    int nodeCount;
    std::istringstream iss(line);
    iss >> nodeCount;
    for (int i = 0; i < nodeCount; i++) {
        nodes.push_back(new Node(i));
    }
    while (std::getline(filestream, line)) {
        std::istringstream iss(line);
        int i, j, cost;
        if (!(iss >> i >> j >> cost)) { break; }

        edges.push_back(new Edge(nodes.at(i), nodes.at(j), cost));
    }
}

UndirectedGraph::~UndirectedGraph() {
    for (int i = 0; i < edges.size(); ++i)
        delete edges[i];
    edges.clear();

    for (int i = 0; i < nodes.size(); ++i)
        delete nodes[i];
    nodes.clear();
}

bool UndirectedGraph::isAdjacent(int nodeOnePos, int nodeTwoPos) const {
    auto iterator = find_if(edges.begin(), edges.end(), [&nodeOnePos, &nodeTwoPos](Edge *curEdge) -> bool {
        return curEdge->nodes.first->nodeId == min(nodeOnePos, nodeTwoPos) &&
               curEdge->nodes.second->nodeId == max(nodeOnePos, nodeTwoPos);
    });

    return iterator != edges.end();
}

vector<Node *> UndirectedGraph::neighborsAt(int nodePos) const {
    vector<Node *> result;
    for (auto edge : edges) {
        if (edge->contains(nodePos)) {
            result.push_back(edge->oppositeTo(nodePos));
        }
    }

    return result;
}

static bool isAlreadyVisited(vector<Node *> &visited, Node *node) {
    return find_if(visited.begin(), visited.end(), [&node](Node *curNode) -> bool {
        return curNode->nodeId == node->nodeId;
    }) != visited.end();
};

static void addPathCost(Node *start, Node *target, vector<Node *> &visitedNodes) {
    if (start->nodeId == target->nodeId) {
        return;
    }
    visitedNodes.push_back(start);
    vector<Node *> nodesToVisit;
    for (auto edge : start->linkedEdges) {
        if (edge->oppositeTo(start)->shortestPath.first == numeric_limits<double>::max() ||
            edge->oppositeTo(start)->shortestPath.first > start->shortestPath.first + edge->distance) {
            edge->oppositeTo(start)->shortestPath = {start->shortestPath.first + edge->distance, start};
            if (!isAlreadyVisited(visitedNodes, edge->oppositeTo(start))) {
                nodesToVisit.push_back(edge->oppositeTo(start));
            }
        }
    }

    //sorting by distance
    sort(nodesToVisit.begin(), nodesToVisit.end(),
         [](const Node *a, const Node *b) -> bool {
             return a->shortestPath.first < b->shortestPath.first;
         });

    //recursion entry point
    for (auto node : nodesToVisit) {
        addPathCost(node, target, visitedNodes);
    }
}

double UndirectedGraph::findShortestPath(int nodeOne, int nodeTwo) const {
    for_each(nodes.begin(), nodes.end(), [](Node *node) {
        node->shortestPath = {numeric_limits<double>::max(), nullptr};
    });

    Node *start = nodes.at(nodeOne);
    Node *target = nodes.at(nodeTwo);
    start->shortestPath = {0, nullptr};
    vector<Node *> visited;
    addPathCost(start, target, visited);

    return target->shortestPath.first;
}

double UndirectedGraph::findKruskalMST(vector<Edge *> &mst) const {
    double totalCost = 0;
    vector<Edge *> edgesToVisit = this->edges;
    //sorting by cost
    sort(edgesToVisit.begin(), edgesToVisit.end(),
         [](const Edge *a, const Edge *b) -> bool {
             return a->distance < b->distance;
         });

    for (auto edge : edgesToVisit) {
        if (!isConnected(mst, edge->nodes.first, edge->nodes.second)) {
            mst.push_back(edge);
            totalCost += edge->distance;
        }
    }

    return totalCost;
}

bool UndirectedGraph::isConnected(vector<Edge *> &mst, Node* startNode, Node* endNode) const {
    //find mutual elements
    std::vector<Edge *> common;
    std::set_intersection(startNode->linkedEdges.begin(), startNode->linkedEdges.end(), mst.begin(), mst.end(), back_inserter(common));

    for(auto edge : common){
        if(edge->oppositeTo(startNode) == endNode)
            return true;
    }

    for(auto edge : common){
        if(isConnected(mst, edge->oppositeTo(startNode),endNode))
            return true;
    }

    return false;
}