#include "Game.h"
#include"CRand.h"
#include"CTexture.h"
#include <SFML/Graphics.hpp>
#include<memory.h>
#include<math.h>
#include<windows.h>
#include<iostream>
#include<string>
using namespace std;
#define MAGIC_WIDTH 960
#define MAGIC_HEIGHT 768
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
#define OPEN 852
#define CLOSED 741
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
    New.setTexture(picture->pNewGame);
    score=0;
    font.loadFromFile("D:\\ProgramsOfTD\\C CPP HMWK\\Fighters\\Fonts\\Medhurst-regular.ttf");
    ScoreText.setFont(font);
    ScoreText.setCharacterSize(30);
    ScoreText.setStyle(sf::Text::Bold);
    ScoreText.setColor(sf::Color::Green);
    StuffText.setFont(font);
    StuffText.setCharacterSize(20);
    StuffText.setStyle(sf::Text::Bold);
    StuffText.setColor(sf::Color::Red);
    mode=nMode;
    shootCD=0;
    stage=1;
    Cheat=CLOSED;
    prCount=0;
    CRand::Prepare();
    shield=3;
    bomb=1;
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

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            if(pFighter->left>=10)pFighter->left-=pFighter->speed;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            if(pFighter->left+pFighter->width<=WIDTH-10)pFighter->left+=pFighter->speed;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            if(pFighter->top+pFighter->height<=HEIGHT-10)pFighter->top+=pFighter->speed;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            if(pFighter->top>=10)pFighter->top-=pFighter->speed;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            Shoot(TP_NORMAL);
        }

        while (pWindow->pollEvent(event))
            {

                if (event.type == sf::Event::Closed)//shutdown
                    {
                       pWindow->close();
                    }
                if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))
                {
                    if(Cheat==CLOSED)
                    {
                        Cheat=OPEN;
                        break;
                    }
                    if(Cheat==OPEN)
                    {
                        Cheat=CLOSED;
                        break;
                    }
                }
                if(mode==MD_NEWGAME)if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Return))
                {
                    clearAll();
                    mode=MD_NORMAL;
                    break;
                }
                if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Space))
                {
                    if(bomb>0)
                    {
                        Shoot(TP_MAGIC);
                        bomb--;
                    }
                }
            }
                ////////////////////////////key answering///////////////////////
                /////////////change stuffs//////////////////////
            if(mode!=MD_OVER&&mode!=MD_STAGEON)
            {
                if(stage==1)
                    if(score>=200)promotion();
                if(stage==2)
                    if(score>=500)promotion();
                int nRand=CRand::GetRandomNumber()%10;////new enemy
                if(nRand==1)
                {
                    developEnemy(TP_NORMAL);
                }
                if(shootCD>0)shootCD--;
                Move();
                if(mode!=MD_NEWGAME)collison();
                char sc[20];
                sprintf(sc,"Score:%d\nLife:%d\nStage:%d",score,pFighter->life,stage);
                ScoreText.setString(sc);
                sprintf(sc,"Shield:%d\nBigBomb:%d\n",shield,bomb);
                StuffText.setString(sc);
            }



                pWindow->clear();
     /////////////////////////Draw the stuffs.////////////////////////

           if(mode==MD_NORMAL||mode==MD_DEATH||mode==MD_NEWGAME)
           {
                if(mode!=MD_NEWGAME)pWindow->draw(Background);

                pFighter->setPosition(pFighter->left,pFighter->top);
                if(mode!=MD_NEWGAME)
                {
                    if(pFighter->nCount%10<=4)
                        pWindow->draw(*pFighter);
                    ////////
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
                }

                for(int i=0;i<MAX_ENEMY;i++)
                {


                    if(pBullet[i]!=NULL)
                    {
                        pBullet[i]->setPosition(pBullet[i]->left,pBullet[i]->top);
                        pWindow->draw(*(pBullet[i]));

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
                if(mode!=MD_NEWGAME)
                {
                    pWindow->draw(ScoreText);
                    StuffText.setPosition(0,500);
                    pWindow->draw(StuffText);
                }
                if(mode==MD_NEWGAME) pWindow->draw(New);
           }
        if(mode==MD_OVER)
            {
                pWindow->draw(Lose);
                pWindow->draw(ScoreText);
            }
        if(mode==MD_STAGEON)
            {
                ScoreText.setPosition(320,280);
                pWindow->draw(ScoreText);
                if(prCount>0)prCount--;
                if(prCount<=0)mode=MD_NORMAL;
                clearAll();
                ScoreText.setPosition(0,0);
            }








           //////////

            pWindow->display();
        }



}


