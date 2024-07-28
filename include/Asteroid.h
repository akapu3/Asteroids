#ifndef ASTEROID_H
#define ASTEROID_H

#include <SFML/Graphics.hpp>

class Asteroid {
public:
    Asteroid();
    void update();
    void render(sf::RenderWindow &window);
    sf::FloatRect getBounds() const;

private:
    sf::Sprite sprite;
    sf::Texture texture;
    sf::Vector2f velocity;
};

#endif // ASTEROID_H
