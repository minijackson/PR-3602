#pragma once

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

		Heuristic(Graph const& psg, MapGraph const& map);
		
		// Cette classe est "callable" : Pour lancer, l'heuristique, on peut directement
		// appeller l'objet créé. On définit pour cela l'opérateur "()"
		virtual int operator()(MapGraph const& state, GraphConstNode const& node) = 0;

	protected:
		virtual ~Heuristic() = default;

		Graph const& psg;
		MapGraph const& map;
	};
}
