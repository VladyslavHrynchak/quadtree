#ifndef NODE_H
#define NODE_H
#include "point.h"

template<typename T>
struct Node
{

    Node()
    {

    }

    Node(Point pos_, T data_):pos(pos_),data(data_)
    {

    }

    Point pos;

    T data = 0;

};

#endif
