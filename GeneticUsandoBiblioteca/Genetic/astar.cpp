#include "astar.h"
#include <queue>
#include <unordered_map>
#include <iostream>
#include <map>
#include <algorithm>


Estado* anullEstado = new Estado(-1,-1,-1);

template<typename Item, typename priority>
struct PriorityQueue
{
    typedef std::pair<priority, Item> PQItem;
    struct GreaterThan
    {
        bool operator()(PQItem Item1, PQItem Item2)
        {
            return Item1.first > Item2.first;
        }
    };
    std::priority_queue<PQItem, std::vector<PQItem>, GreaterThan> Items;

    inline bool empty() const
    {
        return Items.empty();
    }

    inline void put(Item ItemToInclude, priority PriorityToInclude)
    {
        Items.emplace(PriorityToInclude, ItemToInclude);
    }

    Item get()
    {
        Item best_item = Items.top().second;
        Items.pop();
        return best_item;
    }
};

inline double heuristic (Estado Node1, Estado Node2)
{
    return std::abs(Node1.getX() - Node2.getX()) + std::abs(Node1.getY() - Node2.getY());
}

std::vector<Estado> aStar(Graph* graph, Estado* source, Estado* destination, int numberOfNodes,  int numberOfRows, int numberOfColumns, int numberOfDirections)
{
    Estado PredecessorNode[20][20][8];
    int ShortestDistanceFromSource[20][20][8];
    bool visited[numberOfRows][numberOfColumns][numberOfDirections];
    bool FoundDestination = false;

    for (int i = 0; i < numberOfRows; i++)
    {
        for (int j = 0; j < numberOfColumns; j++)
        {
            for (int k = 0; k < numberOfDirections; k++)
            {
                ShortestDistanceFromSource[i][j][k] = MAX;
                PredecessorNode[i][j][k] = *anullEstado;
                visited[i][j][k];
            }
        }
    }

    PriorityQueue<Estado, double> Nodes;
    Nodes.put(*source, 0);
    ShortestDistanceFromSource[source->getX()][source->getY()][source->getDirection()] = 0;
    Estado current;
    while (!Nodes.empty())
    {
        current = Nodes.get();
        //std::cout << "Visiting: " << current.getX() << current.getY() << current.getDirection() << std::endl;
        if (current.getX() == destination->getX() && current.getY() == destination->getY())
        {
            //return true;
            *destination = current;
            FoundDestination = true;
            break;
        }
        visited[current.getX()][current.getY()][current.getDirection()] = true;
        for (Estado VisitingEdge : graph->getEdges(&current))
        {
            double NewCost = ShortestDistanceFromSource[current.getX()][current.getY()][current.getDirection()] + 1;
            if (visited[VisitingEdge.getX()][VisitingEdge.getY()][VisitingEdge.getDirection()] ==  false || NewCost < ShortestDistanceFromSource[VisitingEdge.getX()][VisitingEdge.getY()][VisitingEdge.getDirection()])
            {
                ShortestDistanceFromSource[VisitingEdge.getX()][VisitingEdge.getY()][VisitingEdge.getDirection()] = NewCost;
                double Priority = NewCost + heuristic(VisitingEdge, *destination);
                Nodes.put(VisitingEdge, NewCost);
                PredecessorNode[VisitingEdge.getX()][VisitingEdge.getY()][VisitingEdge.getDirection()] = current;
            }
        }
    }

    std::vector<Estado> path;
    Estado crawl = *destination;
    path.push_back(crawl);
    while (PredecessorNode[crawl.getX()][crawl.getY()][crawl.getDirection()].getX() != anullEstado->getX() &&
           PredecessorNode[crawl.getX()][crawl.getY()][crawl.getDirection()].getY() != anullEstado->getY() &&
           PredecessorNode[crawl.getX()][crawl.getY()][crawl.getDirection()].getDirection() != anullEstado->getDirection())
    {
        path.push_back(PredecessorNode[crawl.getX()][crawl.getY()][crawl.getDirection()]);
        crawl = PredecessorNode[crawl.getX()][crawl.getY()][crawl.getDirection()];
    }


    if (!FoundDestination)
    {
        std::cout << std::endl << "Source Node and Destination Node are not connected" << std::endl;
        *destination = current;
        return path;
    }

    std::cout << std::endl;
    for (int i=path.size() - 1; i>=0; i--)
    {
        std::cout << path[i].getX() << path[i].getY() << path[i].getDirection();
        if (i>0)
            std::cout << " -> ";
    }
    std::cout << std::endl;

    return path;
}
