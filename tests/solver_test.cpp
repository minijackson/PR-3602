#include "solver/tspsolver.hpp"
#include "heuristics/shortest_path.hpp"

#include <iostream>

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN
#define BOOST_TEST_ALTERNATIVE_INIT_API
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(everything_mst) {
	using TSPSolver        = awesome::TSPSolver<awesome::ShortestPathHeuristic>;
	using MapGraph         = TSPSolver::MapGraph;
	using ConstNode        = MapGraph::ConstNode_t;
	using WeightedProperty = graph::WeightedProperty;

	MapGraph map;

	map.addEdges(std::make_tuple("a", "b", WeightedProperty{1}),
	             std::make_tuple("b", "c", WeightedProperty{1}),
	             std::make_tuple("c", "d", WeightedProperty{1}),
	             std::make_tuple("d", "e", WeightedProperty{1}),
	             std::make_tuple("e", "a", WeightedProperty{1}));

	TSPSolver solver(map);

	std::list<ConstNode> candidate{map["a"], map["b"], map["c"], map["d"], map["e"], map["a"]};

	BOOST_CHECK(solver.goForIt() == candidate);
}
