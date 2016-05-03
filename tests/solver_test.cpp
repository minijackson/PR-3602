#include "heuristics/null.hpp"
#include "heuristics/shortest_path.hpp"
#include "heuristics/mst.hpp"
#include "mapgen/mapgen.hpp"
#include "solver/tspsolver.hpp"

#include <fstream>

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_ALTERNATIVE_INIT_API
#include <boost/test/unit_test.hpp>

constexpr char csv1[] = "a,b,c,d,e\n"
                        "0,10,4,9,10\n"
                        "10,0,3,2,4\n"
                        "4,3,0,6,8\n"
                        "9,2,6,0,3\n"
                        "10,4,8,3,0\n";

// Example from "http://www.ams.org/samplings/feature-column/fcarc-tsp"
constexpr char csv2[] = "a,b,c,d,e\n"
                        "0,6,9,inf,10\n"
                        "6,0,11,inf,inf\n"
                        "9,11,0,5,14\n"
                        "inf,inf,5,0,8\n"
                        "10,inf,14,8,0\n";

bool init_unit_test() {
	std::ofstream file1("solver_1.csv");
	file1 << csv1;

	std::ofstream file2("solver_2.csv");
	file2 << csv2;

	return true;
}

int main(int argc, char* argv[]) {
	return ::boost::unit_test::unit_test_main(&init_unit_test, argc, argv);
}

BOOST_AUTO_TEST_CASE(dumb_null) {
	using TSPSolver        = awesome::TSPSolver<awesome::NullHeuristic>;
	using MapGraph         = TSPSolver::MapGraph;
	using ConstNode        = MapGraph::ConstNode_t;
	using WeightedProperty = graph::WeightedProperty;

	MapGraph map;

	map.addEdges({{"a", "b", WeightedProperty{1}},
	              {"b", "c", WeightedProperty{1}},
	              {"c", "d", WeightedProperty{1}},
	              {"d", "e", WeightedProperty{1}},
	              {"e", "a", WeightedProperty{1}}});

	TSPSolver solver(map);

	std::list<ConstNode> candidate{map["a"], map["b"], map["c"], map["d"], map["e"], map["a"]};

	BOOST_CHECK(solver.goForIt() == candidate);
}

BOOST_AUTO_TEST_CASE(dumb_shortest) {
	using TSPSolver        = awesome::TSPSolver<awesome::ShortestPathHeuristic>;
	using MapGraph         = TSPSolver::MapGraph;
	using ConstNode        = MapGraph::ConstNode_t;
	using WeightedProperty = graph::WeightedProperty;

	MapGraph map;

	map.addEdges({{"a", "b", WeightedProperty{1}},
	              {"b", "c", WeightedProperty{1}},
	              {"c", "d", WeightedProperty{1}},
	              {"d", "e", WeightedProperty{1}},
	              {"e", "a", WeightedProperty{1}}});

	TSPSolver solver(map);

	std::list<ConstNode> candidate{map["a"], map["b"], map["c"], map["d"], map["e"], map["a"]};

	BOOST_CHECK(solver.goForIt() == candidate);
}

BOOST_AUTO_TEST_CASE(dumb_mst) {
	using TSPSolver        = awesome::TSPSolver<awesome::MSTHeuristic>;
	using MapGraph         = TSPSolver::MapGraph;
	using ConstNode        = MapGraph::ConstNode_t;
	using WeightedProperty = graph::WeightedProperty;

	MapGraph map;

	map.addEdges({{"a", "b", WeightedProperty{1}},
	              {"b", "c", WeightedProperty{1}},
	              {"c", "d", WeightedProperty{1}},
	              {"d", "e", WeightedProperty{1}},
	              {"e", "a", WeightedProperty{1}}});

	TSPSolver solver(map);

	std::list<ConstNode> candidate{map["a"], map["b"], map["c"], map["d"], map["e"], map["a"]};

	BOOST_CHECK(solver.goForIt() == candidate);
}

BOOST_AUTO_TEST_CASE(solver_insolvable_null) {
	using awesome::MapGen;

	using TSPSolver = awesome::TSPSolver<awesome::NullHeuristic>;
	using MapGraph  = awesome::MapGen::MapGraph;

	MapGraph map = MapGen::fromFile("solver_2.csv");
	map.removeEdge(map["d"], map["c"]);
	map.removeEdge(map["c"], map["d"]);
	TSPSolver solver(map);

	BOOST_CHECK_THROW(solver.goForIt(), std::logic_error);
}

