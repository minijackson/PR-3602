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
		MSTHeuristic(Graph& psg, MapGraph& map, MapGraph& degradedMap);

		int operator()(std::string node) override;
	protected:
	private:
	};

}

#endif
