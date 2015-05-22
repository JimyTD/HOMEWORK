#define WIDTH 800
#define HEIGHT 600
#include<windows.h>
#include <SFML/Graphics.hpp>
#include"Enemy.h"
#include"Fighter.h"
#include"FlyingObject.h"
#include"CTexture.h"


int main()
{
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Fighter!");
    mciSendString("open .\\music\\ring.wav alias ring", NULL, 0, NULL);
    mciSendString("play ring", NULL, 0, NULL);
    while (window.isOpen())
    {
       sf::Event event;
       CTexture pictures;
       pictures.load();
       //≥ı ºªØ!
       Fighter a(360,500,0,0,pictures);

       a.setTexture(pictures.pFighter,true);
       a.setTextureRect(sf::IntRect(29,27,60,66));
       a.setPosition(360,500);
      /////
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

        }

        window.clear();
        window.draw(a);
        window.display();
    }

    return 0;
}
