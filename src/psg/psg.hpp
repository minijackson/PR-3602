#ifndef PSG_HPP
#define PSG_HPP

#include <boost/graph/graph_traits.hpp>
#include <boost/graph/adjacency_list.hpp>

namespace awesome {

	/*! \brief PSG description
	 *
	 * Detailed description
	 */
	class PSG {
		using EdgeWeightProperty = boost::property<boost::edge_weight_t, int>;

		using Graph = boost::adjacency_list<boost::vecS,
		                                    boost::vecS,
		                                    boost::directedS,
		                                    boost::no_property,
		                                    EdgeWeightProperty>;
		using VertexIt = boost::graph_traits<Graph>::vertex_iterator;

		using MapGraph = boost::adjacency_list<boost::vecS,
		                                       boost::vecS,
		                                       boost::directedS,
		                                       boost::no_property,
		                                       EdgeWeightProperty>;
		using MapGraphVertexIt = boost::graph_traits<MapGraph>::vertex_iterator;

	public:
		/*! \brief PSG description
		 *
		 * Detailed description
		 *
		 * \param map argument description
		 */
		explicit PSG(MapGraph map);

	protected:
		/*! \brief psg description
		 */
		Graph psg;

		/*! \brief map description
		 */
		MapGraph map;
	};
}

#endif
