#include "Circle.h"

Circle::Circle(Point a,int r):Point(a.getX(),a.getY())
{
    pCenter=&a;
    radium=r;
}

Circle::~Circle()
{
    //dtor
}

Point Circle::getCenter()
{
    return *pCenter;
}

void Circle::move(int dx,int dy)
{
    this->pCenter->getX()+=dx;
    this->pCenter->getY()+=dy;
}
