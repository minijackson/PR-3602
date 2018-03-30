#pragma once

#include "heuristic.hpp"

namespace awesome {

	/*! \brief The null heuristic.
	 */
	class NullHeuristic : public Heuristic {
	public:

		/*! \brief Construct a null heuristic.
		 *
		 * \param psg the psg of the A* algorithm.
		 * \param map the map of the problem.
		 */
		NullHeuristic(Graph const& psg, MapGraph const& map);

		/*! \brief Get the \f$h(n)\f$ score of a given PSG node.
		 *
		 * \param state the intermediate state.
		 * \param node the given node.
		 * \return the \f$h(n) = 0\f$ score of a given node.
		 */
		int operator()(MapGraph const& state, GraphConstNode const& node) override;

	protected:
	private:
	};
}
