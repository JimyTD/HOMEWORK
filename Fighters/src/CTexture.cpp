#include "CTexture.h"
#include <SFML/Graphics.hpp>
sf::Texture CTexture::pFighter;
sf::Texture CTexture::pEnemy1;
sf::Texture CTexture::pEnemy2;
sf::Texture CTexture::pBullet;
sf::Texture CTexture::pBackground;
sf::Texture CTexture::pBomb;
CTexture::CTexture()
{
    //ctor
}

CTexture::~CTexture()
{
    //dtor
}

void CTexture::load()
{
    this->pFighter.loadFromFile("D:\\ProgramsOfTD\\C CPP HMWK\\Fighters\\Pictures\\Fighter1.png");
    this->pEnemy1.loadFromFile("D:\\ProgramsOfTD\\C CPP HMWK\\Fighters\\Pictures\\Enemy3.png");
    this->pBullet.loadFromFile("D:\\ProgramsOfTD\\C CPP HMWK\\Fighters\\Pictures\\Bullet.png");
    this->pBomb.loadFromFile("D:\\ProgramsOfTD\\C CPP HMWK\\Fighters\\Pictures\\bomb.png");
    this->pBackground.loadFromFile("D:\\ProgramsOfTD\\C CPP HMWK\\Fighters\\Pictures\\bkground1.png");
}
