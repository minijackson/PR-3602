#include "mapgen.hpp"

#include <fstream>
#include <sstream>
#include <string>

namespace awesome {
	MapGen::MapGraph MapGen::fromFile(std::string filename) {
		MapGraph map;

		std::ifstream data(filename);

		std::string line;
		size_t originTownName = 0;
		while(std::getline(data, line)) {

			std::stringstream lineStream(line);
			std::string cell;
			size_t destinationTownName = 0;

			while(std::getline(lineStream, cell, ',')) {
				if(destinationTownName != originTownName) {
					if(cell != "inf") {
						boost::add_edge(originTownName, destinationTownName, std::stoi(cell), map);
					}
				}
				++destinationTownName;
			}
			++originTownName;
		}

		return map;
	}
}
