// RandomShortestPath.cpp
//
// C++ for C Programmers, Part A
// Homework 2: Implement Dijkstra's Algorithm
// 
// Construct two random graphs of 50 vertices, with
// edge density of 20% and 40%
// Find the set of shortest paths to each vertex for both graphs
// and compute the average shortest path length for a given graph
//
// Daniel K. Benjamin
// 1/8/2017


#include <iostream>
#include <vector>
#include <numeric>
#include "DijkstraUndirectedShortestPath.h"

using namespace std;

// calculate the average a vector of values
template <class Summable>
double average(const vector<Summable>& values)
{
	double sum{ accumulate(values.begin(), values.end(), 0.0) };

	return sum / values.size();
}

// Compute the shortest path length from the first vertex
// to every other vertex.  
double averagePathLength(const Graph& g)
{
	vector<double> pathLength{};
	
	DijkstraUndirectedShortestPath dsp{ g, 0 };

	for (int i{ 1 }; i < g.V(); ++i)
	{
		// if a path exists, add the path length to the vector of values
		if (dsp.hasPathTo(i))
			pathLength.push_back(dsp.distTo(i));
	}

	return average(pathLength);
}



int main()
{
	// set the range of distances for random edge weights
	std::array<double, 2> range{ 1.0, 10.0 };

	// fix the number of vertices for both random graphs
	size_t V{ 50 };

	// Construct random graph of 50 vertices, with density ~ 20%
	Graph random20{ V, 0.2, range };
	cout << "Graph of " << V << " vertices, with edge density 20%." << endl;
	cout << "Vertices: " << random20.V() << ", Edges: " << random20.E() << endl;
	cout << "Theoretically - " << 0.2 * V * (V - 1) / 2 << " edges, for density 20%" << endl;
	cout << "Average Shortest Path Length: " << averagePathLength(random20) << "\n\n";

	// Construct random graph of 50 vertices, with density ~ 40%
	Graph random40{ V, 0.4, range };
	cout << "Graph of " << V << " vertices, with edge density 40%." << endl;
	cout << "Vertices: " << random40.V() << ", Edges: " << random40.E() << endl;
	cout << "Theoretically - " << 0.4 * V * (V - 1) / 2 << " edges, for density 40%" << endl;
	cout << "Average Shortest Path Length: " << averagePathLength(random40) << "\n\n";

	// Visual Studio trick to keep the console window open
	cin.get();
	cin.get();

	return 0;
}