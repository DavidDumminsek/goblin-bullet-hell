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

Player::Player(int xc, int yc, float spd, int l, int dmg)
: Entity::Entity(xc, yc, spd, l)
{
  std::cout << "PLAYER CONSTRUCTOR WITH PARAMETERS" << std::endl;
  //CONSTRUCTOR UNIQUE TO PLAYER CLASS
  damage = dmg;
  //CREATE MOVEMENT VARIABLE FOR FUTURE PROJECTILE OBJECTS
  std::cout << "X: " << x << std::endl;
  std::cout << "Y: " << y << std::endl;
  std::cout << "SPEED: " << speed << std::endl;
  std::cout << "LIFE: " << life << std::endl;

}
void Player::shoot()
{
  std::cout << "SHOOT" << std::endl;
}
void Player::move(sf::Event e)
{
  auto keyPressed = e.key.code; 

  if( keyPressed == sf::Keyboard::Up && y > 0)
  {
    y -= speed;
  }
  if( keyPressed == sf::Keyboard::Down && y < 640)
  {
    y += speed;
  }
  if( keyPressed == sf::Keyboard::Left && x > 0)
  {
    x -= speed;
  }
  if( keyPressed == sf::Keyboard::Right && x < 360)
  {
    x += speed;
  }
  std::cout << "PLAYER MOVE CALLED: X: "<< x << " Y: " << y << std::endl;
}
