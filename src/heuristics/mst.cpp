#include "mst.hpp"

#include <iostream>

#include <boost/graph/prim_minimum_spanning_tree.hpp>
#include <numeric>
#include <vector>

namespace awesome {

	MSTHeuristic::MSTHeuristic(Graph& psg, MapGraph& map, MapGraph& degradedMap)
	      : Heuristic(psg, map, degradedMap) {}

	int MSTHeuristic::operator()(std::string node) {
		std::vector<boost::graph_traits<Graph>::vertex_descriptor> p(
		  boost::num_vertices(degradedMap));
		boost::prim_minimum_spanning_tree(degradedMap, &p[0]);

		// Edge (p[i], i) is in the MST
		int sum = 0;
		for(std::size_t i = 0; i != p.size(); ++i) {
			if(p[i] != i) {
				sum += boost::get(
				  boost::edge_weight_t(), degradedMap, boost::edge(p[i], i, degradedMap).first);
			}
		}

		return sum;
	}
}
