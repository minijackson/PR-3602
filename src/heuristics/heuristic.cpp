#include "heuristic.hpp"

namespace awesome {

	Heuristic::Heuristic(Graph& psg, MapGraph& map, MapGraph& degradedMap)
	      : psg(psg)
	      , map(map)
	      , degradedMap(degradedMap) {}
}
