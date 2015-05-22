#ifndef ENEMY_H
#define ENEMY_H
#include <SFML/Graphics.hpp>
#include"FlyingObject.h"

class Enemy:public FlyingObject
{
    public:
        Enemy(int nLeft,int nTop,int nWidth,int nHeight);
        virtual ~Enemy();
        void draw();
    protected:
    private:
};

#endif // ENEMY_H
