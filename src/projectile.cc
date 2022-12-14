#include "projectile.h"
#include <string>
#include <iostream>
#include <math.h>
Projectile::Projectile()
{
  movement = {};
}
Projectile::Projectile(float xc, float yc, float spd, int l, int dmg)
: Entity::Entity(xc, yc, spd, l)
{
  this->dmg = dmg;
}
Projectile::Projectile(float xc, float yc, float spd, int l, int dmg, std::string mv) 
: Entity::Entity(xc, yc, spd, l)
{
  this->dmg = dmg;
  movement = mv;
}
void Projectile::move(int tick)
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
  else if(movement == "wobble")
  {
    y += speed;
    x += 4*sin(y/12);

  }
  else
  {
    y+=speed;
  }
}
