#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Player.h"
#include "Asteroid.h"
#include "Bullet.h"

class Game {
public:
    Game();
    void run();

private:
    void processEvents();
    void update();
    void render();
    void handleCollisions();

    sf::RenderWindow window;
    Player player;
    std::vector<Asteroid> asteroids;
    std::vector<Bullet> bullets;
};

#endif // GAME_H
