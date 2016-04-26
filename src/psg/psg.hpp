#ifndef PSG_HPP
#define PSG_HPP

#include "graph/graph.hpp"

#include <unordered_set>

namespace awesome {

	template <typename Heuristic>
	class PSG {
		using MapGraph          = graph::list::WeightedGraph;
		using MapGraphNode      = MapGraph::Node_t;
		using MapGraphConstNode = MapGraph::ConstNode_t;

		using Graph          = graph::list::AstarGraph<MapGraph>;
		using GraphNode      = Graph::Node_t;
		using GraphConstNode = Graph::ConstNode_t;

	public:
		explicit PSG(MapGraph map);

		void develop(GraphConstNode nodeName);

	protected:
		Graph psg;

		MapGraph map;

		std::unordered_set<std::string> openNodes;

		std::unordered_set<std::string> closedNodes;

		Heuristic heuristic;
	};
}

#include "psg.tcc"

#endif
