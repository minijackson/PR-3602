#include "shortest_path.hpp"

#include <limits>

namespace awesome {

	ShortestPathHeuristic::ShortestPathHeuristic(Graph& psg, MapGraph& map, MapGraph& degradedMap)
	      : Heuristic(psg, map, degradedMap) {}

	int ShortestPathHeuristic::operator()(std::string node) {

		int min = std::numeric_limits<int>::max();

		degradedMap.eachEdges([this, &min](MapGraphConstNode begin, MapGraphConstNode end) {
			int weight = degradedMap.getEdgeProperty(begin, end).weight;
			if(weight < min) {
				min = weight;
			}
		});

		return min * (degradedMap.getVerticesCount() - 1);
	}
}
