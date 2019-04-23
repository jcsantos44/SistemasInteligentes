#include "chromossome.h"

bool operator<(const Chromossome &c1, const Chromossome &c2)
{
    return c1.fitness < c2.fitness;
}

Chromossome::Chromossome()
{

}

Chromossome::Chromossome(int x1, int y1, int r1, int x2, int y2, int r2, int x3, int y3, int r3)
{
    this->x1 = x1;
    this->y1 = y1;
    this->r1 = r1;
    this->x2 = x2;
    this->y2 = y2;
    this->r2 = r2;
    this->x3 = x3;
    this->y3 = y3;
    this->r3 = r3;
}

Chromossome Chromossome::Mate(Chromossome Partner)
{
    Chromossome ChildChromossome;
    ChildChromossome.x1 = this->x1;
    ChildChromossome.y1 = this->y1;
    ChildChromossome.x2 = this->x2;
    ChildChromossome.y2 = this->y2;
    ChildChromossome.x3 = Partner.x2;
    ChildChromossome.y3 = Partner.y2;
    //std::cout << "AAAA" << ChildChromossome.x1 << "AAA";
    return ChildChromossome;
}

Chromossome Chromossome::Mutate()
{
    Chromossome MutatedChromossome;
    MutatedChromossome = *this;
    int a = 2;
    while (a > 0){
        int PontoToMutate = rand()%2;
        int CoordinateToMutate = rand()%1;

        if (PontoToMutate == 0)
        {
            if (CoordinateToMutate == 0)
            {
                x1 = rand()%20;
            } else if (CoordinateToMutate == 1)
            {
                y1 = rand()%20;
            }
        }
        if (PontoToMutate == 1)
        {
            if (CoordinateToMutate == 0)
            {
                x2 = rand()%20;
            } else if (CoordinateToMutate == 1)
            {
                y2 = rand()%20;
            }
        }
        if (PontoToMutate == 2)
        {
            if (CoordinateToMutate == 0)
            {
                x2 = rand()%20;
            } else if (CoordinateToMutate == 1)
            {
                y2 = rand()%20;
            }
        }
        a--;
    }
    return MutatedChromossome;
}

int Chromossome::CalculateFitness(int SourceX, int SourceY, int SourceR, int DestinationX, int DestinationY)  // calular fitness function
{
    int fitness = 0;

    int DistanceRotation = 0;

    DistanceRotation = r1 - SourceR;            //Distancia de rotacao
    if (DistanceRotation > 4)
        DistanceRotation = ((8-r1)+SourceR);

    int DistanceSourceToFirstPoint;                 //Distancia para o primeito ponto intermediario
    DistanceSourceToFirstPoint = sqrt((x1 - SourceX)*(x1 - SourceX) + (y1 - SourceY)*(y1 - SourceY));

    int DistanceFirstPointToSecondPoint = sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));

    int DistanceSecondPointToThirdPoint = sqrt((x3 - x2)*(x3 - x2) + (y3 - y2)*(y3 - y2));
    //std::cout << "  " << (x1 - SourceX)*(x1 - SourceX) << " + " << (y1 - SourceY)*(y1 - SourceY) <<  std::endl;
    //std::cout << "  " << sqrt((x1 - SourceX)*(x1 - SourceX) + (y1 - SourceY)*(y1 - SourceY)) << std::endl;
    //std::cout << "  " << "(" << x1 << " - " << SourceX << ")" << "^2" << " + " << "(" << y1 << " - " << SourceY << ")" << "^2" << std::endl;
    //std::cout << "  " << DistanceRotation << std::endl;
    int DistanceThirdPointToDestination = sqrt((DestinationX - x3)*(DestinationX - x3) + (DestinationY - y3)*(DestinationY - y3));
    //std::cout << std::endl << std::endl;
    //std::cout << sqrt((DestinationX - x1)*(DestinationX - x1) + (DestinationY - y1)*(DestinationY - y1)) << std::endl;

    fitness = DistanceSourceToFirstPoint + DistanceFirstPointToSecondPoint + DistanceSecondPointToThirdPoint + DistanceThirdPointToDestination;
    this->fitness = fitness;
    return fitness;
}

void Chromossome::PrintChromossome()
{
    std::cout << std::endl;
    std::cout << "  " << x1 << "," << y1 << "," << r1 <<  std::endl;
    std::cout << "  " << x2 << "," << y2 << "," << r2 <<  std::endl;
    std::cout << "  " << x3 << "," << y3 << "," << r3 <<  std::endl;

}

Chromossome SpawnChromossome()
{
    int x1,y1,r1,x2,y2,r2,x3,y3,r3;
    x1 = rand()%20;
    y1 = rand()%20;
    r1 = rand()%20;
    x2 = rand()%20;
    y2 = rand()%20;
    r2 = rand()%20;
    x3 = rand()%20;
    y3 = rand()%20;
    r3 = rand()%20;

    //std::cout << "  " << x1 << ", " << y1 << ", " << r1 << ", " << std:: endl;
    //std::cout << "  " << x2 << ", " << y2 << ", " << r2 << ", " << std:: endl;
    //std::cout << "  " << x3 << ", " << y3 << ", " << r3 << ", " << std:: endl;
    //std::cout << std::endl;

    /*while ((x1 == x2 && y1 == y2) || (x2 == x3 && y2 == y3))
    {
        x2 = rand()%20;
        y2 = rand ()%20;
    }

    while ((x1 == x3 && y1 == y3) || (x2 == x3 && y2 == y3))
    {
        x3 = rand()%20;
        y3 = rand()%20;
    }*/

    Chromossome NewChromossome(x1, y1, r1, x2, y2, r2, x3, y3, r3);
//    NewChromossome.fitness = CalculateFitness()
    return NewChromossome;
}
