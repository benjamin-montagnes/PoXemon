#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>


//remarks / stuff to change
/*
We sould be able to throw a pokeball only if we have some in our backpack
We can only throw one pokeball at a time
When we throw one, the game should 'stop', until we know whether or not we caatch the opponent
Normally, the pokeball is not thrown by the pokemon but by the player
*/

class Pokeball {
public:
    float velocityX ;  //Set the speed of each of the pokeballs
    float ballHeight = 500;
    float velocityY;
    float x;
    float y;

    sf::Sprite ball;
    
    float gravity = 981.0f ;//This will make the parabolic trajectory
    float airfriction = 0.5;
    float coefimpact = 0.2;
    bool in_air;
    int bounce;
    
    void dissapear();
    void reset();
    
    void setPosition(float& xpos, float& ypos);
    int update(float deltaTime,sf::RenderWindow& window,float proba, sf::Clock &clock2, sf::Time &elapsed2,float opphealth);
    int catched(float proba, sf::Clock& clock, sf::Time& elapsed,float opphealth);
    bool waiting = false;

    
    Pokeball();
private:
    sf::Texture pic;
};

class Normalball: public Pokeball{
public:
    float proba;
    Normalball();
private:
    sf::Texture pic1;
};

class Superball: public Pokeball{
public:
    float proba;
    Superball();
private:
    sf::Texture pic2;
};

class Masterball: public Pokeball{
public:
    float proba;
    Masterball();
private:
    sf::Texture pic3;
};
