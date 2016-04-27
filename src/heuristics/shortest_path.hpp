#ifndef SHORTEST_PATH_HPP
#define SHORTEST_PATH_HPP

#include "heuristic.hpp"

namespace awesome {

	/*! \brief ShortestPathHeuristic description
	 *
	 * Detailed description
	 */
	class ShortestPathHeuristic : public Heuristic {
	public:
		ShortestPathHeuristic(Graph const& psg, MapGraph const& map);

		int operator()(MapGraph const& state, GraphConstNode node) override;

	protected:
	private:
	};
}

#endif
