#include "tspsolver.hpp"
#include "../heuristics/mst.hpp"
#include "../heuristics/shortest_path.hpp"

namespace awesome {
	template class TSPSolver<MSTHeuristic>;
	template class TSPSolver<ShortestPathHeuristic>;
}
