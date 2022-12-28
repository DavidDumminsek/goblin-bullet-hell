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

Player::Player(std::string tex, float xc, float yc, float spd, int l, int dmg)
: Entity::Entity(tex, xc, yc, spd, l)
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
  entityType = "player";
  collision = true;

}
 std::unique_ptr<Projectile> Player::shoot(int tick)
{

  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && cooldown < cooldownMax)
  {
    std::unique_ptr<Projectile> p(new Projectile{"red", x+12,y,11.f,1,10} );
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
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && y > 0)
  {
    y -= speed;
  }
  if( sf::Keyboard::isKeyPressed(sf::Keyboard::Down)  && y < 610)
  {
    y += speed;
  }
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)  && x > 0)
  {
    x -= speed;
  }
  if( sf::Keyboard::isKeyPressed(sf::Keyboard::Right)  && x < 330)
  {
    x += speed;
  }
}
void Player::update(int tick)
{
  move(tick);
  changeQuadPos();
  hitbox.height = 32;
  hitbox.width = 32;
  hitbox.top = y;
  hitbox.left = x; 
}

