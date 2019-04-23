#pragma once
#include "graph.h"
#include <vector>

using namespace std;

bool BFS(Graph* graph, Estado* source, Estado* destination, int numberOfNodes, Estado predecessor[][20][8], int distance[][20][8], int numberOfRows, int numberOfColumns, int numberOfDirections);

void printBfsShortestDistance(Graph* graph, Estado* source, Estado* destination, int numberOfNodes, int numberOfRows, int numberOfColumns, int numberOfDirections);

vector<Estado> getBFSShortestPath (Graph* graph, Estado* source, Estado* destination, int numberOfNodes, int numberOfRows, int numberOfColumns, int numberOfDirections);
