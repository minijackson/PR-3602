#include "psg.hpp"

#include <algorithm>

namespace awesome {
	PSG::PSG(MapGraph map)
	      : psg()
	      , map(map) {
		psg.addNode("-1");
		map.eachVertices([this, &map](MapGraphConstNode node) {
			map.addEdges({"-1", node.getName()});
			openNodes.insert(node.getName());
		});
		closedNodes.insert("-1");
	}

	void PSG::develop(std::string nodeName) {
		auto openSetNodeIt = openNodes.find(nodeName);
		if(openSetNodeIt == openNodes.end()) {
			if(closedNodes.find(nodeName) == closedNodes.end()) {
				throw std::out_of_range("Non-existing node: " + nodeName);
			} else {
				return;
			}
		}

		degradedMap.eachAdjacents(degradedMap[nodeName],
		                          [this, &nodeName](MapGraphConstNode end) {
			                          std::string endName = end.getName();
			                          if(closedNodes.count(endName) != 0) {
				                          return;
			                          }

			                          if(openNodes.count(endName) == 0) {
				                          openNodes.insert(endName);
										  // TODO: add fScore and gScore to the new node.
										  psg.addEdges({nodeName, nodeName + ", " + endName});
			                          }
			                      });

		openNodes.erase(openSetNodeIt);
		closedNodes.insert(nodeName);
	}
}
