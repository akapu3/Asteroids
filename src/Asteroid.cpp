#include "Asteroid.h"
#include <cstdlib>

Asteroid::Asteroid() {
    if (!texture.loadFromFile("assets/asteroid.png")) {
        // Handle error
    }
    sprite.setTexture(texture);
    sprite.setOrigin(texture.getSize().x / 2, texture.getSize().y / 2);
    sprite.setPosition(rand() % 800, rand() % 600);
    velocity.x = (rand() % 100 - 50) / 10.0;
    velocity.y = (rand() % 100 - 50) / 10.0;
}

void Asteroid::update() {
    sprite.move(velocity);
    if (sprite.getPosition().x > 800) sprite.setPosition(0, sprite.getPosition().y);
    if (sprite.getPosition().x < 0) sprite.setPosition(800, sprite.getPosition().y);
    if (sprite.getPosition().y > 600) sprite.setPosition(sprite.getPosition().x, 0);
    if (sprite.getPosition().y < 0) sprite.setPosition(sprite.getPosition().x, 600);
}

void Asteroid::render(sf::RenderWindow &window) {
    window.draw(sprite);
}

sf::FloatRect Asteroid::getBounds() const {
    return sprite.getGlobalBounds();
}
