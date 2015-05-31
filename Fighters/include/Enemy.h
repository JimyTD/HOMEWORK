#ifndef ENEMY_H
#define ENEMY_H
#include <SFML/Graphics.hpp>
#include"FlyingObject.h"
#include"CTexture.h"

class Enemy:public FlyingObject
{
    public:
        Enemy(int nLeft,int nTop,int nWidth,int nHeight,int nSpeed,CTexture *ct);
        virtual ~Enemy();
        void draw();
        void explode();
        CTexture *ct;
        int life;
        int type;
        int nCount;
    protected:
    private:


};

#endif // ENEMY_H
