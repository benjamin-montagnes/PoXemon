#include "Player.h"

void Player::draw(sf::RenderWindow& target) {
    target.draw(sprite);
    health.draw(target);
    bullets.draw(target);
    if (health.health > 0) {
        bullets.bulletbar.draw(target);
        bullets.attacksbar.draw(target);
    }
}

void Player::draw(sf::RenderTexture& texture){
    texture.draw(sprite);
    //health.draw(texture);
    bullets.draw(texture);
}

void Player::update(float& deltaTime, sf::RenderWindow& window, sf::Clock& clock,
                sf::Time& elapsed, sf::Clock& clock1, sf::Clock& clock2, sf::Clock& clock3, float& groundY) {
                                    // Movement is dependant on time not on frame rate
                                    // This means that we can have smooth movement over multiple frames, instead of static movement per each frame
    velocityX = 0.0f;
    //Left and right movement
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left))||(sf::Keyboard::isKeyPressed(sf::Keyboard::A))) {
        velocityX -= speed;
    }
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right))||(sf::Keyboard::isKeyPressed(sf::Keyboard::D))) {
        velocityX += speed;
    }
    //Jumps
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && canJump)||(sf::Keyboard::isKeyPressed(sf::Keyboard::W) && canJump)) {
        canJump = false;       //While jumping you can't jump
        velocityY = -sqrt(2.0f * 981.0f * jumpHeight);
    }
    //Testing health - will change when we have collision recognition
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        health.setHealth(health.getHealth() - 1);
    }
    //Bullets: shooting
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        bullets.new_click(x,y,sprite.getGlobalBounds(), window, sf::Mouse::getPosition(window));
    }
    if (! sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        bullets.was_released = true;
    }
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))&&(bullets.attacksbar.attack1_available)){
        bullets.attack_type = 1;
        bullets.attacksbar.attack1_available = false;
        bullets.attacksbar.shooting1 = true;
        clock1.restart();
    }

    int i = bullets.update(window, deltaTime, clock, elapsed, clock1, clock2, clock3, (*enemy).sprite, groundY);
    if(i!=0){(*enemy).health.decrease(i+level);}

    collision_opponent();
    health.update();

    velocityY += 981.0f * deltaTime;
    move(deltaTime, window);
}

void Player::move(float& deltaTime, sf::RenderWindow& window) {
    x += velocityX * deltaTime;
    y += velocityY * deltaTime;
    if (y >= groundY) {
        y = groundY;
        velocityY = 0.0f;
        canJump = true;
    }
    if (x < sprite.getGlobalBounds().width/2){
        x = sprite.getGlobalBounds().width/2;
    }
    if (x > window.getSize().x -sprite.getGlobalBounds().width/2){
        x = window.getSize().x -sprite.getGlobalBounds().width/2;
    }

    update_sprite_orientation();
    sprite.setPosition(x, y);
}


void Player::collision_opponent() {
    if (Collision::PixelPerfectTest(sprite, (*enemy).sprite)) {
        //make it impossible for the pokemons to 'cross' each other
        velocityX *= -1;
    }
}


void Player::update_sprite_orientation() {

    if (x > (*enemy).x + 2*sprite.getGlobalBounds().width/3 && was_left) { // if player gets at the right of the oppenent
        //flip the sprites
        sprite.setScale(sf::Vector2f(Scale, Scale));
        (*enemy).sprite.setScale(sf::Vector2f(-enemy->Scale, enemy->Scale));
        was_left = false;
    }

    if (x + 2*sprite.getGlobalBounds().width/3 < (*enemy).x && !was_left){ //if player gets at the left of the opponent
        //flip the sprites
        sprite.setScale(sf::Vector2f(-Scale, Scale));
        (*enemy).sprite.setScale(sf::Vector2f(enemy->Scale, enemy->Scale));
        was_left = true;
    }
}


