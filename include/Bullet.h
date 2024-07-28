#ifndef BULLET_H
#define BULLET_H

#include <SFML/Graphics.hpp>

class Bullet {
public:
    Bullet(sf::Vector2f position, float rotation);
    void update();
    void render(sf::RenderWindow &window);
    sf::FloatRect getBounds() const;
    bool isOffScreen() const;

private:
    sf::Sprite sprite;
    sf::Texture texture;
    sf::Vector2f velocity;
};

#endif // BULLET_H
