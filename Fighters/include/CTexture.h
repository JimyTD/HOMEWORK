#ifndef CTEXTURE_H
#define CTEXTURE_H
#include <SFML/Graphics.hpp>
#include"FlyingObject.h"
class FlyingObject;
class CTexture
{
    public:
        CTexture();
        virtual ~CTexture();
        static sf::Texture pFighter;
        static sf::Texture pEnemy1;
        static sf::Texture pEnemy2;
        static sf::Texture pBullet;
        static sf::Texture pEBullet;
        static sf::Texture pBackground;
        static sf::Texture pBomb;
        static sf::Texture pOver;
        static sf::Texture pBigBomb;
        static sf::Texture pNewGame;
        static sf::Texture pShield;
        static sf::Texture pSTShield;
        static sf::Texture pSTBomb;
        static sf::Texture pSTAtk;
        static sf::Texture pSTSpd;
        static sf::Texture pSTHeal;
        static sf::Texture pSTScore;
        static sf::Texture pBoss;
        void load();
        int MagicPlay(FlyingObject *object);


    protected:
    private:
};

#endif // CTEXTURE_H
