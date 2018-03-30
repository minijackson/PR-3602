#pragma once

#include "heuristic.hpp"

namespace awesome {

	/*! \brief the Shortest Path heuristic.
	 *
	 * In the map where the visited cities are left out, it uses the product of the shortest edge
	 * and the number of cities left to estimate the remaining cost.
	 */
	class ShortestPathHeuristic : public Heuristic {
	public:

		/*! \brief Construct a shortest path heuristic.
		 *
		 * \param psg the psg of the A* algorithm.
		 * \param map the map of the problem.
		 */
		ShortestPathHeuristic(Graph const& psg, MapGraph const& map);

		/*! \brief Get the \f$h(n)\f$ score of a given PSG node.
		 *
		 * \param state the intermediate state.
		 * \param node the given node.
		 * \return the \f$h(n)\f$ score of a given node.
		 */
		int operator()(MapGraph const& state, GraphConstNode const& node) override;

	protected:
	private:
	};
}
