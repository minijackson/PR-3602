#pragma once

#include "heuristic.hpp"

namespace awesome {

	/* The  Null Heuristic inherits from the abstract heuristic class.
	 * It simply returns 0 every time it's called
	 * It's the fastest and least performant heuristic
	 */
	class NullHeuristic : public Heuristic {
	public:
		NullHeuristic(Graph const& psg, MapGraph const& map);

		int operator()(MapGraph const& state, GraphConstNode const& node) override;

	protected:
	private:
	};
}
