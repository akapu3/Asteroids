#include "Bullet.h"
#include <cmath>

Bullet::Bullet(sf::Vector2f position, float rotation) {
    if (!texture.loadFromFile("assets/bullet.png")) {
        // Handle error
    }
    sprite.setTexture(texture);
    sprite.setOrigin(texture.getSize().x / 2, texture.getSize().y / 2);
    sprite.setPosition(position);
    sprite.setRotation(rotation);

    float angle = rotation / 180 * 3.14159;
    velocity.x = cos(angle) * 5;
    velocity.y = sin(angle) * 5;
}

void Bullet::update() {
    sprite.move(velocity);
}

void Bullet::render(sf::RenderWindow &window) {
    window.draw(sprite);
}

sf::FloatRect Bullet::getBounds() const {
    return sprite.getGlobalBounds();
}

bool Bullet::isOffScreen() const {
    sf::Vector2f position = sprite.getPosition();
    return position.x < 0 || position.x > 800 || position.y < 0 || position.y > 600;
}
