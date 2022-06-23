#include <iostream>
#include "circle.h"
#include "quadtree.h"

using namespace std;

int main()
{
    Point x(0, 0);
    Point y(8, 8);
    Circle circle1(2.5);
    Circle circle2(5.1);
    Circle circle3(3.7);


    Quadtree<Circle> quadtree(x, y);

    Node one(Point(2, 4), circle1);
    Node two(Point(5, 1), circle2);
    Node three(Point(3, 7), circle3);

    quadtree.insert(&one);
    quadtree.insert(&two);
    quadtree.insert(&three);

    cout << "Node one: " << quadtree.search(Point(2, 4))->data.radius << endl;
    cout << "Node two: " << quadtree.search(Point(5, 1))->data.radius << endl;
    cout << "Node tree: " << quadtree.search(Point(3, 7))->data.radius << endl;


    return 0;
}
