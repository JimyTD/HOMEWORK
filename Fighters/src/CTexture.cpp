#include "CTexture.h"
#include <SFML/Graphics.hpp>
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

sf::Texture CTexture::pFighter;
sf::Texture CTexture::pEnemy1;
sf::Texture CTexture::pEnemy2;
sf::Texture CTexture::pBullet;
sf::Texture CTexture::pEBullet;
sf::Texture CTexture::pBackground;
sf::Texture CTexture::pBomb;
sf::Texture CTexture::pOver;
sf::Texture CTexture::pBigBomb;
sf::Texture CTexture::pNewGame;
sf::Texture CTexture::pShield;
sf::Texture CTexture::pSTShield;
sf::Texture CTexture::pSTBomb;
sf::Texture CTexture::pSTAtk;
sf::Texture CTexture::pSTSpd;
sf::Texture CTexture::pSTHeal;
sf::Texture CTexture::pSTScore;

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
    this->pEBullet.loadFromFile("D:\\ProgramsOfTD\\C CPP HMWK\\Fighters\\Pictures\\ENEMYBULLET.png");
    this->pOver.loadFromFile("D:\\ProgramsOfTD\\C CPP HMWK\\Fighters\\Pictures\\gg.png");
    this->pBigBomb.loadFromFile("D:\\ProgramsOfTD\\C CPP HMWK\\Fighters\\Pictures\\BigBomb.png");
    this->pNewGame.loadFromFile("D:\\ProgramsOfTD\\C CPP HMWK\\Fighters\\Pictures\\NEWGAME.png");
    this->pShield.loadFromFile("D:\\ProgramsOfTD\\C CPP HMWK\\Fighters\\Pictures\\fighter1_shield.png");
    this->pSTShield.loadFromFile("D:\\ProgramsOfTD\\C CPP HMWK\\Fighters\\Pictures\\shield.png");
    this->pSTBomb.loadFromFile("D:\\ProgramsOfTD\\C CPP HMWK\\Fighters\\Pictures\\GetBomb.png");
    this->pSTScore.loadFromFile("D:\\ProgramsOfTD\\C CPP HMWK\\Fighters\\Pictures\\score.png");
    this->pSTAtk.loadFromFile("D:\\ProgramsOfTD\\C CPP HMWK\\Fighters\\Pictures\\atk+.png");
    this->pSTSpd.loadFromFile("D:\\ProgramsOfTD\\C CPP HMWK\\Fighters\\Pictures\\speed.png");
    this->pSTHeal.loadFromFile("D:\\ProgramsOfTD\\C CPP HMWK\\Fighters\\Pictures\\heal.png");

}

int CTexture::MagicPlay(FlyingObject *object)
{
	switch(object->nCount%15)
	{
	case 14:
		{
            object->setTextureRect(sf::IntRect(0,0,MAGIC_WIDTH/5,MAGIC_HEIGHT/4));
            object->setScale(1.5,1.5);
            object->nCount--;
        	break;
		}
	case 13:
		{
            object->setTextureRect(sf::IntRect(MAGIC_WIDTH/5,0,MAGIC_WIDTH/5,MAGIC_HEIGHT/4));
            object->setScale(1.5,1.5);
            object->nCount--;
			break;
		}
	case 12:
		{
            object->setTextureRect(sf::IntRect(MAGIC_WIDTH/5*2,0,MAGIC_WIDTH/5,MAGIC_HEIGHT/4));
            object->setScale(1.5,1.5);
            object->nCount--;
			break;
		}
	case 11:
		{
            object->setTextureRect(sf::IntRect(MAGIC_WIDTH/5*3,0,MAGIC_WIDTH/5,MAGIC_HEIGHT/4));
            object->setScale(1.5,1.5);
            object->nCount--;
			break;
		}
	case 10:
		{

			object->setTextureRect(sf::IntRect(MAGIC_WIDTH/5*4,0,MAGIC_WIDTH/5,MAGIC_HEIGHT/4));
            object->setScale(1.5,1.5);
            object->nCount--;
			break;
		}
	case 9:
		{

			object->setTextureRect(sf::IntRect(0,MAGIC_HEIGHT/4,MAGIC_WIDTH/5,MAGIC_HEIGHT/4));
            object->setScale(1.5,1.5);
            object->nCount--;
			break;
		}
	case 8:
		{

			object->setTextureRect(sf::IntRect(MAGIC_WIDTH/5,MAGIC_HEIGHT/4,MAGIC_WIDTH/5,MAGIC_HEIGHT/4));
            object->setScale(1.5,1.5);
            object->nCount--;
			break;
		}
	case 7:
		{

			object->setTextureRect(sf::IntRect(MAGIC_WIDTH/5*2,MAGIC_HEIGHT/4,MAGIC_WIDTH/5,MAGIC_HEIGHT/4));
            object->setScale(1.5,1.5);
            object->nCount--;
			break;
		}
	case 6:
		{

			object->setTextureRect(sf::IntRect(MAGIC_WIDTH/5*3,MAGIC_HEIGHT/4,MAGIC_WIDTH/5,MAGIC_HEIGHT/4));
            object->setScale(1.5,1.5);
            object->nCount--;
			break;
		}
	case 5:
		{

			object->setTextureRect(sf::IntRect(MAGIC_WIDTH/5*4,MAGIC_HEIGHT/4,MAGIC_WIDTH/5,MAGIC_HEIGHT/4));
            object->setScale(1.5,1.5);
            object->nCount--;
			break;
		}
	case 4:
		{

			object->setTextureRect(sf::IntRect(0,MAGIC_HEIGHT/4*2,MAGIC_WIDTH/5,MAGIC_HEIGHT/4));
            object->setScale(1.5,1.5);
            object->nCount--;
			break;
		}
	case 3:
		{

			object->setTextureRect(sf::IntRect(MAGIC_WIDTH/5,MAGIC_HEIGHT/4*2,MAGIC_WIDTH/5,MAGIC_HEIGHT/4));
            object->setScale(1.5,1.5);
            object->nCount--;
			break;
		}
	case 2:
		{

			object->setTextureRect(sf::IntRect(MAGIC_WIDTH/5*2,MAGIC_HEIGHT/4*2,MAGIC_WIDTH/5,MAGIC_HEIGHT/4));
            object->setScale(1.5,1.5);
            object->nCount--;
			break;
		}
	case 1:
		{

			object->setTextureRect(sf::IntRect(MAGIC_WIDTH/5*3,MAGIC_HEIGHT/4*2,MAGIC_WIDTH/5,MAGIC_HEIGHT/4));
            object->setScale(1.5,1.5);
            object->nCount--;
			break;
		}
	case 0:
		{

			object->setTextureRect(sf::IntRect(MAGIC_WIDTH/5*4,MAGIC_HEIGHT/4*2,MAGIC_WIDTH/5,MAGIC_HEIGHT/4));
            object->setScale(1.5,1.5);
            object->nCount--;
			break;
		}
	}
		object->setScale(1.8,1.8);
		return 0;
}
