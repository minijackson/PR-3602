#ifndef PSG_HPP
#define PSG_HPP

#include "graph.hpp"

#include <unordered_set>

namespace awesome {

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
		explicit PSG(MapGraph map);

		void develop(std::string nodeName);

	protected:
		Graph psg;

		MapGraph map;

		MapGraph degradedMap;

		std::unordered_set<std::string> openNodes;

		std::unordered_set<std::string> closedNodes;
	};
}

#endif
