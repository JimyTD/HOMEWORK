#include "Stuff.h"
#include<iostream>
#define ST_SHIELD 124
#define ST_BIGBOMB 785
#define ST_HEALED 110
#define ST_ATK 568
#define ST_SPEED 741
#define ST_SCORE 121

Stuff::Stuff(int nLeft,int nTop,int nWidth,int nHeight,int nSpeed,CTexture *ct,int nType,Fighter *fighter,Game *game):FlyingObject(nLeft,nTop,nWidth,nHeight,nSpeed,ct,0)
{
    switch(nType)
    {
    case 0:
        {
            type=ST_SHIELD;
            setTexture(ct->pSTShield);
            break;
        }
    case 1:
        {
            type=ST_BIGBOMB;
            setTexture(ct->pSTBomb);
            break;
        }
    case 2:
        {
            type=ST_HEALED;
            setTexture(ct->pSTHeal);
            break;
        }
    case 3:
        {
            type=ST_ATK;
            setTexture(ct->pSTAtk);
            break;
        }
    case 4:
        {
            type=ST_SPEED;
            setTexture(ct->pSTSpd);
            break;
        }
    case 5:
        {
            type=ST_SCORE;
            setTexture(ct->pSTScore);
            break;
        }


    }
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
    case ST_SCORE:
        pGame->addScore(10);
        break;
    case ST_ATK:

        if(pGame->maxSCD>2)pGame->maxSCD-=2;
        break;
    case ST_SPEED:
        if(pFighter->speed<=20)pFighter->speed+=2;
        break;
    }
}
