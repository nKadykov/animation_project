#include "gold.h"

Gold::Gold(float x, float y) {
    m_position.x = x;
    m_position.y = y;
}

void Gold::setSprite(sf::Sprite sprite) {
    m_sprite = std::move(sprite);
}

void Gold::setPosition(int x, int y) {
    m_position.x = static_cast<float>(x);
    m_position.y = static_cast<float>(y);
}

sf::Sprite Gold::getSprite() {
    return m_sprite;
}

sf::Vector2f Gold::getPosition() {
    return m_position;
}

sf::FloatRect Gold::getBounds() {
    return m_sprite.getGlobalBounds();
}

void Gold::draw(sf::RenderWindow& window) {
    m_sprite.setPosition(m_position);
    window.draw(m_sprite);
}