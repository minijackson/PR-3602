#pragma once

#include "psg.hpp"

#include <algorithm>

namespace awesome {

	template <typename Heuristic>
	PSG<Heuristic>::PSG(MapGraph map)
	      : psg()
	      , map(map)
	      , heuristic(psg, map) {

		psg.addNode("-1");

		map.eachVertices([this, &map](MapGraphConstNode town) {
			std::string townName = town.getName();

			psg.addEdges({"-1", townName});
			psg[townName].setProperty({/* gScore = */ 0,
			                           /* hScore = */ heuristic(map, psg[townName]),
			                           /* parent = */ "-1",
			                           /* state = */ map});
			openNodes.insert(townName);
		});

		closedNodes.insert("-1");
	}

	template <typename Heuristic>
	void PSG<Heuristic>::develop(GraphConstNode node) {
		std::string nodeName = node.getName();
		auto openSetNodeIt = openNodes.find(nodeName);
		if(openSetNodeIt == openNodes.end()) {
			if(closedNodes.find(nodeName) == closedNodes.end()) {
				throw std::out_of_range("Non-existing node: " + nodeName);
			} else {
				return;
			}
		}

		MapGraph const& state = node.getProperty().state;
		std::string currentTownName = nodeName.substr(nodeName.rfind(", "));

		state.eachAdjacents(
		        state[currentTownName],
		        [ this, &state, & PSGparentNode = node, currentTownName ](
		                MapGraphConstNode newTown) {

			        std::string PSGparentNodeName = PSGparentNode.getName();
			        std::string newTownName       = newTown.getName();

			        if(closedNodes.count(newTownName) != 0) {
				        return;
			        }

			        if(openNodes.count(newTownName) == 0) {
				        std::string PSGNewNodeName = PSGparentNodeName + ", " + newTownName;
						MapGraphConstNode currentTown = state[currentTownName];

				        openNodes.insert(newTownName);
				        psg.addEdges({PSGparentNodeName, PSGNewNodeName});

						MapGraph newState = state;
						newState.removeNode(newState[currentTownName]);

				        psg[PSGNewNodeName].setProperty(
				                {/* gScore = */ PSGparentNode.getProperty().gScore +
				                         state.getEdgeProperty(currentTown, newTown).weight,
				                 /* hScore = */ heuristic(newState, psg[PSGNewNodeName]),
				                 /* parent = */ PSGparentNodeName,
				                 /* state = */ newState});
			        }
			    });

		openNodes.erase(openSetNodeIt);
		closedNodes.insert(nodeName);
	}
}
