#ifndef BULLET_H
#define BULLET_H
#include <SFML/Graphics.hpp>
#include"FlyingObject.h"

class Bullet:public FlyingObject
{
    public:
        Bullet(int nLeft,int nTop,int nWidth,int nHeight);
        virtual ~Bullet();

    protected:
    private:
        int type;


};

#endif // BULLET_H
