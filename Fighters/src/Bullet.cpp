#include "Bullet.h"
#include"CTexture.h"
#define TP_BULLET 20
#define TP_ENEMY 30
#define TP_NORMAL 44
#define TP_BOSS 88
#define TP_BOMB 987
#define TP_EXPLODE 785
#define TP_ENEMYBULLET 826
#define TP_MAGIC 741
#define MD_NORMAL 555
#define MD_DEATH 666
#define MD_OVER 777
#define MD_STAGEON 856
#define MD_NEWGAME 773
#define MAGIC_WIDTH 960
#define MAGIC_HEIGHT 768
#define OPEN 852
#define CLOSED 741
#define WIDTH 800
#define HEIGHT 600

Bullet::Bullet(int nLeft,int nTop,int nWidth,int nHeight,int nSpeed,CTexture *ct,int nType,int Count):FlyingObject(nLeft,nTop,nWidth,nHeight,nSpeed,ct,Count)
{
    type=nType;
    if(type==TP_NORMAL)
    setTexture(ct->pBullet);
    if(type==TP_MAGIC)
    {
        setTexture(ct->pBigBomb,true);
        setTextureRect(sf::IntRect(0,0,MAGIC_WIDTH/4,MAGIC_HEIGHT/4));
        speed=0;
    }
    setPosition(nLeft,nTop);

}

Bullet::~Bullet()
{
    //dtor
}
