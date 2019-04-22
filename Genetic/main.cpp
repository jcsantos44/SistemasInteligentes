#include <iostream>
#include <vector>
#include <string>
#include "graph.h"
#include "bfs.h"
#include "astar.h"
#include "environment.h"
#include "genetic.h"

using namespace std;

int main()
{

    Environment Env1;
    Env1.scan_state_from_file();
    Estado* source = new Estado(Env1.getAgent().getX(),Env1.getAgent().getY(),Env1.getAgent().getFacing());
    Estado* destination = new Estado(Env1.getX_Target(),Env1.getY_Target(),2);
    //Env1.traverseMatrixMakeStateGraph();
   // Env1.getGraph()->printGraph();
    //aStar(Env1.getGraph(), source, destination);
    //printBfsShortestDistance(Env1.getGraph(), source, destination, Env1.getN_Rows()*Env1.getN_Cols()*NUMBERDIRECTIONS, Env1.getN_Rows(), Env1.getN_Cols(), NUMBERDIRECTIONS);
    //cout << endl;
    //getAStarShortestPath(Env1.getGraph(), source, destination, Env1.getN_Rows()*Env1.getN_Cols()*NUMBERDIRECTIONS, Env1.getN_Rows(), Env1.getN_Cols(), NUMBERDIRECTIONS);
    //Env1.traverseShortestPath(aStar(Env1.getGraph(), source, destination, Env1.getN_Rows()*Env1.getN_Cols()*NUMBERDIRECTIONS, Env1.getN_Rows(), Env1.getN_Cols(), NUMBERDIRECTIONS));
    //Env1.traverseShortestPath(getBFSShortestPath(Env1.getGraph(), source, destination, Env1.getN_Rows()*Env1.getN_Cols()*NUMBERDIRECTIONS,Env1.getN_Rows(), Env1.getN_Cols(), NUMBERDIRECTIONS));

    vector<Chromossome> Population;
    for (int i = 0; i < 50; i++)
    {
        Population.push_back(SpawnChromossome());
    }

    for (int i = 0; i < 50; i ++)
    {
        cout << Population[i].CalculateFitness(source->getX(), source->getY(), source->getDirection(), destination->getX(), destination->getY()) << endl;
    }

//    int M[20][20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
//                     0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
//                     0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
//                     0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
//                     1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,
//                     0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
//                     0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
//                     0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
//                     0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
//                     0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,1,
//                     0,0,0,0,0,0,1,1,0,0,0,0,1,0,0,0,0,0,1,0,
//                     0,0,0,0,0,1,1,0,0,0,0,1,0,0,0,0,0,1,0,0,
//                     0,0,0,0,1,1,0,0,0,0,1,0,0,0,0,0,1,0,0,0,
//                     0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,
//                     0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
//                     0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,
//                     0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,
//                     0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,
//                     0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,
//                     0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0};

//    Graph* graph = new Graph(numberOfRows, numberOfColumns, numberOfDirections);

//    //graph->printGraph();
//    //cout << counter << endl;

//    //printBfsShortestDistance(graph, source, destination, numberOfRows*numberOfColumns*numberOfDirections, numberOfRows, numberOfColumns, numberOfDirections);
//    printShortestPathMatrix(getShortestPath(graph, source, destination, numberOfRows*numberOfColumns*numberOfDirections, numberOfRows, numberOfColumns, numberOfDirections), M, numberOfRows, numberOfColumns, numberOfDirections);
//
//    return 0;
    //Graph* graph = new Graph(numberOfRows, numberOfColumns, numberOfDirections);

    //Env1.print_state();
}

