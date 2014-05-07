// Name: David Castillo
// Quarter, Year: Spring, 14
// Project: 1
////////////////////////////////////////////////////////////

#ifndef __BSPTREE_H__
#define __BSPTREE_H__

#include <list>
#include "object.h"

using namespace std;


struct BSPNode
{
    Line2D partition;
    list<Rect2D> shapes;
    BSPNode *front;
    BSPNode *back;
};

struct BSPLeaf
{
    float floorHeight;
    float ceilHeight;
    Rect2D bounds;
    bool isBack;
};

class BSPTree
{
    public:
     void  BuildBSPTree(BSPNode *, list<Rect2D>);
     void  AddToList();
     void  GetFromList();
     void  SplitPoly();
    private:
      BSPNode *root;
      double dX(Line2D line);
      double ndY(Line2D line);
      double constant(Line2D line);
      int evalPoint(double x, double y, Line2D);
};

#endif
