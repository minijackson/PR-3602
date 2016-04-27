#ifndef MST_HPP
#define MST_HPP

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

		int operator()(MapGraph const& state, GraphConstNode node) override;
	protected:
	private:
	};

}

#endif
