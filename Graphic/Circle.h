#ifndef CIRCLE_H
#define CIRCLE_H
#include"Point.h"

class Circle:private Point
{
    public:
        Circle(Point a,int r);
        virtual ~Circle();
        Point getCenter();
        void move(int dx,int dy);
    protected:
    private:
        Point* pCenter;
        int radium;
};

#endif // CIRCLE_H
