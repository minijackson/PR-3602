#include "null.hpp"

#include <limits>

namespace awesome {

	NullHeuristic::NullHeuristic(Graph const& psg, MapGraph const& map)
	      : Heuristic(psg, map) {}

	int NullHeuristic::operator()(MapGraph const&, GraphConstNode) {
		return 0;
	}
}
