#ifndef MAPGEN_HPP
#define MAPGEN_HPP

#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/graph_traits.hpp>

namespace awesome {

	/*! \brief MapGen description
	 *
	 * Detailed description
	 */
	class MapGen {
		using EdgeWeightProperty = boost::property<boost::edge_weight_t, int>;

		using MapGraph = boost::adjacency_list<boost::vecS,
		                                       boost::vecS,
		                                       boost::directedS,
		                                       boost::no_property,
		                                       EdgeWeightProperty>;
		using MapGraphVertexIt = boost::graph_traits<MapGraph>::vertex_iterator;

	public:
		/*! \brief MapGen description
		 *
		 * Detailed description
		 *
		 */
		explicit MapGen();

		/*! \brief MapGen::fromFile description
		 *
		 * Detailed description
		 *
		 * \param filename CSV file to convert to map
		 */
		MapGraph fromFile(std::string filename);

	protected:
	};
}

#endif
