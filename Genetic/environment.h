#pragma once
#include <iostream>
#include "agent.h"
#include "graph.h"

#define ROBOT       26
#define WALL        27
#define TARGET	    28
#define NONE        -1

#define MAX_ROWS    20
#define MAX_COLS    20

#define NUMBERDIRECTIONS 8

class Environment {
 private:
    int n_rows, n_cols;
    typedef std::vector<std::vector<int> > mat;
    mat Matrix;
    Graph* graph;
    int x_target, y_target;
    //int Matrix[MAX_ROWS][MAX_COLS];
 public:
    Robot Rob1;
    Environment();
    void scan_state();
    void scan_state_from_file();
    void print_state();
    void move_robot(int direction);
    void rotate_robot(int clock_or_counterclock_90_degrees);
    void addForwardWalkToGraph(int ux, int uy, int udirection);
    void addRotationClockwiseToGraph(int ux, int uy, int udirection);
    void addRotationAnticlockwiseToGraph(int ux, int uy, int udirection);
    void traverseMatrixMakeStateGraph();
    std::vector<std::vector<int> > getMatrix();
    Graph* getGraph();
    int getN_Cols();
    int getN_Rows();
    int getX_Target();
    int getY_Target();
    Robot getAgent();
    void traverseShortestPath(std::vector<Estado> ShortestPath);
};
