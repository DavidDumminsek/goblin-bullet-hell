#include "projectile.h"
#include <string>
#include <iostream>
Projectile::Projectile()
{
  movement = {};
}
Projectile::Projectile(int xc, int yc, float spd, int l, int dmg)
: Entity::Entity(xc, yc, spd, l)
{
  this->dmg = dmg;
}
Projectile::Projectile(int xc, int yc, float spd, int l, int dmg, std::string mv) 
: Entity::Entity(xc, yc, spd, l)
{
  this->dmg = dmg;
  movement = mv;
}
void Projectile::move()
{
  if(movement.empty())
  {
    y -= speed;
  }
  else
  {
    std::cout << "OTHER MOVE" << std::endl;
  }
}
