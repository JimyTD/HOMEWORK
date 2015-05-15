#ifndef CRECTANGLE_H
#define CRECTANGLE_H
#include"CShape.h"
#include<iostream>

class CRectangle:public CShape
{
    public:
        CRectangle(int x,int y,int width,int height):objectx(x),objecty(y),width(width),height(height){}
        void draw()
        {
            std::cout<<"This is a Rectangle"<<std::endl;
        }
        virtual ~CRectangle();
        int getArea()
        {
            return width*height;
        }
    protected:
    private:
        int objectx;
        int objecty;
        int width;
        int height;
};

#endif // CRECTANGLE_H
