#ifndef CSHAPE_H
#define CSHAPE_H
#include <iostream>

class CShape
{
    public:
        CShape();
        virtual void draw()
        {
            std::cout<<"This is a shape"<<std::endl;
        }
        virtual int getArea()
        {
            return 0;
        }
        virtual ~CShape();
    protected:
    private:
};

#endif // CSHAPE_H
