#ifndef HEURISTIC_HPP
#define HEURISTIC_HPP

#include <boost/graph/graph_traits.hpp>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/labeled_graph.hpp>

namespace awesome {
	/*! \brief Heuristic description
	 *
	 * Detailed description
	 */
	class Heuristic {
	protected:
		using EdgeWeightProperty = boost::property<boost::edge_weight_t, int>;

	public:
		using Graph = boost::labeled_graph<boost::adjacency_list<boost::vecS,
		                                                         boost::vecS,
		                                                         boost::directedS,
		                                                         boost::no_property,
		                                                         EdgeWeightProperty>,
		                                   std::string>;
		using MapGraph = boost::labeled_graph<boost::adjacency_list<boost::vecS,
		                                                            boost::vecS,
		                                                            boost::directedS,
		                                                            boost::no_property,
		                                                            EdgeWeightProperty>,
		                                      std::string>;

		/*! \brief Heuristic description
		 *
		 * Detailed description
		 */
		Heuristic(Graph& psg, MapGraph& map, MapGraph& degradedMap);

		virtual int operator()(int node) = 0;

	protected:
		virtual ~Heuristic() = default;

		Graph& psg;
		MapGraph& map;
		MapGraph& degradedMap;
	};
}

#endif
