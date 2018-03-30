#pragma once

#include "graph/graph.hpp"

namespace awesome {

	/*! \brief Heuristic base class.
	 */
	class Heuristic {
	public:
		/*! \brief The map graph type used by the heuristic.
		 */
		using MapGraph          = graph::list::WeightedGraph;

		/*! \brief The map graph's node type used by the heuristic.
		 */
		using MapGraphNode      = MapGraph::Node_t;

		/*! \brief The map graph's immutable node type used by the heuristic.
		 */
		using MapGraphConstNode = MapGraph::ConstNode_t;

		/*! \brief The PSG graph type used by the heuristic.
		 */
		using Graph          = graph::list::AstarGraph<MapGraph>;

		/*! \brief The PSG graph's node type used by the heuristic.
		 */
		using GraphNode      = Graph::Node_t;

		/*! \brief The PSG graph's immutable node type used by the heuristic.
		 */
		using GraphConstNode = Graph::ConstNode_t;

		/*! \brief Construct an heuristic.
		 *
		 * \param psg the psg of the A* algorithm.
		 * \param map the map of the problem.
		 */
		Heuristic(Graph const& psg, MapGraph const& map);
		
		/*! \brief Get the \f$h(n)\f$ score of a given PSG node.
		 *
		 * \param state the intermediate state.
		 * \param node the given node.
		 * \return the \f$h(n)\f$ score of a given node.
		 */
		virtual int operator()(MapGraph const& state, GraphConstNode const& node) = 0;

	protected:
		virtual ~Heuristic() = default;

		/*! \brief The PSG of the A* algorithm.
		 */
		Graph const& psg;

		/*! \brief The base map of the problem.
		 */
		MapGraph const& map;
	};
}
