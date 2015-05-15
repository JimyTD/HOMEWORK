#ifndef CCIRCLE_H
#define CCIRCLE_H
#include"CShape.h"

class CCircle:public CShape
{
    public:
        CCircle(int cx,int cy,int r):centerx(cx),centery(cy),radius(r){}
        void draw()
        {
            std::cout<<"This is a Circle"<<std::endl;
        }
        virtual ~CCircle();
        int getArea()
        {
            return 3*radius*radius;
        }
    protected:
    private:
        int centerx;
        int centery;
        int radius;
};

#endif // CCIRCLE_H
