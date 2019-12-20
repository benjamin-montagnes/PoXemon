#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include "Player.h"

class StateFunctions1 {
public:
    void initialise_background(sf::RenderWindow& window, std::string path, sf::Sprite& background, sf::Texture& texture);
    void initialise_buttons(sf::RectangleShape& start_button, sf::RectangleShape& info_button, sf::RenderWindow& window, sf::Font& font, sf::Text& start_text,
                            sf::Text& info_text, sf::Text& intro_text, sf::Sprite& opp, sf::Sprite& star, sf::Texture& star_texture);
    void draw1(sf::RenderWindow& window, sf::RectangleShape& shape1, sf::RectangleShape& shape2, sf::Text& text1, sf::Text& text2,
            sf::Text& text3, sf::Sprite& sprite, sf::Sprite& bg );
    int update_state1(sf::RenderWindow& window, sf::RectangleShape& start_button, sf::RectangleShape& info_button, sf::Sprite& star);
};

class StateFunctions56 {
public:
    void fall(Pokemon& eevee, float& groundY, float& deltaTime);
    void initialize_state_5_6(char game_mode, Pokemon poke, sf::Font font, sf::Text& text_fainted, sf::Text& choose_pokemon, sf::Text& leave_fight, 
        sf::RenderWindow& target, Pokemon_Button* buttons[], sf::Sprite& running_sprite);
    void const draw_state_5_6(char game_mode,  sf::Font& font, sf::Text& text_fainted, sf::Text choose_pokemon, sf::Text leave_fight, 
        sf::RenderWindow& target, Pokemon_Button* buttons[], sf::Sprite& running_sprite);
    void update_state_5_6(char game_mode, sf::RenderWindow& window, Pokemon_Button* buttons[], int& clicked_button, sf::Sprite& running_sprite );
    void initialize_state7(bool won, sf::Text& lost_fight, sf::Font& font, sf::RenderWindow& window);
    void initialize_state_8(Pokemon& poke, sf::Font& font, sf::Text& text_fainted, sf::RenderWindow& window);

};