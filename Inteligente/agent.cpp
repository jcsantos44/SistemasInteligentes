#include "agent.h"

/*void addForwardWalk(Graph* graph, int ux, int uy, int udirection)
{
    switch(udirection)
    {
    case 0: graph->addCoordinateChange(ux, uy, udirection, ux-1, uy);
            break;
    case 1: graph->addCoordinateChange(ux, uy, udirection, ux-1, uy+1);
            break;
    case 2: graph->addCoordinateChange(ux, uy, udirection, ux, uy+1);
            break;
    case 3: graph->addCoordinateChange(ux, uy, udirection, ux+1, uy+1);
            break;
    case 4: graph->addCoordinateChange(ux, uy, udirection, ux+1, uy);
            break;
    case 5: graph->addCoordinateChange(ux, uy, udirection, ux+1, uy-1);
            break;
    case 6: graph->addCoordinateChange(ux, uy, udirection, ux, uy-1);
            break;
    case 7: graph->addCoordinateChange(ux, uy, udirection, ux-1, uy-1);
            break;
    }
    counter++;
}

void addRotationClockwise(Graph* graph, int ux, int uy, int udirection)
{
    if (udirection == 7)
        graph->addDirectionChange(ux, uy, udirection, 0);
    else
        graph->addDirectionChange(ux, uy, udirection, udirection+1);
        counter++;
}

void addRotationAnticlockwise(Graph* graph, int ux, int uy, int udirection)
{
    if (udirection == 0)
        graph->addDirectionChange(ux, uy, udirection, 7);
    else
        graph->addDirectionChange(ux, uy, udirection, udirection-1);
    counter++;
}*/
