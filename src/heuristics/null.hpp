#pragma once

#include "heuristic.hpp"

namespace awesome {

	/*! \brief ShortestPathHeuristic description
	 *
	 * Detailed description
	 */
	class NullHeuristic : public Heuristic {
	public:
		NullHeuristic(Graph const& psg, MapGraph const& map);

		int operator()(MapGraph const& state, GraphConstNode const& node) override;

	protected:
	private:
	};
}
