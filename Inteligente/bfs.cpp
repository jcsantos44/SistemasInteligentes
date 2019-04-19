#include "bfs.h"
#include <list>
#include <iostream>

using namespace std;

Estado* nullEstado = new Estado(-1,-1,-1);

bool BFS(Graph* graph, Estado* source, Estado* destination, int numberOfNodes, Estado predecessor[][20][8], int distance[][20][8], int numberOfRows, int numberOfColumns, int numberOfDirections)
{
    //cout << numberOfNodes << endl;
    list<Estado> nodeQueue;

    //cout << source->getX() << source->getY() << source->getDirection() << endl;

    bool visited[20][20][8];

    for (int i = 0; i < numberOfRows; i++)
    {
        for (int j = 0; j < numberOfColumns; j++)
        {
            for (int k = 0; k < numberOfDirections; k++)
            {
                visited[i][j][k] = false;
                distance[i][j][k] = MAX;
                predecessor[i][j][k] = *nullEstado;
            }
        }
    }

    visited[source->getX()][source->getY()][source->getDirection()] = true;
    distance[source->getX()][source->getY()][source->getDirection()] = 0;
    nodeQueue.push_back(*source);

    while (!nodeQueue.empty())
    {

        Estado u = nodeQueue.front();

        nodeQueue.pop_front();

        vector<Estado> visiting = graph->getEdges(&u);
        //cout << u.getY() << endl;
        for (unsigned int i = 0; i < visiting.size(); i++)
        {

            if (visited[visiting[i].getX()][visiting[i].getY()][visiting[i].getDirection()] == false)
            {
                //cout << "Starting for" << endl;
                visited[visiting[i].getX()][visiting[i].getY()][visiting[i].getDirection()] = true;
                //cout << visiting[i].getX() << visiting[i].getY() << visiting[i].getDirection() << " - " << destination->getX() << destination->getY() << destination->getDirection() << endl;
                distance[visiting[i].getX()][visiting[i].getY()][visiting[i].getDirection()] = distance[u.getX()][u.getY()][u.getDirection()] + 1;
                predecessor[visiting[i].getX()][visiting[i].getY()][visiting[i].getDirection()] = u;
                nodeQueue.push_back(visiting[i]);
                //cout << "Finishing for" << endl;
                if (visiting[i].getX() == destination->getX() && visiting[i].getY() == destination->getY())
                {
                   *destination = visiting[i];
                    return true;
                }

            }
        }
    }
    return false;
}


void printBfsShortestDistance(Graph* graph, Estado* source, Estado* destination, int numberOfNodes, int numberOfRows, int numberOfColumns, int numberOfDirections)
{
    Estado predecessor[20][20][8];
    int distance[20][20][8];

    if(BFS(graph, source, destination, numberOfNodes, predecessor, distance, numberOfRows, numberOfColumns, numberOfDirections) == false)
    {
        cout <<"Source Node and Destination Node are not connected";
        return;
    }

    vector<Estado> path;
    Estado crawl = *destination;
    path.push_back(crawl);
    while (predecessor[crawl.getX()][crawl.getY()][crawl.getDirection()].getX() != nullEstado->getX() &&
           predecessor[crawl.getX()][crawl.getY()][crawl.getDirection()].getY() != nullEstado->getY() &&
           predecessor[crawl.getX()][crawl.getY()][crawl.getDirection()].getDirection() != nullEstado->getDirection())
    {
        path.push_back(predecessor[crawl.getX()][crawl.getY()][crawl.getDirection()]);
        crawl = predecessor[crawl.getX()][crawl.getY()][crawl.getDirection()];
    }

    //cout << distance[destination->getX()][destination->getY()][destination->getDirection()] << endl;

    for (int i=path.size() - 1; i>=0; i--)
    {
        cout << path[i].getX() << path[i].getY() << path[i].getDirection();
        if (i>0)
            cout << " -> ";
    }
}

vector<Estado> getBFSShortestPath(Graph* graph, Estado* source, Estado* destination, int numberOfNodes, int numberOfRows, int numberOfColumns, int numberOfDirections)
{
    Estado predecessor[20][20][8];
    int distance[20][20][8];

    if(BFS(graph, source, destination, numberOfNodes, predecessor, distance, numberOfRows, numberOfColumns, numberOfDirections) == false)
    {
        cout <<"Ponto de partida e ponto de chegada não estão conectados";
        vector<Estado> emptyVector = {};
        return emptyVector;
    }

    vector<Estado> path;
    Estado crawl = *destination;
    path.push_back(crawl);
    while (predecessor[crawl.getX()][crawl.getY()][crawl.getDirection()].getX() != nullEstado->getX() &&
           predecessor[crawl.getX()][crawl.getY()][crawl.getDirection()].getY() != nullEstado->getY() &&
           predecessor[crawl.getX()][crawl.getY()][crawl.getDirection()].getDirection() != nullEstado->getDirection())
    {
        path.push_back(predecessor[crawl.getX()][crawl.getY()][crawl.getDirection()]);
        crawl = predecessor[crawl.getX()][crawl.getY()][crawl.getDirection()];
    }

    return path;
}














