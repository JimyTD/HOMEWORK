#include "Enemy.h"
#define TP_BULLET 20
#define TP_ENEMY 30
#define TP_NORMAL 44
#define TP_BOSS 88
#define TP_BOMB 987
#define TP_EXPLODE 785
#define TP_ENEMYBULLET 826
#define WIDTH 800
#define HEIGHT 600

Enemy::Enemy(int nLeft,int nTop,int nWidth,int nHeight,int nSpeed,CTexture *ct,int nType,int nScore,int life):FlyingObject(nLeft,nTop,nWidth,nHeight,nSpeed,ct,0)
{
    type=nType;
    this->life=life;
    if(nType==TP_NORMAL)
       {
           setTexture(ct->pEnemy1,true);

       }
    if(nType==TP_ENEMYBULLET)setTexture(ct->pEBullet);
    if(nType==TP_BOSS)
    {
        setTexture(ct->pBoss,true);

    }
    setPosition(nLeft,nTop);
    score=nScore;

}

Enemy::~Enemy()
{
    //dtor
}

void Enemy::draw()
{
    return;
}

void Enemy::explode()
{
    type=TP_EXPLODE;
    nCount=3;
    int midx=left+width/2,midy=top+height/2;
    width=40;
    height=37;
    left=midx-width/2;
    top=midy-height/2;
    speed=0;
    setTexture(ct->pBomb);

}
