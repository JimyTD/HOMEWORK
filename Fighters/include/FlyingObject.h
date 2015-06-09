#ifndef FLYINGOBJECT_H
#define FLYINGOBJECT_H
#include<SFML/Graphics.hpp>
#include"CTexture.h"
class CTexture;
class FlyingObject:public sf::Sprite
{
    public:
        FlyingObject(int nLeft,int nTop,int nWidth,int nHeight,int nSpeed,CTexture *ct,int Count);
        virtual ~FlyingObject();
        int left;
        int top;
        int width;
        int height;
        int speed;
        int nCount;
        CTexture *ct;
        virtual void draw();
    protected:
    private:
};

#endif // FLYINGOBJECT_H
