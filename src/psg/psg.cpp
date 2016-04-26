#include "psg.hpp"
#include "../heuristics/mst.hpp"
#include "../heuristics/shortest_path.hpp"

namespace awesome {
	template class PSG<MSTHeuristic>;
	template class PSG<ShortestPathHeuristic>;
}
