#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include"FlyingObject.h"
#include"CTexture.h"
#include"Enemy.h"
#include"Fighter.h"
#include"Bullet.h"
#define MAX_BULLET 100
#define MAX_ENEMY 120
/*GAME类总控整个进程。注意根据计时器循环处理敌人生成、敌人移动、碰撞处理。*/
class CTexture;
class Game
{
    public:
        Game(sf::RenderWindow *window,CTexture *picture);
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
        void Move();
        void collison();
        void Entrance();
	    void Shoot();
	    void SetFighter(Fighter *p)
	    {
	        pFighter=p;
	    }
	    void addScore(int num)
	    {
	        score+=num;
	    }
	    void enemyShoot(int m);

    protected:
    private:
        sf::RenderWindow *pWindow;
        Fighter *pFighter;
        Bullet *pBullet[MAX_BULLET];
        Enemy *pEnemy[MAX_ENEMY];
        int EnemyUsage;
        int BulletUsage;
        CTexture *picture;
        sf::Sprite Background;
        int score;
        sf::Font font;
        sf::Text ScoreText;

};

#endif // GAME_H
