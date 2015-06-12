#ifndef STUFF_H
#define STUFF_H
#include"FlyingObject.h"
#include"CTexture.h"
#include"Fighter.h"
#include"Game.h"

class Game;
class Stuff:public FlyingObject
{
    public:
        Stuff(int nLeft,int nTop,int nWidth,int nHeight,int nSpeed,CTexture *ct,int nType,Fighter *fighter,Game *game);
        virtual ~Stuff();
        int type;
        void affect();
    protected:
    private:
        Fighter *pFighter;
        Game *pGame;
};

#endif // STUFF_H
