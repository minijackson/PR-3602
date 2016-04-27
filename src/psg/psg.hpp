#ifndef PSG_HPP
#define PSG_HPP

#include "graph/graph.hpp"

#include <list>
#include <set>
#include <unordered_set>

namespace awesome {

	template <typename Heuristic>
	class PSG {
	public:
		using MapGraph          = graph::list::WeightedGraph;
		using MapGraphNode      = MapGraph::Node_t;
		using MapGraphConstNode = MapGraph::ConstNode_t;

		using Graph          = graph::list::AstarGraph<MapGraph>;
		using GraphNode      = Graph::Node_t;
		using GraphConstNode = Graph::ConstNode_t;

		explicit PSG(MapGraph const& map);

		std::list<MapGraphConstNode> goForIt();

	protected:
		std::list<MapGraphConstNode> finishLine(GraphConstNode goal);

		void develop(GraphConstNode node);

		bool isDeveloped(GraphConstNode node) const;

		bool isGoal(GraphConstNode node) const;

		bool isStart(GraphConstNode node) const;

		struct CompareFunc {
			bool operator()(GraphConstNode lhs, GraphConstNode rhs) const {
				return (lhs.getProperty().gScore + lhs.getProperty().hScore) <
				       (rhs.getProperty().gScore + rhs.getProperty().hScore);
			}
		};

		Graph psg;

		MapGraph const& map;

		std::multiset<GraphConstNode, CompareFunc> openNodes;

		std::unordered_set<std::string> closedNodes;

		Heuristic heuristic;
	};
}

#include "psg.tcc"

#endif
