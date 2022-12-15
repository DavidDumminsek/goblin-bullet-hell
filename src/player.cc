#include "player.h"
#include "projectile.h"
#include <SFML/Window/Keyboard.hpp>
#include <iostream>
/*Player::Player(float xc, float yc, float spd, int l, int dmg)
: Entity::Entity(xc, yc, spd, l)
{
  std::cout << "PLAYER CONSTRUCTOR WITH PARAMETERS" << std::endl;
  damage = dmg;
}*/
Player::Player()
{
}

Player::Player(float xc, float yc, float spd, int l, int dmg)
: Entity::Entity(xc, yc, spd, l)
{
  std::cout << "PLAYER CONSTRUCTOR WITH PARAMETERS" << std::endl;
  //CONSTRUCTOR UNIQUE TO PLAYER CLASS
  this->dmg = dmg;
  this->cooldownMax = 10;
  //CREATE MOVEMENT VARIABLE FOR FUTURE PROJECTILE OBJECTS
  std::cout << "X: " << x << std::endl;
  std::cout << "Y: " << y << std::endl;
  std::cout << "SPEED: " << speed << std::endl;
  std::cout << "LIFE: " << life << std::endl;

}
 std::unique_ptr<Projectile> Player::shoot(int tick)
{

  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && cooldown < cooldownMax)
  {
    std::unique_ptr<Projectile> p(new Projectile{x-20,y-20,11.f,1,10} );
    cooldown += cooldownMax;
    return p;
  }
  else
  {
   std::unique_ptr<Projectile> p(nullptr);
   cooldown -= 1;
   if(cooldown < 0) 
      cooldown = 0;
   return p;  
  }
}
void Player::move(int tick)
{
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
}

