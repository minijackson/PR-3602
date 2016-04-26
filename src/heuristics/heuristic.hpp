#ifndef HEURISTIC_HPP
#define HEURISTIC_HPP

#include "graph/graph.hpp"

namespace awesome {

	class Heuristic {
	public:
		using MapGraph          = graph::list::WeightedGraph;
		using MapGraphNode      = MapGraph::Node_t;
		using MapGraphConstNode = MapGraph::ConstNode_t;

		using Graph          = graph::list::AstarGraph<MapGraph>;
		using GraphNode      = Graph::Node_t;
		using GraphConstNode = Graph::ConstNode_t;

		Heuristic(Graph& psg, MapGraph& map);

		virtual int operator()(MapGraph const& state, GraphConstNode node) = 0;

	protected:
		virtual ~Heuristic() = default;

		Graph& psg;
		MapGraph& map;
	};
}

#endif
