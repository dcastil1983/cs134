// Name:David Castillo 
// Quarter, Year: Spring, 14
// Lab: 2
//
// This file is to be modified by the student.
// quadtree.cpp
////////////////////////////////////////////////////////////
#include "quadtree.h"
#include <iostream>
using namespace std;




QuadTreeNode::QuadTreeNode(const Rect2D & space)
	: nodeType(QUAD_TREE_LEAF), space(space), objects(), topLeft(NULL), topRight(NULL), bottomLeft(NULL), bottomRight(NULL)
{}

void QuadTreeNode::insert(const Line2D & value, int currentDepth, int depthLimit, int listLimit)
{
	if (nodeType == QUAD_TREE_PARENT)
	{
        objects.push_back(value);    
	}
	else //(nodeType == QUAD_TREE_LEAF)
	{
        /*
        if(objectCount >=2)
        {
            split
        }
        */

	}
}

void QuadTreeNode::query(const Point2D & p, std::vector<Line2D> & ret) const
{
	if (nodeType == QUAD_TREE_PARENT)
	{
	}
	else //if (nodeType == QUAD_TREE_LEAF)
	{
	}
}

//Recursively deletes the QuadTree
void QuadTreeNode::dealloc()
{
	if (topLeft)
	{
		topLeft->dealloc();
		delete topLeft;
	}
	if (topRight)
	{
		topRight->dealloc();
		delete topRight;
	}
	if (bottomLeft)
	{
		bottomLeft->dealloc();
		delete bottomLeft;
	}
	if (bottomRight)
	{
		bottomRight->dealloc();
		delete bottomRight;
	}
}

void QuadTreeNode::render() const
{
    int yes = 1;
	if (yes ==1/*nodeType == QUAD_TREE_PARENT*/)
	{
        Point2D a(400, 400);
        Point2D b(800, 400);
        Point2D c(800, 800);
        Point2D d(400, 800);
        Line2D first(a, b);
        Line2D second(a, d);
        Line2D third(d, c);
        Line2D fourth(c, b);

        first.render();
        second.render();
        third.render();
        fourth.render();

        for(int i = 0; i < objects.size();i++)
        {
    //        objects[i].render();
        }
	}
	else //if(nodeType == QUAD_TREE_LEAF)
	{
	}
}

QuadTree::QuadTree(const Rect2D & space, int dlim, int llim)
	: root(new QuadTreeNode(space)), depthLimit(dlim), listLimit(llim)
{}

QuadTree::~QuadTree()
{
	root->dealloc();
}

void QuadTree::insert(const Line2D & value)
{
	root->insert(value, 1, depthLimit, listLimit);
}

std::vector<Line2D> QuadTree::query(const Point2D & p) const
{
	std::vector<Line2D> ret;
	root->query(p, ret);
	return ret;
}

void QuadTree::render() const
{
	root->render();
}
