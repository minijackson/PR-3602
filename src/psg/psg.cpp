#include "psg.hpp"

#include <boost/graph/iteration_macros.hpp>

namespace awesome {
	PSG::PSG(MapGraph map)
	      : psg()
	      , map(map) {
		psg.addNode("-1");
		map.eachVertices([this, &map](MapGraphConstNode node) {
			map.addEdges({"-1", node.getName()});
		});
	}

	void PSG::develop(std::string node) {

	}
}