void Game::Shoot(int nType)
{
    if(BulletUsage>MAX_BULLET-2)return;
    if(shootCD>0)return ;

    shootCD=20;
    for(int i=0;i<=99;i++)
       {
           if(pBullet[i]==NULL)
           {
               if(nType==TP_NORMAL)pBullet[i]=new Bullet(pFighter->left+pFighter->width/2-7,pFighter->top,14,30,10,picture,nType);
               if(nType==TP_MAGIC)pBullet[i]=new Bullet(pFighter->left+pFighter->width/2-MAGIC_WIDTH/5/2,pFighter->top-300,MAGIC_WIDTH/5*1.8,MAGIC_HEIGHT/4*1.8,0,picture,nType,120);
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
       int left=CRand::GetRandomNumber()%700;
       int speed=CRand::GetRandomNumber()%3+stage;
       for(int i=0;i<=MAX_ENEMY;i++)
       {
           if(pEnemy[i]==NULL)
           {
               pEnemy[i]=new Enemy(left,0,62,60,speed,picture,TP_NORMAL,speed-stage+1);
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
                       pEnemy[i]=new Enemy(pEnemy[m]->left+pEnemy[m]->width/2-5,pEnemy[m]->top+pEnemy[m]->height,12,25,4,picture,TP_ENEMYBULLET,0);
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
               if(pBullet[j]->type==TP_MAGIC)
               {
                   if(pBullet[j]->nCount>0)
                   {
                       picture->MagicPlay(pBullet[j]);//(*FlyingObject)(pBullet[j])
                       rectExplosion(pBullet[j]->left+pBullet[j]->width/2,pBullet[j]->top+pBullet[j]->height/2,pBullet[j]->width,pBullet[j]->height);
                       if(pBullet[j]->nCount<=0)
                       {
                           deleteBullet(j);
                           continue;
                       }
                   }
               }
               if((pBullet[j]->top)<0)
               {
                   if(pBullet[j]->type!=TP_MAGIC)deleteBullet(j);
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

           if(pEnemy[i]==NULL)continue;
           int Dx=0,Dy=0,fighterCL=0;
           Dx=abs((pFighter->left+pFighter->width/2)-(pEnemy[i]->left+pEnemy[i]->width/2));
           if(Dx<(pFighter->width/2+pEnemy[i]->width/2))
              fighterCL++;
           Dy=abs((pFighter->top+pFighter->height/2)-(pEnemy[i]->top+pEnemy[i]->height/2));
           if(Dy<(pFighter->height/2+pEnemy[i]->height/2))
              fighterCL++;
            if(fighterCL>=2&&pEnemy[i]->type!=TP_EXPLODE)///////////death
            {

               if(pEnemy[i]->type==TP_ENEMYBULLET)
               {
                   deleteEnemy(i);
               }
               else
               {
                   addScore(pEnemy[i]->score);
                   pEnemy[i]->explode();
               }
               if(mode!=MD_DEATH&&Cheat!=OPEN)
                {
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
                    if(pBullet[j]->type==TP_MAGIC)continue;
                    int dx,dy;
                    dx=abs((pBullet[j]->left+pBullet[j]->width/2)-(pEnemy[i]->left+pEnemy[i]->width/2));//
                    if(dx<(pBullet[j]->width/2+pEnemy[i]->width/2))
                        collisons++;
                    dy=abs((pBullet[j]->top+pBullet[j]->height/2)-(pEnemy[i]->top+pEnemy[i]->height/2));
                    if(dy<(pBullet[j]->height/2+pEnemy[i]->height/2))
                        collisons++;
                    if(collisons>=2)
                    {
                        addScore(pEnemy[i]->score);
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
    if(nRand%8==6)developEnemy(TP_ENEMYBULLET,m);
    pEnemy[m]->nCount=60;
}

void Game::clearAll()
{
    for(int i=0;i<MAX_ENEMY;i++)
        if(pEnemy[i]!=NULL)
            delete(pEnemy[i]);
    for(int i=0;i<MAX_BULLET;i++)
        if(pBullet[i]!=NULL)
            delete(pBullet[i]);
    memset(pEnemy,NULL,MAX_ENEMY*sizeof(Enemy*));
    memset(pBullet,NULL,MAX_BULLET*sizeof(Bullet*));

}


void Game::rectExplosion(int heartx,int hearty,int width,int height)
{
     int collisons=0;
     for(int i=0;i<MAX_ENEMY;i++)
           {
             if(pEnemy[i]!=NULL)
                {
                    if(pEnemy[i]->type==TP_EXPLODE)continue;
                    //if(pEnemy[i]->type==TP_ENEMYBULLET)continue;
                    int dx,dy;
                    dx=abs(heartx-(pEnemy[i]->left+pEnemy[i]->width/2));//
                    if(dx<(width/2+pEnemy[i]->width/2))
                        collisons++;
                    dy=abs(hearty-(pEnemy[i]->top+pEnemy[i]->height/2));
                    if(dy<height/2+(pEnemy[i]->height/2))
                        collisons++;
                    if(collisons>=2)
                    {
                        std::cout<<collisons;
                        addScore(pEnemy[i]->score);
                        pEnemy[i]->explode();
                    }
                    collisons=0;
                }
           }

}
