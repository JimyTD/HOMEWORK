#ifndef BULLET_H
#define BULLET_H
#include <SFML/Graphics.hpp>
#include"FlyingObject.h"
#include"CTexture.h"

class Bullet:public FlyingObject
{
    public:
        Bullet(int nLeft,int nTop,int nWidth,int nHeight,int nSpeed,CTexture *ct,int nType,int nCount=0);
        virtual ~Bullet();
        int type;
    protected:
    private:



};

#endif // BULLET_H
