#include "player.h"
#include <SFML/Window/Keyboard.hpp>
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

  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && y > 20)
  {
    y -= speed;
  }
  if( sf::Keyboard::isKeyPressed(sf::Keyboard::Down)  && y < 640)
  {
    y += speed;
  }
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)  && x > 20)
  {
    x -= speed;
  }
  if( sf::Keyboard::isKeyPressed(sf::Keyboard::Right)  && x < 360)
  {
    x += speed;
  }
  
  std::cout << "PLAYER MOVE CALLED: X: "<< x << " Y: " << y << std::endl;
}
