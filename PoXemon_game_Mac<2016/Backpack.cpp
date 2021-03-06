#include "Backpack.h"
#include<map>
#include<string>
#include<cmath>


Backpack::Backpack(){
    dict_pokeball["Normalball"] = 0;
    dict_pokeball["Superball"] = 0;
    dict_pokeball["Masterball"] = 0;


    bool masternow = true;
    bool supernow = true;
    bool normalnow = true;

// //creates a box with nothing inside
//    //Outline with white base
//    clickbox.setFillColor(sf::Color::White);
//    clickbox.setOutlineThickness(4);
//    clickbox.setOutlineColor(sf::Color::Black);
//    clickbox.setSize(sf::Vector2f(100,40));
//    clickbox.setPosition(50,100);

    normaltext1.loadFromFile("Images/pokeball.png");
    normalball.setTexture(normaltext1);
    normalball.setScale(sf::Vector2f(0.2f, 0.2f));
//    normalball.setScale(sf::Vector2f(0.4f, 0.4f));
    normalball.setPosition(70,150);
//    normalball.setPosition(140,300);

    normaltext2.loadFromFile("Images/superball.png");
    superball.setTexture(normaltext2);
    superball.setScale(sf::Vector2f(0.2f, 0.2f));
//    superball.setScale(sf::Vector2f(0.4f, 0.4f));
    superball.setPosition(120,150);
//    superball.setPosition(240,300);

    normaltext3.loadFromFile("Images/masterball.png");
    masterball.setTexture(normaltext3);
    masterball.setScale(sf::Vector2f(0.055f, 0.055f));
//    masterball.setScale(sf::Vector2f(0.110f, 0.110f));
    masterball.setPosition(170,150);
//    masterball.setPosition(340,300);

    new_Superball.ball.setPosition(150,150);
}

Backpack::~Backpack(){
    for (int i=0; i<3; i++){
        if (backpack_pokemons[i]){
            delete backpack_pokemons[i];
        }
    }
}

void Backpack::setBackpack(int i){ //Some standard backpacks
    bag_number = i;
    if(i==1){ //First opponent;
        std::string name1 = "jistolwer";
        std::string name2 = "auron";
        std::string name3 = "pulple";
        Backpack_Pokemon* poke1 = new Backpack_Pokemon(name1, 1, 0, 50, 20);
        Backpack_Pokemon* poke2 = new Backpack_Pokemon(name2, 1, 1, 60, 20);
        Backpack_Pokemon* poke3 = new Backpack_Pokemon(name3, 1, 2, 70, 30);
        backpack_pokemons[0] = poke1;
        backpack_pokemons[1] = poke2;
        backpack_pokemons[2] = poke3;
        
    }
    if(i==2){ //Fire Pokemons for underground trainer;
        std::string name1 = "poras";
        std::string name2 = "arfau";
        std::string name3 = "lowtor";
        Backpack_Pokemon* poke1 = new Backpack_Pokemon(name1, 13, 0, 100, 40);
        Backpack_Pokemon* poke2 = new Backpack_Pokemon(name2, 14, 1, 100, 40);
        Backpack_Pokemon* poke3 = new Backpack_Pokemon(name3, 15, 2, 100, 40);
        backpack_pokemons[0] = poke1;
        backpack_pokemons[1] = poke2;
        backpack_pokemons[2] = poke3;
        
    }

    if(i==3){ //Mixed for Clement trainer;
        std::string name1 = "wapefet";
        std::string name2 = "sandlax";
        std::string name3 = "auron";
        Backpack_Pokemon* poke1 = new Backpack_Pokemon(name1, 1, 0, 100, 30);
        Backpack_Pokemon* poke2 = new Backpack_Pokemon(name2, 1, 1, 100, 10);
        Backpack_Pokemon* poke3 = new Backpack_Pokemon(name3, 1, 2, 100, 20);
        backpack_pokemons[0] = poke1;
        backpack_pokemons[1] = poke2;
        backpack_pokemons[2] = poke3;
        
    }

    if(i==4){ //For the ref.
        std::string name1 = "abata";
        std::string name2 = "golnite";
        std::string name3 = "pikalee";
        Backpack_Pokemon* poke1 = new Backpack_Pokemon(name1, 1, 0, 100, 30);
        Backpack_Pokemon* poke2 = new Backpack_Pokemon(name2, 1, 1, 100, 20);
        Backpack_Pokemon* poke3 = new Backpack_Pokemon(name3, 1, 2, 100, 40);
        backpack_pokemons[0] = poke1;
        backpack_pokemons[1] = poke2;
        backpack_pokemons[2] = poke3;
        
    }
    if(i==5){ //For Julien
        std::string name1 = "twobee";
        std::string name2 = "rodritata";
        std::string name3 = "rabloni";
        Backpack_Pokemon* poke1 = new Backpack_Pokemon(name1, 1, 0, 100, 30);
        Backpack_Pokemon* poke2 = new Backpack_Pokemon(name2, 1, 1, 100, 20);
        Backpack_Pokemon* poke3 = new Backpack_Pokemon(name3, 100, 2, 100, 40);
        backpack_pokemons[0] = poke1;
        backpack_pokemons[1] = poke2;
        backpack_pokemons[2] = poke3;
        
    }
}

