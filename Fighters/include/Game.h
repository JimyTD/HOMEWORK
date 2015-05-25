#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include"FlyingObject.h"
#include"CTexture.h"
#include"Enemy.h"
#include"Fighter.h"
#include"Bullet.h"
/*GAME���ܿ��������̡�ע����ݼ�ʱ��ѭ������������ɡ������ƶ�����ײ����*/
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
