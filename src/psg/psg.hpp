#ifndef PSG_HPP
#define PSG_HPP

#include "graph.hpp"

#include <vector>

namespace awesome {

	/*! \brief PSG description
	 *
	 * Detailed description
	 */
	class PSG {
		using Graph = graph::list::Graph<graph::AstarNodeProperty, graph::WeightedProperty>;
		using GraphNode =
		        graph::list::Graph<graph::AstarNodeProperty, graph::WeightedProperty>::Node_t;
		using GraphConstNode =
		        graph::list::Graph<graph::AstarNodeProperty, graph::WeightedProperty>::ConstNode_t;

		using MapGraph     = graph::list::Graph<graph::NoProperty, graph::WeightedProperty>;
		using MapGraphNode = graph::list::Graph<graph::NoProperty, graph::WeightedProperty>::Node_t;
		using MapGraphConstNode =
		        graph::list::Graph<graph::NoProperty, graph::WeightedProperty>::ConstNode_t;

	public:
		/*! \brief PSG description
		 *
		 * Detailed description
		 *
		 * \param map argument description
		 */
		explicit PSG(MapGraph map);

		/*! \brief develop description
		 *
		 * Detailed description
		 *
		 * \param node argument description
		 */
		void develop(std::string node);

	protected:
		/*! \brief psg description
		 */
		Graph psg;

		/*! \brief map description
		 */
		MapGraph map;

		std::vector<std::string> openNodes;

		std::vector<std::string> closedNodes;
	};
}

#endif
