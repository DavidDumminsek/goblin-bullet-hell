#ifndef PLAYER_H
#define PLAYER_H
#include <map>
#include <string>
#include "entity.h"
#include <SFML/Graphics.hpp>
class Player : public Entity
{
  private:
    std::map<std::string, int> movement;
    int damage{0};
  public:
    Player();
    Player(int xc, int yc, float spd, int l, int dmg);
    Player(const Player& rhs) = default;
    //move constructor
    Player(Player&& rhs) = default;
    //copy assigment
    Player& operator=(const Player& rhs) = default;
    //move assigment
    Player& operator=(Player&& rhs) = default;
    ~Player() = default;
    void shoot() override;
    void move(sf::Event e);
};
#endif
