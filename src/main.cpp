#include <iostream>
#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Animation");
    window.setFramerateLimit(60);

    sf::Texture background_texture;
    background_texture.loadFromFile("assets/back.jpg");
    sf::Sprite background_sprite(background_texture);

    sf::Texture man_texture;
    man_texture.loadFromFile("assets/man.png");
    sf::Sprite man_sprite;
    man_sprite.setTexture(man_texture);

    int man_x = 100;
    int man_y = 650;

    int current_frame;
    int current_direction = 0;

    while(window.isOpen()) {
        sf::Event event;

        man_sprite.setPosition(man_x, man_y);

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
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            man_x -= 10;
            current_frame = (current_frame + 1) % 10;
            current_direction = 1;
        }

        if(man_x < 5) {
            man_x = 5;
        }         
        if(man_x > 1230) {
            man_x = 1230;
        } 

        man_sprite.setTextureRect(sf::IntRect(current_frame * 48, current_direction * 60, 48, 60));

        window.clear();
        window.draw(background_sprite);
        window.draw(man_sprite);
        window.display();
    }
}