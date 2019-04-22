#include <iostream>
#include <vector>
#include <string>
#include "graph.h"
#include "bfs.h"
#include "astar.h"
#include "environment.h"
#include "chromossome.h"
#include <bits/stdc++.h>

#define NUMBEROFITERATIONS 100

using namespace std;

int RandomNumber(int Start, int End)
    {
        int Range = (End - Start) + 1;
        int RandomInt = Start + (rand()%Range);
        return RandomInt;
    }

int main()
{

    Environment Env1;
    Env1.scan_state_from_file();
    Estado* source = new Estado(Env1.getAgent().getX(),Env1.getAgent().getY(),Env1.getAgent().getFacing());
    Estado* destination = new Estado(Env1.getX_Target(),Env1.getY_Target(),2);



    vector<Chromossome> Population;
    for (int i = 0; i < 10; i++)
    {
        Population.push_back(SpawnChromossome());
        Population[i].CalculateFitness(source->getX(), source->getY(), source->getDirection(), destination->getX(), destination->getY());
    }

    sort(Population.begin(), Population.end());

    for (int i = 0; i < 10; i ++)
    {
        cout << Population[i].fitness << endl;
        //Env1.AddPontoIntermediarioToStateMatrix(Population[i].x1, Population[i].y1, 1);
        //Env1.AddPontoIntermediarioToStateMatrix(Population[i].x2, Population[i].y2, 2);
        //Env1.AddPontoIntermediarioToStateMatrix(Population[i].x3, Population[i].y3, 3);
    }

    //Env1.AddPontoIntermediarioToStateMatrix(Population[0].x1, Population[0].y1, 1);
    //Env1.AddPontoIntermediarioToStateMatrix(Population[0].x2, Population[0].y2, 2);
    //Env1.AddPontoIntermediarioToStateMatrix(Population[0].x3, Population[0].y3, 3);

    int BestCost = sqrt((destination->getX() - source->getX())*(destination->getX() - source->getX()) + (destination->getY() - source->getY())*(destination->getY() - source->getY()));

    bool found = false;

    int NumberIterations = NUMBEROFITERATIONS;

    while(NumberIterations > 0)
    {
        cout << endl << NumberIterations << endl;
   //     cout << endl << endl << BestCost << endl;
        //if (Population[0].fitness <= BestCost)
        //{
        //    found = true;
        //    break;
        //}

        vector<Chromossome> NewGeneration;

        int SampleSize = (10*10)/100;      //10% most fittest go into new generation
        for (int i = 0; i < SampleSize; i++)
        {
            NewGeneration.push_back(Population[i]);
        }

        SampleSize = (90*10)/100;
        for (int i = 0; i < SampleSize; i++)
        {
           // cout << endl << RandomNumber(1,4) << endl;
            Chromossome Offspring = Population[RandomNumber(0,5)].Mate(Population[RandomNumber(0,5)]);
            Offspring.CalculateFitness(source->getX(), source->getY(), source->getDirection(), destination->getX(), destination->getY());
            //Offspring.PrintChromossome();
            NewGeneration.push_back(Offspring);
            Chromossome Mutation = Population[RandomNumber(6,9)].Mutate();
            Mutation.CalculateFitness(source->getX(), source->getY(), source->getDirection(), destination->getX(), destination->getY());
            NewGeneration.push_back(Mutation);
        }
        sort(NewGeneration.begin(),NewGeneration.end());
        Population = NewGeneration;
        sort(Population.begin(),Population.end());

        //cout << endl;
        for (int i = 0; i < 10; i ++)
        {
            //Population[i].PrintChromossome();
            cout << Population[i].fitness << endl;
            //cout << Population[i].x1 << "," << Population[i].y1 << endl;
            //cout << Population[i].x2 << "," << Population[i].y2 << endl;
            //cout << Population[i].x3 << "," << Population[i].y3 << endl;
        }
        NumberIterations--;
    }


    //sort(Population.begin(), Population.end());

    Env1.AddPontoIntermediarioToStateMatrix(Population[0].x1, Population[0].y1, 1);
    Env1.AddPontoIntermediarioToStateMatrix(Population[0].x2, Population[0].y2, 2);
    Env1.AddPontoIntermediarioToStateMatrix(Population[0].x3, Population[0].y3, 3);

    Env1.print_state();
}




