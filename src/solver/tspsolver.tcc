#pragma once

#include "tspsolver.hpp"

#include <algorithm>
#include <sstream>

namespace awesome {

	template <typename Heuristic>
	TSPSolver<Heuristic>::TSPSolver(MapGraph const& map)
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
			openNodes.insert(psg[townName]);
		});

		closedNodes.insert("-1");
	}

	template <typename Heuristic>
	auto TSPSolver<Heuristic>::goForIt() -> std::list<MapGraphConstNode> {
		while(openNodes.size() != 0) {
			GraphConstNode currentNode = *openNodes.begin();

			if(isGoal(currentNode)) {
				return finishLine(std::move(currentNode));
			}

			develop(currentNode);
		}
		throw std::logic_error("Something went wrong. Sorry.");
	}

	template <typename Heuristic>
	auto TSPSolver<Heuristic>::finishLine(GraphConstNode goal) -> std::list<MapGraphConstNode> {
		std::istringstream towns(goal.getName());

		std::list<MapGraphConstNode> travelerPath;

		for(std::string town; std::getline(towns, town, ',');) {
			travelerPath.push_back(map[town]);
		}
		return travelerPath;
	}

	template <typename Heuristic>
	void TSPSolver<Heuristic>::develop(GraphConstNode node) {

		std::string nodeName = node.getName();
		auto openSetNodeIt = findInOpenNodes(node);
		if(openSetNodeIt == openNodes.end()) {
			if(closedNodes.find(nodeName) == closedNodes.end()) {
				throw std::out_of_range("Non-existing node: " + nodeName);
			} else {
				return;
			}
		}

		MapGraph const& state = node.getProperty().state;

		std::string::size_type commaPos = nodeName.rfind(",");
		std::string currentTownName;
		if(commaPos == std::string::npos) {
			currentTownName = nodeName;
		} else {
			currentTownName = nodeName.substr(commaPos + 1);
		}

		state.eachAdjacents(state[currentTownName],
		                    [ this, &state, & psgParentNode = node, currentTownName ](
		                            MapGraphConstNode newTown) {

			                    std::string psgParentNodeName = psgParentNode.getName();
			                    std::string newTownName       = newTown.getName();

			                    std::string psgNewNodeName    = psgParentNodeName + "," + newTownName;
			                    GraphConstNode psgNewNode     = psg[psgNewNodeName];
			                    MapGraphConstNode currentTown = state[currentTownName];

			                    psg.addEdges({psgParentNodeName, psgNewNodeName});
			                    psg.setEdgeProperty(psgParentNode,
			                                        psgNewNode,
			                                        state.getEdgeProperty(currentTown, newTown));

			                    MapGraph newState = state;
			                    if(!isStart(psgParentNode)) {
				                    newState.removeNode(newState[currentTownName]);
			                    }

			                    psg[psgNewNodeName].setProperty(
			                            {/* gScore = */ psgParentNode.getProperty().gScore +
			                                     state.getEdgeProperty(currentTown, newTown).weight,
			                             /* hScore = */ heuristic(newState, psgNewNode),
			                             /* parent = */ psgParentNodeName,
			                             /* state = */ newState});
			                    openNodes.insert(psgNewNode);
			                });

		openNodes.erase(openSetNodeIt);
		closedNodes.insert(nodeName);
	}

	template <typename Heuristic>
	auto TSPSolver<Heuristic>::findInOpenNodes(GraphConstNode node) const ->
	        typename std::multiset<GraphConstNode, CompareFunc>::iterator {
		auto range = openNodes.equal_range(node);
		auto begin = range.first, end = range.second;
		for(auto it = begin; it != end; ++it) {
			if(*it == node) {
				return it;
			}
		}
		return openNodes.end();
	}

	template <typename Heuristic>
	bool TSPSolver<Heuristic>::isGoal(GraphConstNode node) const {
		std::istringstream towns(node.getName());

		size_t sum = 0;
		for(std::string town; std::getline(towns, town, ',');) {
			++sum;
		}
		return sum == (map.getVerticesCount() + 1);
	}

	template <typename Heuristic>
	bool TSPSolver<Heuristic>::isStart(GraphConstNode node) const {
		return node.getName().find(",") == std::string::npos;
	}
}
