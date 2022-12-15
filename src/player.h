#ifndef PLAYER_H
#define PLAYER_H
#include <map>
#include <string>
#include "entity.h"
#include "projectile.h"
#include <SFML/Graphics.hpp>
class Player : public Entity
{
  private:
    int cooldown{0};
    int cooldownMax{0};
  public:
    Player();
    Player(float xc, float yc, float spd, int l, int dmg);
    Player(const Player& rhs) = default;
    //move constructor
    Player(Player&& rhs) = default;
    //copy assigment
    Player& operator=(const Player& rhs) = default;
    //move assigment
    Player& operator=(Player&& rhs) = default;
    ~Player() = default;
    ///Creates and returns a projectile if spacebar is pressed
    ///
    ///This function checks if spacebar is pressed. A cooldown timer is also checked against.
    ///If the function has returned a \ref Projectile before the cooldown is maxed.
    ///And everytime the function dosen't return a \ref Projectile the cooldown is reduced by one.
    ///@return A \ref Projectile pointer if spacebar is pressed and cooldown is equal to 0
    std::unique_ptr<Projectile> shoot(int tick);
    ///Changes x and y coordinates based on user input
    ///
    ///This function changes the x and y coordinates based on what key is pressed.
    void move(int tick) override;
};
#endif
