#include "graph/graph.hpp"

#include "heuristics/mst.hpp"
#include "heuristics/shortest_path.hpp"

#include <tuple>

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN
#define BOOST_TEST_ALTERNATIVE_INIT_API
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(heuristics_shortest_path_basic) {
	awesome::ShortestPathHeuristic::MapGraph map;

	std::vector<std::tuple<std::string, std::string, int>> edges{
	  std::tuple<std::string, std::string, int>{"0", "1", 1},
	  std::tuple<std::string, std::string, int>{"1", "2", 2},
	  std::tuple<std::string, std::string, int>{"2", "3", 3},
	  std::tuple<std::string, std::string, int>{"3", "4", 4},
	  std::tuple<std::string, std::string, int>{"4", "0", 5},
	  std::tuple<std::string, std::string, int>{"0", "2", 1},
	  std::tuple<std::string, std::string, int>{"0", "3", 2},
	  std::tuple<std::string, std::string, int>{"1", "3", 1},
	  std::tuple<std::string, std::string, int>{"1", "4", 3},
	  std::tuple<std::string, std::string, int>{"2", "4", 4}};

	int weight;
	std::string start, end;
	for(auto const& edge : edges) {
		std::tie(start, end, weight) = edge;

		map.addEdges({start, end});
		map.setEdgeProperty(map[start], map[end], {weight});

		map.addEdges({end, start});
		map.setEdgeProperty(map[end], map[start], {weight});
	}

	awesome::ShortestPathHeuristic::Graph psg;
	auto degradedMap = map;

	awesome::ShortestPathHeuristic heur(psg, map);
	BOOST_CHECK_EQUAL(heur(degradedMap, psg["0"]), 4);

	degradedMap.removeNode(degradedMap["0"]);

	BOOST_CHECK_EQUAL(heur(degradedMap, psg["1"]), 3);
}

BOOST_AUTO_TEST_CASE(heuristics_mst_basic) {
	awesome::MSTHeuristic::MapGraph map;

	std::vector<std::string> vertices{"0", "1", "2", "3", "4"};

	std::vector<std::tuple<std::string, std::string, int>> edges{
	  std::tuple<std::string, std::string, int>{"0", "1", 1},
	  std::tuple<std::string, std::string, int>{"1", "2", 2},
	  std::tuple<std::string, std::string, int>{"2", "3", 3},
	  std::tuple<std::string, std::string, int>{"3", "4", 4},
	  std::tuple<std::string, std::string, int>{"4", "0", 5},
	  std::tuple<std::string, std::string, int>{"0", "2", 1},
	  std::tuple<std::string, std::string, int>{"0", "3", 2},
	  std::tuple<std::string, std::string, int>{"1", "3", 1},
	  std::tuple<std::string, std::string, int>{"1", "4", 3},
	  std::tuple<std::string, std::string, int>{"2", "4", 4}};

	int weight;
	std::string start, end;
	for(auto const& edge : edges) {
		std::tie(start, end, weight) = edge;

		map.addEdges({start, end});
		map.setEdgeProperty(map[start], map[end], {weight});

		map.addEdges({end, start});
		map.setEdgeProperty(map[end], map[start], {weight});
	}

	awesome::MSTHeuristic::Graph psg;
	auto degradedMap = map;

	awesome::MSTHeuristic heur(psg, map);
	BOOST_CHECK_EQUAL(heur(degradedMap, psg["0"]), 6);

	degradedMap.removeNode(degradedMap["0"]);

	BOOST_CHECK_EQUAL(heur(degradedMap, psg["1"]), 6);
}
