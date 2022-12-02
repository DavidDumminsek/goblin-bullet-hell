#include "projectile.h"

Projectile::Projectile()
{
  movement = {};
}
Projectile::Projectile(int xc, int yc, float spd, int l, int dmg, std::map<std::string, int> mv) 
: Entity::Entity(xc, yc, spd, l)
{
  this->dmg = dmg;
  movement = mv;
}
