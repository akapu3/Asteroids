#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Bullet.h"

class Player {
public:
    Player();
    void handleInput(std::vector<Bullet> &bullets);
    void update();
    void render(sf::RenderWindow &window);
    sf::FloatRect getBounds() const;

private:
    sf::Sprite sprite;
    sf::Texture texture;
    sf::Vector2f velocity;
    float rotationSpeed;
    float shootCooldown;
};

#endif // PLAYER_H
