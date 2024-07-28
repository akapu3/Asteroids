cmake_minimum_required(VERSION 3.10)

# Set the project name
project(Asteroids)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Find the SFML package
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

# Add the include directory
include_directories(include)

# Add the executable
add_executable(Asteroids
        src/main.cpp
        src/Game.cpp
        src/Player.cpp
        src/Asteroid.cpp
        src/Bullet.cpp
)

# Link SFML libraries
target_link_libraries(Asteroids sfml-graphics sfml-window sfml-system)