BOOST_AUTO_TEST_CASE(solver_insolvable_shortest) {
	using awesome::MapGen;

	using TSPSolver = awesome::TSPSolver<awesome::ShortestPathHeuristic>;
	using MapGraph  = awesome::MapGen::MapGraph;

	MapGraph map = MapGen::fromFile("solver_2.csv");
	map.removeEdge(map["d"], map["c"]);
	map.removeEdge(map["c"], map["d"]);
	TSPSolver solver(map);

	BOOST_CHECK_THROW(solver.goForIt(), std::logic_error);
}

BOOST_AUTO_TEST_CASE(solver_insolvable_mst) {
	using awesome::MapGen;

	using TSPSolver = awesome::TSPSolver<awesome::MSTHeuristic>;
	using MapGraph  = awesome::MapGen::MapGraph;

	MapGraph map = MapGen::fromFile("solver_2.csv");
	map.removeEdge(map["d"], map["c"]);
	map.removeEdge(map["c"], map["d"]);
	TSPSolver solver(map);

	BOOST_CHECK_THROW(solver.goForIt(), std::logic_error);
}

BOOST_AUTO_TEST_CASE(solver_sample_problem_1_null) {
	using awesome::MapGen;

	using TSPSolver = awesome::TSPSolver<awesome::NullHeuristic>;
	using MapGraph  = awesome::MapGen::MapGraph;
	using ConstNode = MapGraph::ConstNode_t;

	MapGraph map = MapGen::fromFile("solver_1.csv");
	TSPSolver solver(map);

	std::list<ConstNode> result   = solver.goForIt(),
	                     expected = {map["e"], map["d"], map["b"], map["c"], map["a"], map["e"]};

	BOOST_CHECK(result == expected);
}

BOOST_AUTO_TEST_CASE(solver_sample_problem_1_shortest) {
	using awesome::MapGen;

	using TSPSolver = awesome::TSPSolver<awesome::ShortestPathHeuristic>;
	using MapGraph  = awesome::MapGen::MapGraph;
	using ConstNode = MapGraph::ConstNode_t;

	MapGraph map = MapGen::fromFile("solver_1.csv");
	TSPSolver solver(map);

	std::list<ConstNode> result   = solver.goForIt(),
	                     expected = {map["a"], map["c"], map["b"], map["d"], map["e"], map["a"]};

	BOOST_CHECK(result == expected);
}

BOOST_AUTO_TEST_CASE(solver_sample_problem_1_mst) {
	using awesome::MapGen;

	using TSPSolver = awesome::TSPSolver<awesome::MSTHeuristic>;
	using MapGraph  = awesome::MapGen::MapGraph;
	using ConstNode = MapGraph::ConstNode_t;

	MapGraph map = MapGen::fromFile("solver_1.csv");
	TSPSolver solver(map);

	std::list<ConstNode> result   = solver.goForIt(),
	                     expected = {map["b"], map["c"], map["a"], map["e"], map["d"], map["b"]};

	BOOST_CHECK(result == expected);
}

BOOST_AUTO_TEST_CASE(solver_sample_problem_2_null) {
	using awesome::MapGen;

	using TSPSolver = awesome::TSPSolver<awesome::NullHeuristic>;
	using MapGraph  = awesome::MapGen::MapGraph;
	using ConstNode = MapGraph::ConstNode_t;

	MapGraph map = MapGen::fromFile("solver_2.csv");
	TSPSolver solver(map);

	std::list<ConstNode> result   = solver.goForIt(),
	                     expected = {map["c"], map["d"], map["e"], map["a"], map["b"], map["c"]};

	BOOST_CHECK(result == expected);
}

BOOST_AUTO_TEST_CASE(solver_sample_problem_2_shortest) {
	using awesome::MapGen;

	using TSPSolver = awesome::TSPSolver<awesome::ShortestPathHeuristic>;
	using MapGraph  = awesome::MapGen::MapGraph;
	using ConstNode = MapGraph::ConstNode_t;

	MapGraph map = MapGen::fromFile("solver_2.csv");
	TSPSolver solver(map);

	std::list<ConstNode> result   = solver.goForIt(),
	                     expected = {map["b"], map["a"], map["e"], map["d"], map["c"], map["b"]};

	BOOST_CHECK(result == expected);
}

BOOST_AUTO_TEST_CASE(solver_sample_problem_2_mst) {
	using awesome::MapGen;

	using TSPSolver = awesome::TSPSolver<awesome::MSTHeuristic>;
	using MapGraph  = awesome::MapGen::MapGraph;
	using ConstNode = MapGraph::ConstNode_t;

	MapGraph map = MapGen::fromFile("solver_2.csv");
	TSPSolver solver(map);

	std::list<ConstNode> result   = solver.goForIt(),
	                     expected = {map["d"], map["c"], map["b"], map["a"], map["e"], map["d"]};

	BOOST_CHECK(result == expected);
}
