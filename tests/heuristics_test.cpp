#include "heuristics/shortest_path.hpp"

#include <tuple>

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN
#define BOOST_TEST_ALTERNATIVE_INIT_API
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(heuristics_shortest_path_basic) {
	awesome::ShortestPathHeuristic::MapGraph map;

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

	for(auto const& vertex : vertices) {
		boost::add_vertex(vertex, map);
	}

	int weight;
	std::string start, end;
	for(auto const& edge : edges) {
		std::tie(start, end, weight) = edge;

		boost::add_edge_by_label(start, end, weight, map);
		boost::add_edge_by_label(end, start, weight, map);
	}

	awesome::ShortestPathHeuristic::Graph psg;
	auto degradedMap = map;

	awesome::ShortestPathHeuristic heur(psg, map, degradedMap);
	BOOST_CHECK_EQUAL(heur(0), 4);

	boost::clear_vertex_by_label("0", degradedMap);
	boost::remove_vertex("0", degradedMap);

	BOOST_CHECK_EQUAL(heur(1), 3);
}
