#pragma once

#include "graph/graph.hpp"

#include <list>
#include <set>
#include <unordered_set>

/*! \brief namespace containing the TSP solver and the heuristics.
 */
namespace awesome {

	/*! \brief The solver of TSP
	 */
	template <typename Heuristic>
	class TSPSolver {
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

		/*! \brief Construct a TSP solver.
		 *
		 * \param map the map of the problem.
		 */
		explicit TSPSolver(MapGraph const& map);

		/*! \brief solve the TSP problem.
		 *
		 * \return the list of node that constitute the solution of the TSP problem.
		 */
		std::list<MapGraphConstNode> goForIt();

	protected:
		/*! \brief A structure used to compare two PSG nodes.
		 */
		struct CompareFunc {
			/*! \brief Compare two PSG nodes relatively to the \f$f(n)\f$ score.
			 *
			 * \param lhs the first node to compare to.
			 * \param rhs the second node to compare to.
			 * \return true if lhs' \f$f(n)\f$ score is greater than rhs'.
			 */
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
