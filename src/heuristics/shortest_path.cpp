#include "shortest_path.hpp"

#include <limits>

namespace awesome {

	ShortestPathHeuristic::ShortestPathHeuristic(Graph const& psg, MapGraph const& map)
	      : Heuristic(psg, map) {}

	int ShortestPathHeuristic::operator()(MapGraph const& state, GraphConstNode const&) {

		int min = std::numeric_limits<int>::max();

		state.eachEdges([this, &state, &min](MapGraphConstNode begin, MapGraphConstNode end) {
			int weight = state.getEdgeProperty(begin, end).weight;
			if(weight < min) {
				min = weight;
			}
		});

		return min * (state.getVerticesCount() - 1);
	}
}
