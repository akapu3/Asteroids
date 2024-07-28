#include "Game.h"

Game::Game()
        : window(sf::VideoMode(800, 600), "Asteroids") {
    // Initialize player and asteroids
    for (int i = 0; i < 5; ++i) {
        asteroids.push_back(Asteroid());
    }
}

void Game::run() {
    while (window.isOpen()) {
        processEvents();
        update();
        handleCollisions();
        render();
    }
}

void Game::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
    }
    player.handleInput(bullets);
}

void Game::update() {
    player.update();
    for (auto &asteroid : asteroids) {
        asteroid.update();
    }
    for (auto &bullet : bullets) {
        bullet.update();
    }
    bullets.erase(std::remove_if(bullets.begin(), bullets.end(), [](Bullet &b) { return b.isOffScreen(); }), bullets.end());
}

void Game::render() {
    window.clear();
    player.render(window);
    for (auto &asteroid : asteroids) {
        asteroid.render(window);
    }
    for (auto &bullet : bullets) {
        bullet.render(window);
    }
    window.display();
}

void Game::handleCollisions() {
    // Check collision between player and asteroids
    for (const auto &asteroid : asteroids) {
        if (player.getBounds().intersects(asteroid.getBounds())) {
            // Handle collision (e.g., end game, reduce player's health)
            window.close(); // Placeholder: Close window on collision
        }
    }

    // Check collision between bullets and asteroids
    for (auto bulletIt = bullets.begin(); bulletIt != bullets.end();) {
        bool bulletDestroyed = false;
        for (auto asteroidIt = asteroids.begin(); asteroidIt != asteroids.end();) {
            if (bulletIt->getBounds().intersects(asteroidIt->getBounds())) {
                asteroidIt = asteroids.erase(asteroidIt);
                bulletIt = bullets.erase(bulletIt);
                bulletDestroyed = true;
                break;
            } else {
                ++asteroidIt;
            }
        }
        if (!bulletDestroyed) {
            ++bulletIt;
        }
    }
}
