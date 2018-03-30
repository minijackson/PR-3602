#pragma once

#include "heuristic.hpp"

namespace awesome {

	/*! \brief The heuristic using an MST.
	 */
	class MSTHeuristic : public Heuristic {
	public:
		/*! \brief Construct an MSTHeuristic.
		 *
		 * \param psg the psg of the A* algorithm.
		 * \param map the map of the problem.
		 */
		MSTHeuristic(Graph const& psg, MapGraph const& map);

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
