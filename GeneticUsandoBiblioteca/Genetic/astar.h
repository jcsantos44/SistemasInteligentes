#pragma once
#include "graph.h"

std::vector<Estado> aStar(Graph* graph, Estado* source, Estado* destination, int numberOfNodes,  int numberOfRows, int numberOfColumns, int numberOfDirections);

std::vector<Estado> getAStarShortestPath(Graph* graph, Estado* source, Estado* destination, int numberOfNodes, int numberOfRows, int numberOfColumns, int numberOfDirections);
