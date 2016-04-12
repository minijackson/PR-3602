#ifndef HEURISTIC_HPP
#define HEURISTIC_HPP

#include <boost/graph/graph_traits.hpp>
#include <boost/graph/adjacency_list.hpp>

namespace awesome {
	/*! \brief Heuristic description
	 *
	 * Detailed description
	 */
	class Heuristic {
		using EdgeWeightProperty = boost::property<boost::edge_weight_t, int>;

		using Graph = boost::adjacency_list<boost::vecS,
		                                    boost::vecS,
		                                    boost::directedS,
		                                    boost::no_property,
		                                    EdgeWeightProperty>;
		using MapGraph = boost::adjacency_list<boost::vecS,
		                                       boost::vecS,
		                                       boost::directedS,
		                                       boost::no_property,
		                                       EdgeWeightProperty>;

	public:
		/*! \brief Heuristic description
		 *
		 * Detailed description
		 */
		Heuristic(Graph& psg, MapGraph& map, MapGraph& degradedMap);

		virtual int operator()(int node) = 0;

	protected:
		virtual ~Heuristic() = 0;

		Graph& psg;
		MapGraph& map;
		MapGraph& degradedMap;
	};
}

#endif
