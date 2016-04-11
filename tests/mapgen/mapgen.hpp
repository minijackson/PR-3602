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
	private:
		using EdgeWeightProperty = boost::property<boost::edge_weight_t, int>;

	public:
		using MapGraph = boost::adjacency_list<boost::vecS,
		                                       boost::vecS,
		                                       boost::directedS,
		                                       boost::no_property,
		                                       EdgeWeightProperty>;
	private:
		using MapGraphVertexIt = boost::graph_traits<MapGraph>::vertex_iterator;

	public:
		/*! \brief MapGen::fromFile description
		 *
		 * Detailed description
		 *
		 * \param filename CSV file to convert to map
		 */
		static MapGraph fromFile(std::string filename);

	private:
		MapGen();
	};
}

#endif
