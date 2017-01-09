#include "DijkstraUndirectedShortestPath.h"
#include <limits>

using namespace std;

const double infinity{ numeric_limits<double>::infinity() };


DijkstraUndirectedShortestPath::DijkstraUndirectedShortestPath(const Graph& g, vertex source)
	: _distTo{ vector<dist>(g.V(), infinity) },
	_edgeTo{ vector<Edge<dist>>{} },
	_pq{ IndexMinPriorityQueue<dist, vertex>{g.V()} }
{
	_distTo[source] = 0.0;

	_pq.insert(_distTo[source], source);

	while (!_pq.isEmpty())
	{
		vertex v = _pq.removeMin();
		for (const edge& e : g.neighbors(v))
			relax(e, v);
	}
}

DijkstraUndirectedShortestPath::~DijkstraUndirectedShortestPath()
{
}

const DijkstraUndirectedShortestPath::dist& DijkstraUndirectedShortestPath::distTo(const vertex& sink) const
{
	return _distTo[sink];
}

bool DijkstraUndirectedShortestPath::hasPathTo(const vertex& sink) const
{
	return (_distTo[sink] < infinity);
}

const vector<DijkstraUndirectedShortestPath::edge>& DijkstraUndirectedShortestPath::pathTo(const vertex& sink) const
{
	vector<edge> path{};
	
	if (!hasPathTo(sink)) return path;

	vertex x{ sink };
	for (edge e = _edgeTo[sink]; e; e = _edgeTo[x])
	{
		path.push_back(e);
		x = e.second();
	}
}

void DijkstraUndirectedShortestPath::relax(const edge& e, const vertex& v)
{
	vertex w{ e.second() };
	if (_distTo[w] > _distTo[v] + e.weight())
	{
		_distTo[w] = _distTo[v] + e.weight();
		_edgeTo[w] = e;

		if (_pq.containsIndex(w)) _pq.changeKey(_distTo[w], w);
		else                      _pq.insert(_distTo[w], w);
	}
}
