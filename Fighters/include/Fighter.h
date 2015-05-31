#ifndef FIGHTER_H
#define FIGHTER_H
#include <SFML/Graphics.hpp>
#include"FlyingObject.h"
#include"CTexture.h"
class CTexture;

class Fighter:public FlyingObject
{
    public:
        Fighter(int nLeft,int nTop,int nWidth,int nHeight,int nSpeed,CTexture *ct);
        virtual ~Fighter();
        void draw();
        void explode();
        int life;
        int type;
        CTexture *ct;
        int addSpeed;
    protected:
    private:



        ////bitmap

};

#endif // FIGHTER_H
