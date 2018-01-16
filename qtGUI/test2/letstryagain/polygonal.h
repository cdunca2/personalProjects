#ifndef POLYGONAL_H
#define POLYGONAL_H

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <utility>

using namespace std;

enum SHAPE {
    star,
    rhombus
};

class vertex {
public:
    double x, y;
    bool ishead;
    vertex* next;
    vertex* prev;

    vertex(double, double);
};

class polygon {
public:
    vertex* vertexes = NULL;

    polygon();
    polygon(int);
    polygon(SHAPE);
    void add_vert(double, double);
    void do_split();
    void do_average(int, vector<int>);
    void print_verts();
};

#endif // POLYGONAL_H
