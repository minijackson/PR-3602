#include "mapgen.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

namespace awesome {
	MapGen::MapGraph MapGen::fromFile(std::string filename) {
		std::ifstream data(filename);

		std::string line;
		while(std::getline(data, line)) {
			std::stringstream lineStream(line);
			std::string cell;
			while(std::getline(lineStream, cell, ',')) {
				std::cout << cell << std::endl;
			}
		}
	}
}
