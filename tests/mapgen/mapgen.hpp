#ifndef MAPGEN_HPP
#define MAPGEN_HPP

#include "graph/graph.hpp"

namespace awesome {

	/*! \brief MapGen description
	 *
	 * Detailed description
	 */
	class MapGen {
	public:
		using MapGraph = graph::list::WeightedGraph;

	public:
		/*! \brief MapGen::fromFile description
		 *
		 * Detailed description
		 *
		 * \param filename CSV file to convert to map
		 */
		static MapGraph fromFile(std::string filename);

		static MapGraph random(size_t nodeCount);

	private:
		MapGen();
	};
}

#endif
