#include "player.h"
#include <iostream>
/*Player::Player(int xc, int yc, float spd, int l, int dmg)
: Entity::Entity(xc, yc, spd, l)
{
  std::cout << "PLAYER CONSTRUCTOR WITH PARAMETERS" << std::endl;
  damage = dmg;
}*/
Player::Player()
{
  movement = {};
}

Player::Player(int xc, int yc, float spd, int l, int dmg, std::map<std::string, int> mv)
: Entity::Entity(xc, yc, spd, l)
{
  std::cout << "PLAYER CONSTRUCTOR WITH PARAMETERS" << std::endl;
  //CONSTRUCTOR UNIQUE TO PLAYER CLASS
  damage = dmg;
  //CREATE MOVEMENT VARIABLE FOR FUTURE PROJECTILE OBJECTS
  movement = mv; 
}
void Player::shoot()
{
  std::cout << "SHOOT" << std::endl;
}
void Player::move()
{
  std::cout << "MOVE" << std::endl;
}
