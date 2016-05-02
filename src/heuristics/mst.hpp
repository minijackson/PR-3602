#pragma once

#include "heuristic.hpp"

namespace awesome {

	/*! \brief MSTHeuristic description
	 *
	 * Detailed description
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
