#include "Player.h"

Player::Player()
        : velocity(0, 0), rotationSpeed(5), shootCooldown(0) {
    if (!texture.loadFromFile("assets/player.png")) {
        // Handle error
    }
    sprite.setTexture(texture);
    sprite.setOrigin(texture.getSize().x / 2, texture.getSize().y / 2);
    sprite.setPosition(400, 300);
}

void Player::handleInput(std::vector<Bullet> &bullets) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        sprite.rotate(-rotationSpeed);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        sprite.rotate(rotationSpeed);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        float angle = sprite.getRotation() / 180 * 3.14159;
        velocity.x += cos(angle) * 0.1;
        velocity.y += sin(angle) * 0.1;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && shootCooldown <= 0) {
        bullets.push_back(Bullet(sprite.getPosition(), sprite.getRotation()));
        shootCooldown = 15; // Cooldown time before the next shot
    }
}

void Player::update() {
    sprite.move(velocity);
    if (sprite.getPosition().x > 800) sprite.setPosition(0, sprite.getPosition().y);
    if (sprite.getPosition().x < 0) sprite.setPosition(800, sprite.getPosition().y);
    if (sprite.getPosition().y > 600) sprite.setPosition(sprite.getPosition().x, 0);
    if (sprite.getPosition().y < 0) sprite.setPosition(sprite.getPosition().x, 600);

    if (shootCooldown > 0) {
        shootCooldown--;
    }
}

void Player::render(sf::RenderWindow &window) {
    window.draw(sprite);
}

sf::FloatRect Player::getBounds() const {
    return sprite.getGlobalBounds();
}