//int counter = 20*20;
//
//void addForwardWalk(Graph* graph, int ux, int uy, int udirection)
//{
//    switch(udirection)
//    {
//    case 0: graph->addCoordinateChange(ux, uy, udirection, ux-1, uy);
//            break;
//    case 1: graph->addCoordinateChange(ux, uy, udirection, ux-1, uy+1);
//            break;
//    case 2: graph->addCoordinateChange(ux, uy, udirection, ux, uy+1);
//            break;
//    case 3: graph->addCoordinateChange(ux, uy, udirection, ux+1, uy+1);
//            break;
//    case 4: graph->addCoordinateChange(ux, uy, udirection, ux+1, uy);
//            break;
//    case 5: graph->addCoordinateChange(ux, uy, udirection, ux+1, uy-1);
//            break;
//    case 6: graph->addCoordinateChange(ux, uy, udirection, ux, uy-1);
//            break;
//    case 7: graph->addCoordinateChange(ux, uy, udirection, ux-1, uy-1);
//            break;
//    }
//    counter++;
//}
//
//void addRotationClockwise(Graph* graph, int ux, int uy, int udirection)
//{
//    if (udirection == 7)
//        graph->addDirectionChange(ux, uy, udirection, 0);
//    else
//        graph->addDirectionChange(ux, uy, udirection, udirection+1);
//    counter++;
//}
//
//void addRotationAnticlockwise(Graph* graph, int ux, int uy, int udirection)
//{
//    if (udirection == 0)
//        graph->addDirectionChange(ux, uy, udirection, 7);
//    else
//        graph->addDirectionChange(ux, uy, udirection, udirection-1);
//    counter++;
//}
//
//void traverseMatrix(Graph* graph, int M[][20], int numberOfRows, int numberOfColumns, int numberOfDirections)
//{
//    for (int i = 0; i < numberOfRows; i++)
//    {
//        for (int j = 0; j < numberOfColumns; j++)
//        {
//            for (int direction = 0; direction < numberOfDirections; direction ++)
//            {
//                switch (direction)
//                {
//                    case 0 : //north
//                        if (i-1 >= 0 && M[i-1][j] != 1)
//                            addForwardWalk(graph, i, j, direction);
//                        break;
//                    case 1 : //northeast
//                        if (i-1 >= 0 && j+1 < numberOfColumns && M[i-1][j+1] != 1)
//                            addForwardWalk(graph, i, j, direction);
//                        break;
//                    case 2 : //east
//                        if (j+1 < numberOfColumns && M[i][j+1] != 1)
//                            addForwardWalk(graph, i, j, direction);
//                        break;
//                    case 3 : //southeast
//                        if (i+1 < numberOfRows && j+1 < numberOfColumns && M[i+1][j+1] != 1)
//                            addForwardWalk(graph, i, j, direction);
//                        break;
//                    case 4 : //south
//                        if (i+1 < numberOfRows && M[i+1][j] != 1)
//                            addForwardWalk(graph, i, j, direction);
//                        break;
//                    case 5 : //southwest
//                        if (i+1 < numberOfRows && j-1 >= 0 && M[i+1][j-1] != 1)
//                            addForwardWalk(graph, i, j, direction);
//                        break;
//                    case 6 :
//                        if (j-1 >= 0 && M[i][j-1] != 1)
//                            addForwardWalk(graph, i, j, direction);
//                        break;
//                    case 7 :
//                        if (i-1 >= 0 && j-1 >= 0 && M[i-1][j-1] != 1)
//                            addForwardWalk(graph, i, j, direction);
//                        break;
//                }
//                addRotationClockwise(graph, i, j, direction);
//                addRotationAnticlockwise(graph, i, j, direction);
//            }
//        }
//    }
//}

//void printShortestPathMatrix(vector<Estado> shortestPath, int M[20][20], int numberOfRows, int numberOfColumns, int numberOfDirections)
//{
//    string M2[20][20];
//    for (int i = 0; i < numberOfRows; i++)
//    {
//        for (int j = 0; j < numberOfColumns; j++)
//        {
//            if (M[i][j] == 0)
//                M2[i][j] = '.';
//            else if (M[i][j] == 1)
//                M2[i][j] = '*';
//            else
//                M2[i][j] = std::to_string(M[i][j]);
//        }
//    }
//    for (int i=shortestPath.size() - 1; i>=0; i--)
//    {
//        switch (shortestPath[i].getDirection())
//        {
//            case NORTH :
//                M2[shortestPath[i].getX()][shortestPath[i].getY()] = '|';
//                break;
//            case NORTHEAST :
//                M2[shortestPath[i].getX()][shortestPath[i].getY()] = '/';
//                break;
//            case EAST :
//                M2[shortestPath[i].getX()][shortestPath[i].getY()] = '-';
//                break;
//            case SOUTHEAST :
//                M2[shortestPath[i].getX()][shortestPath[i].getY()] = '\\';
//                break;
//            case SOUTH :
//                M2[shortestPath[i].getX()][shortestPath[i].getY()] = '|';
//                break;
//            case SOUTHWEST :
//                M2[shortestPath[i].getX()][shortestPath[i].getY()] = '/';
//                break;
//            case WEST :
//                M2[shortestPath[i].getX()][shortestPath[i].getY()] = '-';
//                break;
//            case NORTHWEST :
//                M2[shortestPath[i].getX()][shortestPath[i].getY()] = '\\';
//                break;
//        }
//    }
//
//    for (int i = 0; i < numberOfRows; i++)
//    {
//        for (int j = 0; j < numberOfColumns; j++)
//        {
//            if (i == numberOfRows-1 && j == numberOfColumns-1)
//                cout << 'v';
//            else
//                cout << M2[i][j] << "|";
//        }
//        cout << endl;
//    }
//}




