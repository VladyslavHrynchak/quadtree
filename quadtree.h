#ifndef QUADTREE_H
#define QUADTREE_H
#include "point.h"
#include "node.h"
#include <iostream>

using namespace std;

template<typename T>
class Quadtree
{
public:
public:
    Quadtree()
    {

    }
    Quadtree(Point topLeft_, Point botRight_):topLeft(topLeft_),botRight(botRight_)
    {

    }
    void insert(Node<T> *node)
    {
        if (node == nullptr)
        {
            return;
        }

        if (!inBoundary(node->pos))
        {
            return;
        }

        if (abs(topLeft.x - botRight.x) <= 1 && abs(topLeft.y - botRight.y) <= 1)
        {
            if (n == nullptr)
            {
                n = node;
            }
            return;
        }

        if ((topLeft.x + botRight.x) / 2 >= node->pos.x)
        {

            if ((topLeft.y + botRight.y) / 2 >= node->pos.y)
            {
                if (topLeftTree == nullptr)
                {
                    topLeftTree = new Quadtree(Point(topLeft.x, topLeft.y), Point((topLeft.x + botRight.x) / 2, (topLeft.y + botRight.y) / 2));
                    topLeftTree->insert(node);
                }
            }


            else
            {
                if (botLeftTree == nullptr)
                {
                    botLeftTree = new Quadtree( Point(topLeft.x, (topLeft.y + botRight.y) / 2), Point((topLeft.x + botRight.x) / 2, botRight.y));
                    botLeftTree->insert(node);
                }
            }
        }
        else
        {

            if ((topLeft.y + botRight.y) / 2 >= node->pos.y)
            {
                if (topRightTree == nullptr)
                {
                    topRightTree = new Quadtree(Point((topLeft.x + botRight.x) / 2, topLeft.y), Point(botRight.x, (topLeft.y + botRight.y) / 2));
                    topRightTree->insert(node);
                }
            }


            else
            {
                if (botRightTree == nullptr)
                {
                    botRightTree = new Quadtree( Point((topLeft.x + botRight.x) / 2, (topLeft.y + botRight.y) / 2), Point(botRight.x, botRight.y));
                    botRightTree->insert(node);
                }
            }
        }
    }


    Node<T>* search(Point p)
    {

        if (!inBoundary(p))
        {
            return nullptr;
        }


        if (n != nullptr)
        {
            return n;
        }


        if ((topLeft.x + botRight.x) / 2 >= p.x)
        {

            if ((topLeft.y + botRight.y) / 2 >= p.y)
            {
                if (topLeftTree == nullptr)
                {
                    return nullptr;
                }
                else
                {
                    return topLeftTree->search(p);
                }
            }
            else
            {
                if (botLeftTree == nullptr)
                {
                    return nullptr;
                }
                else
                {
                    return botLeftTree->search(p);
                }


            }
        }
        else
        {

            if ((topLeft.y + botRight.y) / 2 >= p.y)
            {
                if (topRightTree == nullptr)
                {
                    return nullptr;
                }
                else
                {
                    return topRightTree->search(p);
                }
            }

            else
            {
                if (botRightTree == nullptr)
                {
                     return nullptr;
                }
                else
                {
                      return botRightTree->search(p);
                }

            }
        }
    };

    bool inBoundary(Point p)
    {
        return (p.x >= topLeft.x && p.x <= botRight.x && p.y >= topLeft.y && p.y <= botRight.y);
    }


private:
    Point topLeft = Point(0, 0);
    Point botRight = Point(0, 0);

    Node<T> *n = nullptr;

    Quadtree *topLeftTree = nullptr;
    Quadtree *topRightTree = nullptr;
    Quadtree *botLeftTree = nullptr;
    Quadtree *botRightTree = nullptr;


};

#endif
