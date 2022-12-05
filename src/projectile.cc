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
  //player projectile movement
  if(movement.empty())
  {
    y -= speed;
  }
  //Enemy projectile specifier
  else if(movement == "right")
  {
    y += speed;
    x += speed/2;
  }
  else if(movement == "left")
  {
    y+=speed;
    x-=speed;
  }
  else
  {
    y+=speed;
  }
}
