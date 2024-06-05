#include <iostream>
#include <SFML/Graphics.hpp>
#include <memory>
#include <list>
#include "gold.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(1280, 720), L"Animation", sf::Style::Default);
    window.setFramerateLimit(60);

    sf::Texture background_texture;
    background_texture.loadFromFile("assets/back.jpg");
    sf::Sprite background_sprite(background_texture);

    sf::Texture man_texture;
    man_texture.loadFromFile("assets/man.png");
    sf::Sprite man_sprite(man_texture);

    sf::Texture gold_texture;
    gold_texture.loadFromFile("assets/gold.png");
    sf::Sprite gold_sprite(gold_texture);

    std::list<Gold> gold_list;

    int man_x = 100;
    int man_y = 650;

    int current_frame = 0;
    int current_direction = 0;

    sf::Clock clock;
    sf::Time dt;
    float gold_time = 0;

    srand(time(nullptr));

    while(window.isOpen()) {
        auto gold_list_iterator = gold_list.begin();
        dt = clock.getElapsedTime();
        clock.restart();
        float t = dt.asSeconds();
        gold_time += t;
        man_sprite.setPosition(man_x, man_y);
        sf::Event event;
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed) {
                window.close();
            }
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            window.close();
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            man_x += 10;
            current_frame = (current_frame + 1) % 10;
            current_direction = 0;
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            current_frame = (current_frame + 1) % 10;
            man_y -= 10;
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            current_frame = (current_frame + 1) % 10;
            man_y += 10;
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            man_x -= 10;
            current_frame = (current_frame + 1) % 10;
            current_direction = 1;
        }

        if(man_y < 0) {
            man_y = 0;
        }
        if(man_y > 650) {
            man_y = 650;
        }
 
        if(man_x < 5) {
            man_x = 5;
        }         
        if(man_x > 1230) {
            man_x = 1230;
        } 

        if(gold_time > 1.0) {
            int gold_x = rand() % 1200;
            int gold_y = rand() % 650;
            Gold gold(gold_x, gold_y);
            gold.setSprite(gold_sprite);
            gold_list.push_back(std::move(gold));
            gold_time = 0.0;
        }

        while(gold_list_iterator != gold_list.end()) {
            if(man_sprite.getGlobalBounds().intersects(gold_list_iterator->getBounds())) {
                gold_list_iterator = gold_list.erase(gold_list_iterator);
                continue;
            }
            gold_list_iterator++;
        }
        gold_list_iterator = gold_list.begin();

        man_sprite.setTextureRect(sf::IntRect(current_frame * 48, current_direction * 60, 48, 60));

        window.clear();

        window.draw(background_sprite);
        while(gold_list_iterator != gold_list.end()) {
            gold_list_iterator->draw(window);
            gold_list_iterator++;
        }
        window.draw(man_sprite);
        window.display();
    }
}