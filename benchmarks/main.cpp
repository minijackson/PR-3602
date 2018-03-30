#include "solver/tspsolver.hpp"

#include "heuristics/mst.hpp"
#include "heuristics/null.hpp"
#include "heuristics/shortest_path.hpp"

#include "../tests/mapgen/mapgen.hpp"

#include <chrono>
#include <iostream>

int main() {
	awesome::MapGen::MapGraph map = awesome::MapGen::random(16);

	awesome::TSPSolver<awesome::MSTHeuristic> solver(map);

	auto start = std::chrono::high_resolution_clock::now();

	auto nodes = solver.goForIt();

	auto end = std::chrono::high_resolution_clock::now();

	for(auto const node : nodes) {
		std::cout << node.getName() << " ";
	}
	std::cout << std::endl;

	std::chrono::duration<double> diff = end - start;

	std::cout << "Time: " << diff.count() << std::endl;
}
