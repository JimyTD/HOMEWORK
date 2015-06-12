#include "Stuff.h"
#define ST_SHIELD 124
#define ST_BIGBOMB 785
#define ST_HEALED 110

Stuff::Stuff(int nLeft,int nTop,int nWidth,int nHeight,int nSpeed,CTexture *ct,int nType,Fighter *fighter,Game *game):FlyingObject(nLeft,nTop,nWidth,nHeight,nSpeed,ct,0)
{
    type=nType;
    pFighter=fighter;
    pGame=game;
}

Stuff::~Stuff()
{
    //dtor
}

void Stuff::affect()
{
    switch(type)
    {
    case ST_HEALED:
        pFighter->life++;
        break;
    case ST_SHIELD:
        pGame->getShield();
        break;
    case ST_BIGBOMB:
        pGame->getBigBomb();
        break;
    }
}
