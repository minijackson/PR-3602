#include "psg.hpp"

namespace awesome {
	PSG::PSG(MapGraph map)
	      : psg()
	      , map(map) {
		for(std::pair<MapGraphVertexIt, MapGraphVertexIt> vp = boost::vertices(map);
		    vp.first != vp.second;
		    ++vp.first) {
			boost::add_edge(-1, *vp.first, 0, psg);
		}
	}
}
