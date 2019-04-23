#pragma once
#include <vector>
#include "estado.h"

#define MAX 2147483647


class Graph
{
private:

    typedef std::vector<std::vector<std::vector<std::vector<Estado> > > > adjacency;
    adjacency _adj;
    int _numberOfRows;
    int _numberOfColumns;
    int _numberOfDirections;
    //vector<Estado> _adj[5][5][8];
public:
    Graph();
    Graph (int numberOfRows, int numberOfColumns, int numberOfDirections);
    void makeAdjacencyList (int numberOfRows, int numberOfColumns, int numberOfDirections);
    void addDirectionChange(int ux, int uy, int udirection, int newDirection);
    void addCoordinateChange(int ux, int uy, int udirection, int vx, int vy);
    int getNumberOfColumns();
    int getNumberOfRows();
    std::vector<Estado> getEdges(Estado* estado);
    void printGraph();
};
