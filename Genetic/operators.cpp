#include "operators.h"

bool operator == (const Estado &e1, const Estado &e2)
{
    return e1==e2;
}

bool operator < (const Estado &e1, const Estado &e2)
{
    return e1<e2;
}

bool operator != (const Estado &e1, const Estado &e2)
{
    return e1!=e2;
}

