#ifndef FLYINGOBJECT_H
#define FLYINGOBJECT_H
#include<SFML/Graphics.hpp>

class FlyingObject:public sf::Sprite
{
    public:
        FlyingObject(int nLeft,int nTop,int nWidth,int nHeight,int nSpeed);
        virtual ~FlyingObject();
        int left;
        int top;
        int width;
        int height;
        int speed;
        virtual void draw();
    protected:
    private:
};

#endif // FLYINGOBJECT_H
