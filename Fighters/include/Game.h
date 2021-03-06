#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include"FlyingObject.h"
#include"CTexture.h"
#include"Enemy.h"
#include"Fighter.h"
#include"Bullet.h"
#include"Stuff.h"
#define MAX_BULLET 100
#define MAX_ENEMY 120
#define MAX_STUFF 100
#define MD_NORMAL 555
#define MD_SHIELD 666
#define MD_OVER 777
#define MD_STAGEON 856
#define MD_NEWGAME 773
#define TP_BULLET 20
#define TP_ENEMY 30
#define TP_NORMAL 44
#define TP_BOSS 88
#define TP_BOMB 987
#define TP_EXPLODE 785
#define TP_ENEMYBULLET 826
/*GAME类总控整个进程。注意根据计时器循环处理敌人生成、敌人移动、碰撞处理。*/
class CTexture;
class Stuff;
class Game
{
    public:
        Game(sf::RenderWindow *window,CTexture *picture,int nMode);
        virtual ~Game();
        void developEnemy(int type,int m=0);
        void deleteEnemy(int i)
        {
            delete(pEnemy[i]);
            pEnemy[i]=NULL;
            EnemyUsage--;
        }
        void deleteBullet(int i)
        {
            delete(pBullet[i]);
            pBullet[i]=NULL;
            BulletUsage--;
        }
        void deleteStuff(int i)
        {
            delete(pStuff[i]);
            pStuff[i]=NULL;
            StuffUsage--;
        }
        void Move();
        void collison();
        void Entrance();
	    void Shoot(int nType);
	    void SetFighter(Fighter *p)
	    {
	        pFighter=p;
	    }
	    void addScore(int num)
	    {
	        score+=num;
	    }
	    void enemyShoot(int m);
	    void GameOver()
	    {
            mode=MD_OVER;
	    }
	    void promotion()
	    {
	        stage++;
	        mode=MD_STAGEON;
	        prCount=240;
	    }
	    void clearAll();
	    void getShield()
	    {
	        shield++;
	    }
	    void getBigBomb()
	    {
	        bomb++;
	    }
	    void rectExplosion(int heartx,int hearty,int width,int height);
	    void Shield();
	    void DropStuff(int heartx,int hearty);
	    int maxSCD;


    protected:
    private:
        sf::RenderWindow *pWindow;
        Fighter *pFighter;
        Bullet *pBullet[MAX_BULLET];
        Enemy *pEnemy[MAX_ENEMY];
        Stuff *pStuff[MAX_STUFF];
        int EnemyUsage;
        int BulletUsage;
        int StuffUsage;
        CTexture *picture;
        sf::Sprite Background;
        sf::Sprite Lose;
        sf::Sprite New;
        int score;
        sf::Font font;
        sf::Text ScoreText;
        sf::Text StuffText;
        int mode;
        int shootCD;
        int stage;
        int Cheat;
        int prCount;
        int shield;
        int bomb;



};

#endif // GAME_H
