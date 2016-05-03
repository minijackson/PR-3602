#pragma once

#include "heuristic.hpp"

namespace awesome {

	/* The  Shortest Path Heuristic (Minimum Spanning Tree) inherits from the abstract heuristic class.
	 * In the map where the visited cities are left out, it uses the product of the shortest edge and
	 * the number of cities left to estimate the remaining cost.
	 */
	class ShortestPathHeuristic : public Heuristic {
	public:
		ShortestPathHeuristic(Graph const& psg, MapGraph const& map);

		int operator()(MapGraph const& state, GraphConstNode const& node) override;

	protected:
	private:
	};
}
