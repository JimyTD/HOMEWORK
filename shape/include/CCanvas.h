#ifndef CCANVAS_H
#define CCANVAS_H
#define ARR_SIZE 10
#include"CShape.h"
#include<iostream>
using namespace std;
class CCanvas
{
    public:
        CCanvas()
        {
            usage=0;
        }
        virtual ~CCanvas();
        void append(CShape* newShape);
        void draw();
        int totalArea()
        {
            int total=0;
            for(int i=0;i<usage;i++)
            {
              //  cout<<(arr[i]->getArea());
                total+=(arr[i]->getArea());
            }
            return total;
        }
    protected:
    private:
        CShape* arr[ARR_SIZE];
        int usage;//—≠ª∑”√<
};

#endif // CCANVAS_H
