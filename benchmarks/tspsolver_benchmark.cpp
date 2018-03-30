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

		nodeCounts.push_back({2, 0});
		nodeCounts.push_back({3, 0});
		nodeCounts.push_back({4, 0});
		nodeCounts.push_back({5, 0});
		nodeCounts.push_back({6, 0});
		nodeCounts.push_back({7, 0});
		nodeCounts.push_back({8, 0});
		nodeCounts.push_back({9, 0});
		nodeCounts.push_back({10, 0});
		nodeCounts.push_back({11, 0});
		nodeCounts.push_back({12, 0});
		nodeCounts.push_back({13, 0});
		nodeCounts.push_back({14, 0});
		nodeCounts.push_back({15, 0});
		nodeCounts.push_back({16, 0});

		return nodeCounts;
	}

	void setUp(int64_t experimentValue) override {
		map = awesome::MapGen::random(experimentValue);
		this->experimentValue = experimentValue;
	}

protected:
	MapGraph map;
	int64_t experimentValue;

};

BASELINE_F(TSPSolver, NullHeuristic, TSPSolverFixture, 10, 1) {
	if(experimentValue < 10) {
		TSPSolver<NullHeuristic> nullTSPSolver(map);
		celero::DoNotOptimizeAway(nullTSPSolver.goForIt());
	}
}

BENCHMARK_F(TSPSolver, ShortestPathHeuristic, TSPSolverFixture, 10, 1) {
	if(experimentValue < 10) {
		TSPSolver<ShortestPathHeuristic> shortestPathTSPSolver(map);
		celero::DoNotOptimizeAway(shortestPathTSPSolver.goForIt());
	}
}

BENCHMARK_F(TSPSolver, MSTHeuristic, TSPSolverFixture, 10, 1) {
	if(experimentValue < 17) {
		TSPSolver<MSTHeuristic> mstTSPSolver(map);
		celero::DoNotOptimizeAway(mstTSPSolver.goForIt());
	}
}
