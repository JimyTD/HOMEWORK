#include "Bullet.h"
#include"CTexture.h"

Bullet::Bullet(int nLeft,int nTop,int nWidth,int nHeight,int nSpeed,CTexture *ct):FlyingObject(nLeft,nTop,nWidth,nHeight,nSpeed)
{
    setTexture(ct->pBullet);
    setPosition(nLeft,nTop);

}

Bullet::~Bullet()
{
    //dtor
}
