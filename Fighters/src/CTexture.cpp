#include "CTexture.h"
#include <SFML/Graphics.hpp>
sf::Texture CTexture::pFighter;
sf::Texture CTexture::pEnemy1;
sf::Texture CTexture::pEnemy2;
sf::Texture CTexture::pEnemy3;
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
    this->pFighter.loadFromFile("D:\\ProgramsOfTD\\À×µçÍ¼Æ¬ËØ²Ä\\y0224bo04s.png");
}
