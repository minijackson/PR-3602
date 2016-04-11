#include "mapgen/mapgen.hpp"

#include <fstream>
#include <set>

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_ALTERNATIVE_INIT_API
#include <boost/test/unit_test.hpp>

constexpr char csv1[] = "0,1,2,3\n"
                        "4,0,6,7\n"
                        "8,9,0,11\n"
                        "12,13,14,0\n";

bool init_unit_test() {
	std::ofstream file("1.csv");
	file << csv1;
	return true;
}

int main(int argc, char* argv[]) {
	return ::boost::unit_test::unit_test_main(&init_unit_test, argc, argv);
}


BOOST_AUTO_TEST_CASE(test) {
	using awesome::MapGen;
	MapGen::MapGraph map = MapGen::fromFile("1.csv");

	std::set<int> vertices{}, expectedVertices{0, 1, 2, 3};

	MapGen::MapGraph::vertex_iterator vertexIt, verticesEndIt;
	for(boost::tie(vertexIt, verticesEndIt) = boost::vertices(map); vertexIt != verticesEndIt;
	    ++vertexIt) {
		vertices.insert(*vertexIt);
	}

	std::set<std::pair<int, int>> edges{}, expectedEdges{{0, 1},
	                                                     {0, 2},
	                                                     {0, 3},
	                                                     {1, 0},
	                                                     {1, 2},
	                                                     {1, 3},
	                                                     {2, 0},
	                                                     {2, 1},
	                                                     {2, 3},
	                                                     {3, 0},
	                                                     {3, 1},
	                                                     {3, 2}};

	MapGen::MapGraph::edge_iterator edgeIt, edgesEndIt;
	for(boost::tie(edgeIt, edgesEndIt) = boost::edges(map); edgeIt != edgesEndIt; ++edgeIt) {

		int source = boost::source(*edgeIt, map), target = boost::target(*edgeIt, map);

		edges.insert(std::pair<int, int>(source, target));

		int weight         = boost::get(boost::edge_weight_t(), map, *edgeIt),
		    expectedWeight = source * 4 + target;
		BOOST_CHECK_EQUAL(weight, expectedWeight);
	}

	BOOST_CHECK(vertices == expectedVertices);
	BOOST_CHECK(edges == expectedEdges);
}
