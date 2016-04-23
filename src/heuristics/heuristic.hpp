#ifndef HEURISTIC_HPP
#define HEURISTIC_HPP

#include "graph.hpp"

namespace awesome {

	class Heuristic {
	public:
		using Graph = graph::list::Graph<graph::AstarNodeProperty, graph::WeightedProperty>;
		using GraphNode =
		        graph::list::Graph<graph::AstarNodeProperty, graph::WeightedProperty>::Node_t;
		using GraphConstNode =
		        graph::list::Graph<graph::AstarNodeProperty, graph::WeightedProperty>::ConstNode_t;

		using MapGraph     = graph::list::Graph<graph::NoProperty, graph::WeightedProperty>;
		using MapGraphNode = graph::list::Graph<graph::NoProperty, graph::WeightedProperty>::Node_t;
		using MapGraphConstNode =
		        graph::list::Graph<graph::NoProperty, graph::WeightedProperty>::ConstNode_t;

		Heuristic(Graph& psg, MapGraph& map, MapGraph& degradedMap);

		virtual int operator()(std::string node) = 0;

	protected:
		virtual ~Heuristic() = default;

		Graph& psg;
		MapGraph& map;
		MapGraph& degradedMap;
	};
}

#endif
