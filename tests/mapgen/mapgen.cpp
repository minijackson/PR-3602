#include "mapgen.hpp"

#include "graph/algorithms.hpp"

#include <algorithm>
#include <complex>
#include <fstream>
#include <random>
#include <sstream>
#include <string>

namespace awesome {
	MapGen::MapGraph MapGen::fromFile(std::string filename) {
		MapGraph map;

		std::ifstream data(filename);

		std::vector<std::string> townNames;

		std::string line;

		{
			std::getline(data, line);
			std::stringstream lineStream(line);
			std::string currentTownName;
			while(std::getline(lineStream, currentTownName, ',')) {
				townNames.push_back(currentTownName);
			}
		}

		size_t originTownId = 0;
		while(std::getline(data, line)) {

			std::stringstream lineStream(line);
			std::string cell;
			size_t destinationTownId = 0;

			while(std::getline(lineStream, cell, ',')) {
				if(destinationTownId != originTownId) {
					if(cell != "inf") {
						map.addEdges({townNames[originTownId],
						              townNames[destinationTownId],
						              graph::WeightedProperty{std::stoi(cell)}});
					}
				}
				++destinationTownId;
			}
			++originTownId;
		}

		return map;
	}

	MapGen::MapGraph MapGen::random(size_t nodeCount) {
		std::random_device r;
		std::seed_seq seed{r(), r(), r(), r(), r(), r(), r(), r()};
		std::mt19937 gen(seed);
		std::uniform_int_distribution<> dist(0, 10);

		std::vector<std::complex<int>> nodes;

		std::generate_n(std::back_inserter(nodes),
		                nodeCount,
		                [&dist, &gen]() {
			                return std::complex<int>{dist(gen), dist(gen)};
			            });

		MapGraph map;

		for(size_t i = 0; i < nodeCount; ++i) {
			for(size_t j = i + 1; j < nodeCount; ++j) {
				std::string startNodeName = std::to_string(i), endNodeName = std::to_string(j);
				map.addEdges({startNodeName,
				              endNodeName,
				              graph::WeightedProperty{std::abs(nodes[i] - nodes[j])}});
			}
		}

		return graph::symmetric(map);
	}
}
