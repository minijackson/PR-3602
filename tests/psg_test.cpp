#include "psg/psg.hpp"
#include "heuristics/shortest_path.hpp"

#include <iostream>

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN
#define BOOST_TEST_ALTERNATIVE_INIT_API
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(everything_mst) {
	using PSG = awesome::PSG<awesome::ShortestPathHeuristic>;
	using MapGraph = PSG::MapGraph;
	using ConstNode = MapGraph::ConstNode_t;

	MapGraph map;

	map.addNode("a");
	map.addNode("b");
	map.addNode("c");
	map.addNode("d");
	map.addNode("e");

	map.connect(map["a"], map["b"], {1});
	map.connect(map["b"], map["c"], {1});
	map.connect(map["c"], map["d"], {1});
	map.connect(map["d"], map["e"], {1});
	map.connect(map["e"], map["a"], {1});

	PSG psg(map);

	std::list<ConstNode> candidate{map["a"], map["b"], map["c"], map["d"], map["e"], map["a"]};

	BOOST_CHECK(psg.goForIt() == candidate);
}
