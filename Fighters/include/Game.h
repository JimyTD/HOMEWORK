#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include"FlyingObject.h"
#include"CTexture.h"
#include"Enemy.h"
#include"Fighter.h"
#include"Bullet.h"
/*GAME类总控整个进程。注意根据计时器循环处理敌人生成、敌人移动、碰撞处理。*/
class CTexture;
class Game
{
    public:
        Game(sf::RenderWindow *window);
        virtual ~Game();
        void developEnemy();
        void Move();
        void collison();
        void Entrance();

    protected:
    private:
        sf::RenderWindow *pWindow;
        Fighter *pFighter;
        Bullet *pBullet;
        Enemy *pEnemy;
        int EnemyUsage;
        int BulletUsage;

};

#endif // GAME_H
