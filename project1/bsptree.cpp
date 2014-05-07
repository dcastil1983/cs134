#include "bsptree.h"
#include <vector>
#include <list>
#include <iostream>

using namespace std;


double BSPTree::dX(Line2D line)
{
   double x2 = line.p2.x;
   double x1 = line.p1.x;
   double dX = x2-x1;
   return dX;
}

double BSPTree::ndY(Line2D line)
{
    double y2 = line.p2.y;
    double y1 = line.p1.y;
    double ndY = (y2-y1) * -1;
    return ndY;
}
/*
double BSPTree::constant(Line2D line)
{
    double constant = 0.0;
    double dx = dX(line);
    double dy = ndY(line) * -1;
    constant = line.p1.x*dy - line.p1.y*dx;
    return constant; 
}
*/
/*
bool BSPTree::split()
{

    //Returns false if we have already split
    //if(leftChild != NULL || rightChild != NULL)
    {
        return false;
    }

}

*/

/*
void BSPTree::BuildBSPTree(BSPNode *tree, list<Rect2D> shapes)
{
    shape *root = shapes.GetFromList();
    tree -> partition = root -> getRect();
    tree -> shapes.AddToList(root);
    list front;
    list back;

    Rect2D rect;

    while((poly = polygons.GetFromList()) != NULL)
    {
        int result = tree -> partition.ClassifyPolygon(poly);
        switch(result)
        {

        }
    }
}

*/

