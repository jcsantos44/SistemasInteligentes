#include "estado.h"

Estado::Estado(){};

Estado::Estado(int x, int y, int direction)
{
    _x = x;
    _y = y;
    _direction = direction;
}

int Estado::getX() const
{
    return _x;
}

int Estado::getY() const
{
    return _y;
}

int Estado::getDirection() const
{
    return _direction;
}