void Backpack::set_opponent(Opponent* opponent) {
    this->opponent = opponent;
}

ReturnValue Backpack::Pokeball_shoot(float& deltaTime, sf::RenderWindow& window, sf::Clock &clock2, sf::Time & elapsed2){ // returns 0 if nothing,
    value.string = "None";
    float health_opponent = opponent->health.health;

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)&&(dict_pokeball["Normalball"]>0)&&new_Normalball.in_air ==false&&new_Superball.in_air ==false&&new_Masterball.in_air ==false){
        
        //Get the mouse position:
        sf::Vector2i mousepixel = sf::Mouse::getPosition(window);
        sf::Vector2f mouse_pos = window.mapPixelToCoords(mousepixel);

//        std::cout<<mouse_pos.x<<", "<<mouse_pos.y<<std::endl;
        //corresponds to the pokeball icon on the screen
        if((mouse_pos.x>140)&&(mouse_pos.x<180)&&(mouse_pos.y>280)&&(mouse_pos.y<330)){ //a changer avec les valeurs sur github
//        if((mouse_pos.x>140)&&(mouse_pos.x<180)&&(mouse_pos.y>300)&&(mouse_pos.y<380)){

            dict_pokeball["Normalball"]-=1;
            value.string = "Normalball";

            sf::Vector2u size = window.getSize();
            float w = size.x;
            float width = (float) w;
            float h = size.y;
            float height = (float) h + 2.0f;
            float width4 = width/5;


            new_Normalball.setPosition(width4, height);// Need to figure out where the starting x and y position are
            new_Normalball.velocityY = 1.2*-sqrt(5.0f * 981.0f * new_Normalball.ballHeight); //We need to reset the ball's position and starting speed when you shoot, that's why its in this class
            new_Normalball.velocityX = 1.4*500;
            new_Normalball.in_air = true;

        }
    }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)&&(dict_pokeball["Superball"]>0)&&new_Superball.in_air ==false&&new_Normalball.in_air ==false&&new_Masterball.in_air ==false){

                            //Get the mouse position:
                            sf::Vector2i mousepixel = sf::Mouse::getPosition(window);
                            sf::Vector2f mouse_pos = window.mapPixelToCoords(mousepixel);

                            //corresponds to the pokeball icon on the screen
                            if((mouse_pos.x>250)&&(mouse_pos.x<305)&&(mouse_pos.y>300)&&(mouse_pos.y<380)){


                            dict_pokeball["Superball"]-=1;
                            value.string = "Superball";

                            sf::Vector2u size = window.getSize();
                            float w = size.x;
                            float width = (float) w;
                            float h = size.y;
                            float height = (float) h + 2.0f;
                            float width4 = width/5;


                            new_Superball.setPosition(width4, height);// Need to figure out where the starting x and y position are
                            new_Superball.velocityY = 1.2*-sqrt(5.0f * 981.0f * new_Superball.ballHeight);//We need to reset the ball's position and starting speed when you shoot, that's why its in this class
                            new_Superball.velocityX = 1.4*500;
                            new_Superball.in_air = true;
                    }


        }
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)&&(dict_pokeball["Masterball"]>0)&&new_Normalball.in_air ==false && new_Superball.in_air ==false && new_Masterball.in_air ==false){

                                //Get the mouse position:
                                sf::Vector2i mousepixel = sf::Mouse::getPosition(window);
                                sf::Vector2f mouse_pos = window.mapPixelToCoords(mousepixel);

                                //corresponds to the pokeball icon on the screen
                                if((mouse_pos.x>340)&&(mouse_pos.x<400)&&(mouse_pos.y>300)&&(mouse_pos.y<380)){


                                dict_pokeball["Masterball"]-=1;
                                value.string = "Masterball";

                                sf::Vector2u size = window.getSize();
                                float w = size.x;
                                float width = (float) w;
                                float h = size.y;
                                float height = (float) h + 2.0f;
                                float width4 = width/5;


                                new_Masterball.setPosition(width4, height);// Need to figure out where the starting x and y position are
                                new_Masterball.velocityY = 1.2*-sqrt(5.0f * 981.0f * new_Masterball.ballHeight); //We need to reset the ball's position and starting speed when you shoot, that's why its in this class
                                new_Masterball.velocityX = 1.4*500;
                                new_Masterball.in_air = true;
                        }


            }


    //Continuation of the one shot as time goes by
    if (new_Normalball.in_air) {
        int catched = new_Normalball.update(deltaTime, window, new_Normalball.proba, clock2, elapsed2, health_opponent);
            //bool still_on_screen = new_Normalball.update(deltaTime, window,new_Normalball.proba, clock2, elapsed2,health_opponent);
        if(new_Normalball.waiting == false){
            new_Normalball.ball.setOrigin(100, 100);//I suppose (100,100) is close to the center of the sprite before rescaling
            new_Normalball.ball.rotate(12*3.0f);
        }
        else{
            new_Normalball.ball.setRotation(0);
        }
            if (catched == 1 || catched == 2) {
                        value.i = catched;
                        return value;
            }
    }
    //Continuation of the one shot as time goes by
    if (new_Superball.in_air) {
            int catched = new_Superball.update(deltaTime, window,new_Superball.proba, clock2, elapsed2,health_opponent);
                if(new_Superball.waiting == false){
                    new_Superball.ball.setOrigin(100, 100);//I suppose (100,100) is close to the center of the sprite before rescaling
                    new_Superball.ball.rotate(12*3.0f);
                }
                else{
                    new_Superball.ball.setRotation(0);
                }
                //if the ball reached the end of the window, then the ball is not in air
            if (catched == 1 || catched == 2) {
                        //new_Superball.in_air = false;
                        value.i = catched;
                        return value;
            }
    }
    //Continuation of the one shot as time goes by
    if (new_Masterball.in_air) {
            int catched = new_Masterball.update(deltaTime, window,new_Masterball.proba, clock2, elapsed2,health_opponent);
                if(new_Masterball.waiting == false){
                    new_Masterball.ball.setOrigin(310, 310);//I suppose (310,310) is close to the center of the sprite before rescaling
                    new_Masterball.ball.rotate(12*3.0f);
                }
                else{
                    new_Masterball.ball.setRotation(0);
                }
                //if the ball reached the end of the window, then the ball is not in air
                if (catched == 1 || catched == 2) {
                    //new_Masterball.in_air = false;
                    value.i = catched;
                    return value;
                }
    }
    value.i = 0;
    return value;
}

void Backpack::draw(sf::RenderWindow &target) const {

    if(new_Normalball.in_air){
        target.draw(new_Normalball.ball);
    }
    if(new_Superball.in_air){
        target.draw(new_Superball.ball);
    }
    if(new_Masterball.in_air){
        target.draw(new_Masterball.ball);
    }

    target.draw(clickbox);
    if (dict_pokeball.find("Normalball")->second >0){target.draw(normalball);}
    if (dict_pokeball.find("Superball")->second >0){target.draw(superball);}
    if (dict_pokeball.find("Masterball")->second >0){target.draw(masterball);}
}

void Backpack::draw(sf::RenderTexture& texture) const {

    //don't need
}

bool Backpack::alive_pokemons() {
    for (int i = 0; i < 3; i++) {
        if (backpack_pokemons[i]) {
            if (backpack_pokemons[i]->health > 0) {
                return true;
            }
        }
    }
    return false;
}

void Backpack::reset(){
    new_Masterball.reset();
    new_Normalball.reset();
    new_Superball.reset();
}
