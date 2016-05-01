#pragma once

#include "graph/graph.hpp"

#include <list>
#include <set>
#include <unordered_set>

namespace awesome {

	template <typename Heuristic>
	class TSPSolver {
	public:
		using MapGraph          = graph::list::WeightedGraph;
		using MapGraphNode      = MapGraph::Node_t;
		using MapGraphConstNode = MapGraph::ConstNode_t;

		using Graph          = graph::list::AstarGraph<MapGraph>;
		using GraphNode      = Graph::Node_t;
		using GraphConstNode = Graph::ConstNode_t;

		explicit TSPSolver(MapGraph const& map);

		std::list<MapGraphConstNode> goForIt();

	protected:
		struct CompareFunc {
			bool operator()(GraphConstNode const& lhs, GraphConstNode const& rhs) const {
				return (lhs.getProperty().gScore + lhs.getProperty().hScore) <
				       (rhs.getProperty().gScore + rhs.getProperty().hScore);
			}
		};

		std::list<MapGraphConstNode> finishLine(GraphConstNode goal);

		void develop(GraphConstNode node);

		typename std::multiset<GraphConstNode, CompareFunc>::iterator findInOpenNodes(
		        GraphConstNode node) const;

		bool isGoal(GraphConstNode node) const;

		bool isFailure(GraphConstNode node) const;

		bool isStart(GraphConstNode node) const;

		Graph psg;

		MapGraph const& map;

		std::multiset<GraphConstNode, CompareFunc> openNodes;

		std::unordered_set<std::string> closedNodes;

		Heuristic heuristic;
	};
}

#include "tspsolver.tcc"
