#include "mst.hpp"

#include "graph/algorithms.hpp"

#include <boost/graph/prim_minimum_spanning_tree.hpp>
#include <numeric>
#include <vector>

namespace awesome {

	MSTHeuristic::MSTHeuristic(Graph const& psg, MapGraph const& map)
	      : Heuristic(psg, map) {}

	int MSTHeuristic::operator()(MapGraph const& state, GraphConstNode const&) {
		MapGraph undirectedMap = graph::undirected(state);
		MapGraph mst = graph::minimumSpanningTree(undirectedMap, undirectedMap.begin());

		size_t sum = 0;
		mst.eachEdges([&mst, &sum](MapGraphConstNode begin, MapGraphConstNode end) {
			sum += mst.getEdgeProperty(begin, end).weight;
		});

		// Directed graph ⇒ 2× more edges !
		return sum / 2;
	}
}
