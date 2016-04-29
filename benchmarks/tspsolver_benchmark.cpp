#include <celero/Celero.h>

#include "solver/tspsolver.hpp"

#include "heuristics/mst.hpp"
#include "heuristics/null.hpp"
#include "heuristics/shortest_path.hpp"

#include "../tests/mapgen/mapgen.hpp"

CELERO_MAIN

class TSPSolverFixture : public celero::TestFixture {
public:
	template <typename Heuristic>
	using TSPSolver             = awesome::TSPSolver<Heuristic>;
	using NullHeuristic         = awesome::NullHeuristic;
	using ShortestPathHeuristic = awesome::ShortestPathHeuristic;
	using MSTHeuristic          = awesome::MSTHeuristic;
	using MapGraph              = awesome::MapGen::MapGraph;

	TSPSolverFixture() {}

	std::vector<std::pair<int64_t, uint64_t>> getExperimentValues() const override {
		std::vector<std::pair<int64_t, uint64_t>> nodeCounts;

		nodeCounts.push_back(std::pair<int64_t, uint64_t>(4, 0));
		nodeCounts.push_back(std::pair<int64_t, uint64_t>(8, 0));
		nodeCounts.push_back(std::pair<int64_t, uint64_t>(16, 0));
		nodeCounts.push_back(std::pair<int64_t, uint64_t>(32, 0));
		nodeCounts.push_back(std::pair<int64_t, uint64_t>(64, 0));
		nodeCounts.push_back(std::pair<int64_t, uint64_t>(128, 0));
		nodeCounts.push_back(std::pair<int64_t, uint64_t>(256, 0));

		return nodeCounts;
	}

	void setUp(int64_t experimentValue) override {
		map = awesome::MapGen::random(experimentValue);
	}

protected:
	MapGraph map;

};

BASELINE_F(TSPSolver, NullHeuristic, TSPSolverFixture, 10, 1) {
	TSPSolver<NullHeuristic> nullTSPSolver(map);
	celero::DoNotOptimizeAway(nullTSPSolver.goForIt());
}

BENCHMARK_F(TSPSolver, ShortestPathHeuristic, TSPSolverFixture, 10, 1) {
	TSPSolver<ShortestPathHeuristic> shortestPathTSPSolver(map);
	celero::DoNotOptimizeAway(shortestPathTSPSolver.goForIt());
}

BENCHMARK_F(TSPSolver, MSTHeuristic, TSPSolverFixture, 10, 1) {
	TSPSolver<MSTHeuristic> mstTSPSolver(map);
	celero::DoNotOptimizeAway(mstTSPSolver.goForIt());
}
