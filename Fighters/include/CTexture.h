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
        void load();
        int MagicPlay(FlyingObject *object);


    protected:
    private:
};

#endif // CTEXTURE_H
