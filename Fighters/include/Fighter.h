#ifndef FIGHTER_H
#define FIGHTER_H
#include <SFML/Graphics.hpp>
#include"FlyingObject.h"
#include"CTexture.h"
class CTexture;

class Fighter:public FlyingObject
{
    public:
        Fighter(int nLeft,int nTop,int nWidth,int nHeight,int nSpeed,CTexture &ct);
        virtual ~Fighter();
        void draw();
        void explode();
    protected:
    private:
        int life;
        int type;


        ////bitmap

};

#endif // FIGHTER_H
