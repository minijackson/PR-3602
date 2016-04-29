#include "mapgen/mapgen.hpp"

#include <fstream>
#include <set>

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_ALTERNATIVE_INIT_API
#include <boost/test/unit_test.hpp>

constexpr char csv1[] = "a,b,c,d,e\n"
                        "0,10,4,9,10\n"
                        "2,0,3,2,4\n"
                        "3,5,0,6,8\n"
                        "9,2,4,0,3\n"
                        "9,2,3,6,0\n";

// Example from "http://www.ams.org/samplings/feature-column/fcarc-tsp"
constexpr char csv2[] = "a,b,c,d,e\n"
                        "0,6,9,inf,10\n"
                        "6,0,11,inf,inf\n"
                        "9,11,0,inf,14\n"
                        "inf,inf,inf,0,8\n"
                        "10,inf,14,8,0\n";

bool init_unit_test() {
	std::ofstream file1("mapgen_1.csv");
	file1 << csv1;

	std::ofstream file2("mapgen_2.csv");
	file2 << csv2;

	return true;
}

int main(int argc, char* argv[]) {
	return ::boost::unit_test::unit_test_main(&init_unit_test, argc, argv);
}

BOOST_AUTO_TEST_CASE(mapgen_basic_csv) {
	using awesome::MapGen;
	MapGen::MapGraph map = MapGen::fromFile("mapgen_1.csv"),
	                 expected{{"a", "b", {10}}, {"a", "c", {4}}, {"a", "d", {9}}, {"a", "e", {10}},
	                          {"b", "a", {2}},  {"b", "c", {3}}, {"b", "d", {2}}, {"b", "e", {4}},
	                          {"c", "a", {3}},  {"c", "b", {5}}, {"c", "d", {6}}, {"c", "e", {8}},
	                          {"d", "a", {9}},  {"d", "b", {2}}, {"d", "c", {4}}, {"d", "e", {3}},
	                          {"e", "a", {9}},  {"e", "b", {2}}, {"e", "c", {3}}, {"e", "d", {6}}};

	BOOST_CHECK_EQUAL(map, expected);
}

BOOST_AUTO_TEST_CASE(mapgen_csv_with_inf) {
	using awesome::MapGen;
	MapGen::MapGraph map = MapGen::fromFile("mapgen_2.csv"), expected{{"a", "b", {6}},
	                                                                  {"a", "c", {9}},
	                                                                  {"a", "e", {10}},
	                                                                  {"b", "a", {6}},
	                                                                  {"b", "c", {11}},
	                                                                  {"c", "a", {9}},
	                                                                  {"c", "b", {11}},
	                                                                  {"c", "e", {14}},
	                                                                  {"d", "e", {8}},
	                                                                  {"e", "a", {10}},
	                                                                  {"e", "c", {14}},
	                                                                  {"e", "d", {8}}};

	BOOST_CHECK_EQUAL(map, expected);
}

BOOST_AUTO_TEST_CASE(mapgen_random) {
	using awesome::MapGen;

	MapGen::MapGraph map = MapGen::random(10);

	BOOST_CHECK_EQUAL(map.getVerticesCount(), 10);
	// 2×n(n-1)/2 = 90
	// ×2 because we store it as a directed graph
	BOOST_CHECK_EQUAL(map.getEdgesCount(), 90);
}
