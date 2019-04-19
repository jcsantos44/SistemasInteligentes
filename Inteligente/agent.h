#pragma once
#include <iostream>

#define EAST		0
#define NORTHEAST	1
#define NORTH		2
#define NORTHWEST       3
#define WEST		4
#define SOUTHWEST       5
#define SOUTH		6
#define SOUTHEAST	7

#define CLOCKWISE    100
#define COUNTERCLOCK 101

class Robot {
  public:
    int getX() { return locX; }
    int getY() { return locY; }
    int getFacing() { return facing; }
    void setFacing(int f) { facing = f; }
    void setLocation(int x, int y){locX=x;locY=y;};
    int move(int direction){
	if(direction==EAST) 	       locY++;
	else if(direction==SOUTHEAST) {locY++;locX++;}
	else if(direction==WEST)       locY--;
	else if(direction==SOUTHWEST) {locY--;locX++;}
	else if(direction==SOUTH)             locX++;
	else if(direction==NORTHWEST) {locY--;locX--;}
	else if(direction==NORTH)             locX--;
	else if(direction==NORTHEAST) {locY++;locX--;}
	return 1;
	};
    void print_state()
	{
		printf("Robot position: X=%d, Y=%d, facing:",locX, locY);
		if(facing==NORTH) 	printf(" NORTH\n");
		if(facing==EAST) 	printf(" EAST\n");
		if(facing==SOUTH) 	printf(" SOUTH\n");
		if(facing==WEST) 	printf(" WEST\n");
		if(facing==NORTHEAST) 	printf(" NORTHEAST\n");
		if(facing==NORTHWEST) 	printf(" NORTHWEST\n");
		if(facing==SOUTHEAST) 	printf(" SOUTHEAST\n");
		if(facing==SOUTHWEST) 	printf(" SOUTHWEST\n");
        };

  private:
    int locX;
    int locY;
    int facing;
};
