#include <iostream>
#include <SFML/Graphics.hpp>
#include <memory>
#include <list>
#include "gold.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(1280, 720), L"Animation", sf::Style::Default);
    window.setFramerateLimit(60);

    sf::Texture background_texture;
    if(!background_texture.loadFromFile("assets/back.jpg")) {
        exit(1);
    }
    sf::Sprite background_sprite(background_texture);

    sf::Texture man_texture;
    if(!man_texture.loadFromFile("assets/man.png")) {
        exit(1);
    }
    sf::Sprite man_sprite(man_texture);

    sf::Texture gold_texture;
    if(!gold_texture.loadFromFile("assets/gold.png")) {
        exit(1);
    }
    sf::Sprite gold_sprite(gold_texture);

    sf::Font font;
    if(!font.loadFromFile("assets/ImpactRegular.ttf")) {
        exit(1);
    }
    sf::Text score_text;
    score_text.setFont(font);
    score_text.setPosition(100, 10);
    score_text.setOutlineColor(sf::Color::Black);
    score_text.setOutlineThickness(4);
    score_text.setCharacterSize(40);
    int score = 0;

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
                score++;
                continue;
            }
            gold_list_iterator++;
        }
        gold_list_iterator = gold_list.begin();

        man_sprite.setTextureRect(sf::IntRect(current_frame * 48, current_direction * 60, 48, 60));

        window.clear();

        score_text.setString("Gold: " + std::to_string(score));

        window.draw(background_sprite);
        while(gold_list_iterator != gold_list.end()) {
            gold_list_iterator->draw(window);
            gold_list_iterator++;
        }
        window.draw(man_sprite);
        window.draw(score_text);
        window.display();
    }
}