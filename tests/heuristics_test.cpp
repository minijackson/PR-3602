#include "graph/graph.hpp"

#include "heuristics/mst.hpp"
#include "heuristics/null.hpp"
#include "heuristics/shortest_path.hpp"

#include <tuple>

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN
#define BOOST_TEST_ALTERNATIVE_INIT_API
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(heuristics_null) {
	awesome::NullHeuristic::MapGraph map{{"0", "1", {1}},
	                                     {"1", "2", {2}},
	                                     {"2", "3", {3}},
	                                     {"3", "4", {4}},
	                                     {"4", "0", {5}},
	                                     {"0", "2", {1}},
	                                     {"0", "3", {2}},
	                                     {"1", "3", {1}},
	                                     {"1", "4", {3}},
	                                     {"2", "4", {4}}};

	awesome::NullHeuristic::Graph psg;
	auto degradedMap = map;

	awesome::NullHeuristic heur(psg, map);
	BOOST_CHECK_EQUAL(heur(degradedMap, psg["0"]), 0);

	degradedMap.removeNode(degradedMap["0"]);

	BOOST_CHECK_EQUAL(heur(degradedMap, psg["1"]), 0);
}

BOOST_AUTO_TEST_CASE(heuristics_shortest_path_basic) {
	awesome::ShortestPathHeuristic::MapGraph map{{"0", "1", {1}},
	                                             {"1", "2", {2}},
	                                             {"2", "3", {3}},
	                                             {"3", "4", {4}},
	                                             {"4", "0", {5}},
	                                             {"0", "2", {1}},
	                                             {"0", "3", {2}},
	                                             {"1", "3", {1}},
	                                             {"1", "4", {3}},
	                                             {"2", "4", {4}}};

	awesome::ShortestPathHeuristic::Graph psg;
	auto degradedMap = map;

	awesome::ShortestPathHeuristic heur(psg, map);
	BOOST_CHECK_EQUAL(heur(degradedMap, psg["0"]), 4);

	degradedMap.removeNode(degradedMap["0"]);

	BOOST_CHECK_EQUAL(heur(degradedMap, psg["1"]), 3);
}

BOOST_AUTO_TEST_CASE(heuristics_mst_basic) {
	awesome::MSTHeuristic::MapGraph map{{"0", "1", {1}},
	                                    {"1", "2", {2}},
	                                    {"2", "3", {3}},
	                                    {"3", "4", {4}},
	                                    {"4", "0", {5}},
	                                    {"0", "2", {1}},
	                                    {"0", "3", {2}},
	                                    {"1", "3", {1}},
	                                    {"1", "4", {3}},
	                                    {"2", "4", {4}}};

	awesome::MSTHeuristic::Graph psg;
	auto degradedMap = map;

	awesome::MSTHeuristic heur(psg, map);
	BOOST_CHECK_EQUAL(heur(degradedMap, psg["0"]), 6);

	degradedMap.removeNode(degradedMap["0"]);

	BOOST_CHECK_EQUAL(heur(degradedMap, psg["1"]), 6);
}
