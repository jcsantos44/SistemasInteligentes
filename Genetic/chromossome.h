#pragma once
#include <math.h>
#include <iostream>

class Chromossome
{
public:
    int x1,y1,r1;
    int x2,y2,r2;
    int x3,y3,r3;
    int fitness;

    Chromossome(int x1, int y1, int r1, int x2, int y2, int r2, int x3, int y3, int r3); //Constructor
    Chromossome();
    int CalculateFitness(int SourceX, int SourceY, int SourceR, int DestinationX, int DestinationY); //Evaluate FitnessFunction
    Chromossome Mate(Chromossome Partner);
    Chromossome Mutate();
    void PrintChromossome();
};

bool operator<(const Chromossome &c1, const Chromossome &c2);

Chromossome SpawnChromossome();
