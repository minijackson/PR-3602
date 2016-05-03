#pragma once

#include "heuristic.hpp"

namespace awesome {

	/* The  MST Heuristic (Minimum Spanning Tree) inherits from the abstract heuristic class.
	 * It uses the MST algorithm on the map where the cities we've already visited are removed.
	 * That way we get a precise estimate of the cost, event though it might be a bit slower 
	 * than other heuristics.
	 */
	class MSTHeuristic : public Heuristic {
	public:
		/*! \brief MSTHeuristic description
		 *
		 * Detailed description
		 */
		MSTHeuristic(Graph const& psg, MapGraph const& map);

		int operator()(MapGraph const& state, GraphConstNode const& node) override;
	protected:
	private:
	};

}
