#pragma once
#include <math.h>

class Chromossome
{
public:
    int x1,y1,r1;
    int x2,y2,r2;
    int x3,y3,r3;
    int CalculateFitness(int SourceX, int SourceY, int SourceR, int DestinationX, int DestinationY);
    Chromossome(int x1, int y1, int r1, int x2, int y2, int r2, int x3, int y3, int r3);
};

Chromossome::Chromossome(int x1, int y1, int r1, int x2, int y2, int r2, int x3, int y3, int r3)
{
    this->x1 = x1;
    this->y1 = y1;
    this->r1 = r1;
}

int Chromossome::CalculateFitness(int SourceX, int SourceY, int SourceR, int DestinationX, int DestinationY)
{
    int fitness = 0;
    int DistanceRotation = 0;
    DistanceRotation = r1 - SourceR;
    if (DistanceRotation > 4)
        DistanceRotation = ((8-r1)+SourceR);
    int DistanceSourceToFirstPoint;
    DistanceSourceToFirstPoint = sqrt((x1 - SourceX)*(x1 - SourceX) + (y1 - SourceY)*(y1 - SourceY)) + DistanceRotation;
    int DistanceLastPointToDestination = sqrt((DestinationX - SourceX)*(DestinationX - SourceX) + (DestinationY - SourceY)*(DestinationY - SourceY));

    fitness = DistanceSourceToFirstPoint + DistanceLastPointToDestination;

    return fitness;
}

Chromossome SpawnChromossome()
{
    Chromossome NewChromossome(rand()%10, rand()%10, rand()%10, rand()%10, rand()%10, rand()%10, rand()%10, rand()%10, rand()%10);
    return NewChromossome;
}
