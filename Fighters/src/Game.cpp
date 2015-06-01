#include "Game.h"
#include"CRand.h"
#include <SFML/Graphics.hpp>
#include<memory.h>
#include<math.h>
#include<windows.h>
#include<iostream>
#include<string>
using namespace std;
#define TP_BULLET 20
#define TP_ENEMY 30
#define TP_NORMAL 44
#define TP_BOSS 88
#define TP_BOMB 987
#define TP_EXPLODE 785
#define TP_ENEMYBULLET 826
#define MD_NORMAL 555
#define MD_DEATH 666
#define MD_OVER 777
#define WIDTH 800
#define HEIGHT 600




class CRand;
Game::Game(sf::RenderWindow *window,CTexture *picture,int nMode)
{
    pWindow=window;
    this->picture=picture;
    memset(pEnemy,NULL,MAX_ENEMY*sizeof(Enemy*));
    memset(pBullet,NULL,MAX_BULLET*sizeof(Bullet*));
    EnemyUsage=0;
    BulletUsage=0;
    Background.setTexture(picture->pBackground);
    Lose.setTexture(picture->pOver);
    score=0;
    font.loadFromFile("D:\\ProgramsOfTD\\C CPP HMWK\\Fighters\\Fonts\\Medhurst-regular.ttf");
    ScoreText.setFont(font);
    ScoreText.setCharacterSize(30);
    ScoreText.setStyle(sf::Text::Bold);
    ScoreText.setColor(sf::Color::Green);
    mode=nMode;

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
        if(mode!=MD_OVER)
        {
            int nRand=CRand::GetRandomNumber3()%100;////new enemy
            if(nRand==1)
            {
                developEnemy(TP_NORMAL);
            }
            Move();
            collison();
            char sc[20];
            sprintf(sc,"Score:%d",score);
            ScoreText.setString(sc);
        }



            pWindow->clear();
 /////////////////////////Draw the stuffs.////////////////////////

       if(mode==MD_NORMAL||mode==MD_DEATH)
       {
            pWindow->draw(Background);
            if(pFighter->speed<0)pFighter->speed+=pFighter->addSpeed;
            if(pFighter->speed>0)pFighter->speed-=pFighter->addSpeed;
            if(pFighter->left<=0&&pFighter->speed<0)pFighter->speed=0;
            if(pFighter->left>=800-pFighter->width&&pFighter->speed>0)pFighter->speed=0;
            //THE EDGE.
            pFighter->left+=pFighter->speed;
            pFighter->setPosition(pFighter->left,pFighter->top);

            if(pFighter->nCount%10<=4)
            pWindow->draw(*pFighter);
            if(mode==MD_DEATH)
            {
                if(pFighter->nCount==120)pFighter->setTexture(picture->pFighter);
                pFighter->nCount--;
                if(pFighter->nCount<=0)
                {
                    mode=MD_NORMAL;
                    pFighter->type=TP_NORMAL;
                }
            }
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
                        break;
                    case TP_ENEMYBULLET:
                        pEnemy[i]->setPosition(pEnemy[i]->left,pEnemy[i]->top);
                        pWindow->draw(*(pEnemy[i]));
                        break;

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
            pWindow->draw(ScoreText);
       }
    if(mode==MD_OVER)
        {
            pWindow->draw(Lose);
            pWindow->draw(ScoreText);
        }








       //////////

        pWindow->display();
    }



}


void Game::Shoot()
{
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

void Game::developEnemy(int type,int m)
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
               pEnemy[i]=new Enemy(left,0,62,60,1,picture,TP_NORMAL);
               EnemyUsage++;
               break;
           }
       }

    }
    if(type==TP_ENEMYBULLET)
        {
            for(int i=0;i<=MAX_ENEMY;i++)
               {
                   if(pEnemy[i]==NULL)
                   {
                       pEnemy[i]=new Enemy(pEnemy[m]->left+pEnemy[m]->width/2-5,pEnemy[m]->top+pEnemy[m]->height,12,25,4,picture,TP_ENEMYBULLET);
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
               if(pEnemy[i]->type==TP_NORMAL||pEnemy[i]->type==TP_ENEMYBULLET)
               {

                       pEnemy[i]->top+=pEnemy[i]->speed;
                       if(pEnemy[i]->nCount>0)pEnemy[i]->nCount--;
                        if(pEnemy[i]->nCount<=0)enemyShoot(i);
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
                   if(pEnemy[i]->type==TP_EXPLODE)
                    {
                        pEnemy[i]->nCount--;
                        if(pEnemy[i]->nCount<0)
                        {
                            addScore(1);
                            deleteEnemy(i);
                            mciSendString("seek explode to 0", NULL, 0, NULL);
                            mciSendString("play explode", NULL, 0, NULL);
                            continue;
                        }
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
                   break;

               }
           }

       }

}







void Game::collison()
{

    int collisons=0;
    for(int i=0;i<MAX_ENEMY;i++)
       {
           if(mode!=MD_DEATH)
           {
               if(pEnemy[i]==NULL)continue;
               int Dx=0,Dy=0,fighterCL=0;
               Dx=abs((pFighter->left+pFighter->width/2)-(pEnemy[i]->left+pEnemy[i]->width/2));
               if(Dx<(pFighter->width/2+pEnemy[i]->width/2))
                  fighterCL++;
               Dy=abs((pFighter->top+pFighter->height/2)-(pEnemy[i]->top+pEnemy[i]->height/2));
               if(Dy<(pFighter->height/2+pEnemy[i]->height/2))
                  fighterCL++;
                if(fighterCL>=2)///////////death
                {
                   if(pEnemy[i]->type==TP_ENEMYBULLET)deleteEnemy(i);
                   else pEnemy[i]->explode();
                   int IsLose=pFighter->death();
                   if(IsLose==0)mode=MD_DEATH;
                   if(IsLose==-1)mode=MD_OVER;
                }
           }

           ////////enemy and our bullet
           for(int j=0;j<MAX_BULLET;j++)
           {
             if((pEnemy[i]!=NULL)&&(pBullet[j]!=NULL))
                {
                    if(pEnemy[i]->type==TP_EXPLODE)continue;
                    if(pEnemy[i]->type==TP_ENEMYBULLET)continue;
                    int dx,dy;
                    dx=abs((pBullet[j]->left+pBullet[j]->width/2)-(pEnemy[i]->left+pEnemy[i]->width/2));//
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

void Game::enemyShoot(int m)
{
    int nRand=CRand::GetRandomNumber3();
    if(nRand%40==6)developEnemy(TP_ENEMYBULLET,m);
    pEnemy[m]->nCount=60;
}
