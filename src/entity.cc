#include "entity.h"
#include <iostream>
#include <utility>

Entity::Entity()
{
  x = 160;
  y = 320;
  speed = 1.f;
   life = 2;
}

Entity::Entity(float xc, float yc, float spd, int l)
{
  x = xc;
  y = yc;
  speed = spd;
  life = l;
}


void Entity::move(int tick)
{
  std::cout << "MOVE" << std::endl;
}


int Entity::GetX() const
{
  return x;
}
int Entity::GetY() const
{
  return y;
}
