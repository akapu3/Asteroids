CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

SRC = src/main.cpp src/Game.cpp src/Player.cpp src/Asteroid.cpp src/Bullet.cpp
OBJ = $(SRC:.cpp=.o)
TARGET = Asteroids

all: $(TARGET)

$(TARGET): $(OBJ)
    $(CXX) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
    $(CXX) $(CXXFLAGS) -c $< -o $@

clean:
    rm -f $(OBJ) $(TARGET)

.PHONY: all clean
