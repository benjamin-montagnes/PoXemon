#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
 #include "ResourcePath.hpp"
#include <unistd.h>
#include <stdio.h>
#include <iostream>
#include "tilemap.hpp"
#include "trainer.hpp"
#include "const.hpp"
#include "npc.hpp"
#include "map.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(544, 544), "Tilemap");
    sf::View view(sf::Vector2f(272, 272), sf::Vector2f(544, 544));
    view.zoom(0.7f);
    window.setPosition(sf::Vector2i(0, 0));
    

    Map map1(1);

    /* sf::Music music;
    if (!music.openFromFile(resourcePath() + "town_1.ogg")) {
        return EXIT_FAILURE;
    }
    music.play(); */


    //Variables for the character and declaration of him/ we need to put it in constructor
    float playerMovementSpeed = 4;
    int sheetRect = 64;
    int sizeAnim = 4;
    
    Trainer Arthur(playerMovementSpeed, sheetRect, sizeAnim);
    
    sf::Clock clock;
    
    window.setFramerateLimit(30);
    
    while (window.isOpen())
    {
        sf::Event event;
        window.pollEvent(event);
        if(event.type == sf::Event::Closed) window.close();
        
        
        sf::Time elapsed1 = clock.getElapsedTime();
        
        
        window.clear(sf::Color(112,200,160));     
        
        Arthur.displacement(event,view, collision);
        map1.draw(window, Arthur);

        window.setView(view);
        
        window.display();
    }

    return 0;
}

