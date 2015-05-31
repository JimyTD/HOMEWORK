#include "Game.h"
#include"CRand.h"
#include <SFML/Graphics.hpp>
#include<memory.h>
#include<math.h>
#include<windows.h>
#include<iostream>
#define TP_BULLET 20
#define TP_ENEMY 30
#define TP_NORMAL 44
#define TP_BOSS 88
#define TP_BOMB 987
#define TP_EXPLODE 785
#define WIDTH 800
#define HEIGHT 600



class CRand;
Game::Game(sf::RenderWindow *window,CTexture *picture)
{
    pWindow=window;
    this->picture=picture;
    memset(pEnemy,NULL,MAX_ENEMY*sizeof(Enemy*));
    memset(pBullet,NULL,MAX_BULLET*sizeof(Bullet*));
    EnemyUsage=0;
    BulletUsage=0;
    Background.setTexture(picture->pBackground);
    score=0;

}

Game::~Game()
{
    //dtor
}

void Game::Entrance()
{
    sf::Event event;
    CRand::Prepare();
    while (pWindow->isOpen())
    {


    while (pWindow->pollEvent(event))
        {

            if (event.type == sf::Event::Closed)//shutdown
                {
                   pWindow->close();
                }

            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Left)//left key pressed
            {
                if((pFighter->left)>pFighter->speed)
                pFighter->speed-=10;
            }

            if ((event.type == sf::Event::KeyPressed)&&(event.key.code==sf::Keyboard::Right))//right key pressed
            {
                if((pFighter->left+30)<800-(pFighter->speed))
                pFighter->speed+=10;
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space)//space key pressed
            {
                Shoot();
            }
        }
            ////////////////////////////key answering///////////////////////
            /////////////change stuffs//////////////////////

            int nRand=CRand::GetRandomNumber3()%100;////new enemy
            if(nRand==1)
            {
                developEnemy(TP_NORMAL);
            }
            Move();
            collison();


            pWindow->clear();
 /////////////////////////Draw the stuffs.////////////////////////
        pWindow->draw(Background);
        if(pFighter->speed<0)pFighter->speed+=pFighter->addSpeed;
        if(pFighter->speed>0)pFighter->speed-=pFighter->addSpeed;
        if(pFighter->left<=0&&pFighter->speed<0)pFighter->speed=0;
        if(pFighter->left>=800-pFighter->width&&pFighter->speed>0)pFighter->speed=0;
        //THE EDGE.
        pFighter->left+=pFighter->speed;
        pFighter->setPosition(pFighter->left,pFighter->top);

        pWindow->draw(*pFighter);
        for(int i=0;i<MAX_BULLET;i++)
        {
            if(pEnemy[i]!=NULL)
            {
                switch(pEnemy[i]->type)
                {
                case TP_NORMAL:
                    pEnemy[i]->setPosition(pEnemy[i]->left,pEnemy[i]->top);
                    pWindow->draw(*(pEnemy[i]));
                    break;
                case TP_EXPLODE:
                    pEnemy[i]->setPosition(pEnemy[i]->left,pEnemy[i]->top);
                    pWindow->draw(*(pEnemy[i]));
                    pEnemy[i]->nCount--;
                    if(pEnemy[i]->nCount<0)
                    {
                        deleteEnemy(i);
                        mciSendString("seek bomb to 0", NULL, 0, NULL);
                        mciSendString("play bomb", NULL, 0, NULL);
                        addScore(1);
                    }
                }

            }
        }
        for(int i=0;i<MAX_ENEMY;i++)
        {


            if(pBullet[i]!=NULL)
            {
                pBullet[i]->setPosition(pBullet[i]->left,pBullet[i]->top);
                pWindow->draw(*(pBullet[i]));

            }


        }



       //////////

        pWindow->display();
    }



}


void Game::Shoot()
{
    //std::cout<<BulletUsage;
    if(BulletUsage>MAX_BULLET-2)return;
    for(int i=0;i<=99;i++)
       {
           if(pBullet[i]==NULL)
           {
               pBullet[i]=new Bullet(pFighter->left+pFighter->width/2-14,pFighter->top,28,60,10,picture);
               BulletUsage++;
               return;
           }

       }
}

void Game::developEnemy(int type)
{
    if(EnemyUsage>MAX_ENEMY-2)return ;
    if(type==TP_NORMAL)
    {
       CRand::Prepare();
       int left=CRand::GetRandomNumber()%700;
       for(int i=0;i<=MAX_ENEMY;i++)
       {
           if(pEnemy[i]==NULL)
           {
               pEnemy[i]=new Enemy(left,0,62,60,1,picture);
               pEnemy[i]->type=TP_NORMAL;
               EnemyUsage++;
               break;
           }
       }

    }


}

void Game::Move()
{

    for(int i=0;i<MAX_ENEMY;i++)
       {
           if(pEnemy[i]!=NULL)
           {
               pEnemy[i]->top+=pEnemy[i]->speed;
               if((pEnemy[i]->left)<(-pEnemy[i]->width))
               {
                   deleteEnemy(i);
                   continue;

               }

               if((pEnemy[i]->left)>WIDTH)
               {
                   deleteEnemy(i);
                   continue;

               }
               if((pEnemy[i]->top)>HEIGHT)
               {
                   deleteEnemy(i);
                   continue;
               }

           }

       }
    for(int j=0;j<MAX_BULLET;j++)
       {
           if(pBullet[j]!=NULL)
           {
               pBullet[j]->top-=pBullet[j]->speed;//Bullet heads front.
               if((pBullet[j]->top)<0)
               {
                   deleteBullet(j);
                   continue;

               }
           }

       }

}







void Game::collison()
{
    int collisons=0;
    for(int i=0;i<MAX_ENEMY;i++)
       {
           for(int j=0;j<MAX_BULLET;j++)
           {
             if((pEnemy[i]!=NULL)&&(pBullet[j]!=NULL))
                {
                    if(pEnemy[i]->type==TP_EXPLODE)continue;
                    int dx,dy;
                    dx=abs((pBullet[j]->left+pBullet[j]->width/2)-(pEnemy[i]->left+pEnemy[i]->width/2));
                    if(dx<(pBullet[j]->width/2+pEnemy[i]->width/2))
                        collisons++;
                    dy=abs((pBullet[j]->top+pBullet[j]->height/2)-(pEnemy[i]->top+pEnemy[i]->height/2));
                    if(dy<(pBullet[j]->height/2+pEnemy[i]->height/2))
                        collisons++;
                    if(collisons>=2)
                    {
                        pEnemy[i]->explode();
                        deleteBullet(j);
                    }
                    collisons=0;
                }
           }

       }
}
