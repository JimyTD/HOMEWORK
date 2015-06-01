#define WIDTH 800
#define HEIGHT 600
#define TP_BULLET 20
#define TP_ENEMY 30
#define TP_NORMAL 44
#define TP_BOSS 88
#define TP_BOMB 987
#define TP_EXPLODE 785
#define TP_ENEMYBULLET 826
#define MD_NORMAL 555
#define MD_DEATH 666
#define MD_OVER 777
#define WIDTH 800
#define HEIGHT 600
#include<windows.h>
#include <SFML/Graphics.hpp>
#include"Enemy.h"
#include"Fighter.h"
#include"FlyingObject.h"
#include"CTexture.h"
#include"Game.h"
#include<assert.h>


int main()
{
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Fighter!",sf::Style::Close);
    window.setFramerateLimit(60);
    mciSendString("open .\\music\\ring.wav alias ring", NULL, 0, NULL);
    //mciSendString("open .\\music\\bomb!.mp3 alias explode", NULL, 0, NULL);
    mciSendString("play ring", NULL, 0, NULL);
    CTexture pictures;
    pictures.load();
    Fighter a(360,500,60,66,0,&pictures);
    Game mainGame(&window,&pictures,MD_NORMAL);
    mainGame.SetFighter(&a);
    //Preparations.
    /////Entrance of event loop
    mainGame.Entrance();

    return 0;
}
