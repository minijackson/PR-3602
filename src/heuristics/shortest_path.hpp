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
		ShortestPathHeuristic(Graph& psg, MapGraph& map, MapGraph& degradedMap);

		int operator()(std::string node) override;

	protected:
	private:
	};
}

#endif
