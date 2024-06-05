#include <SFML/Graphics.hpp>

class Gold {
public:
    Gold() = delete; 
    Gold(float x, float y);
    Gold(const Gold&) = delete;
    Gold(Gold&&) = default;
    Gold& operator=(const Gold&) = delete;
    Gold& operator=(Gold&&) = default;
    ~Gold() = default;

    void setSprite(sf::Sprite);
    void setPosition(int x, int y);

    sf::Sprite getSprite();
    sf::Vector2f getPosition();
    sf::FloatRect getBounds();

    void draw(sf::RenderWindow&);
private:
    sf::Vector2f m_position;
    sf::Sprite m_sprite;
};