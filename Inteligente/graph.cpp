#include <vector>
#include <iostream>
#include "graph.h"

using namespace std;

Graph::Graph()
{
    makeAdjacencyList(5,5,8);
};

Graph::Graph(int numberOfRows, int numberOfColumns, int numberOfDirections)
{
    makeAdjacencyList(numberOfRows, numberOfColumns, numberOfDirections);
    _numberOfRows = numberOfRows;
    _numberOfColumns = numberOfColumns;
    _numberOfDirections = numberOfDirections;
}

void Graph::makeAdjacencyList(int numberOfRows, int numberOfColumns, int numberOfDirections)
{
    adjacency adj(numberOfRows, vector<vector<vector<Estado> > >
                (numberOfColumns, vector<vector<Estado> >
                (numberOfDirections, vector<Estado>(0))));
    _adj = adj;
}

void Graph::addDirectionChange(int ux, int uy, int udirection, int newDirection)
{
    Estado* newEstado = new Estado (ux,uy,newDirection);
    _adj[ux][uy][udirection].push_back(*newEstado);

}

void Graph::addCoordinateChange(int ux, int uy, int udirection, int vx, int vy)
{
    Estado* newEstado = new Estado (vx, vy, udirection);
    _adj[ux][uy][udirection].push_back(*newEstado);
}

int Graph::getNumberOfColumns()
{
    return _numberOfColumns;
}

int Graph::getNumberOfRows()
{
    return _numberOfRows;
}

std::vector<Estado> Graph::getEdges(Estado* estado)
{
    return _adj[estado->getX()][estado->getY()][estado->getDirection()];
}

void Graph::printGraph()
{
    for (int i = 0; i < _numberOfRows; i++)
    {
        for (int j = 0; j < _numberOfColumns; j++)
        {
            for (int k = 0; k < _numberOfDirections; k++)
            {
                cout << i << j << k;
                for (vector<Estado>::const_iterator iter = _adj[i][j][k].begin(); iter != _adj[i][j][k].end(); ++iter)
                {
                    cout << " -> " << iter->getX() << iter->getY() << iter->getDirection() << " ";
                }
                cout << endl;
            }
        }
    } cout << '\n';
}
