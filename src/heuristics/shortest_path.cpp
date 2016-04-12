#include "shortest_path.hpp"

#include <limits>

namespace awesome {

	ShortestPathHeuristic::ShortestPathHeuristic(Graph& psg, MapGraph& map, MapGraph& degradedMap)
	      : Heuristic(psg, map, degradedMap) {}

	int ShortestPathHeuristic::operator()(int node) {

		int min = std::numeric_limits<int>::max();

		MapGraph::edge_iterator edgeIt, edgesEndIt;
		for(boost::tie(edgeIt, edgesEndIt) = boost::edges(degradedMap); edgeIt != edgesEndIt; ++edgeIt) {

			int weight = boost::get(boost::edge_weight_t(), degradedMap, *edgeIt);
			min        = (weight < min) ? weight : min;
		}

		MapGraph::vertex_iterator verticesBeginIt, verticesEndIt;
		boost::tie(verticesBeginIt, verticesEndIt) = boost::vertices(degradedMap);

		return min * (std::distance(verticesBeginIt, verticesEndIt) - 1);
	}
}
