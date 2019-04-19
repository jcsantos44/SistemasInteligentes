#pragma once

class Estado
{

private:
    int _x, _y;
    int _direction; //0 - North; 1 - Northeast; 2 - East; 3 - Southeast; 4 - South; 5 - Southwest; 6 - West; 7 - Northwest;
public:
    Estado(int x, int y, int direction);
    Estado();
    int getX() const;
    int getY() const;
    int getDirection() const;
    friend bool operator == (const Estado &e1, const Estado &e2){return e1==e2;}
    friend bool operator < (const Estado &e1, const Estado &e2){return e1<e2;};
    friend bool operator != (const Estado &e1, const Estado &e2){return e1!=e2;};
};
