#include "entity.h"
#include <iostream>
#include <utility>

Entity::Entity()
{
  x = 160;
  y = 320;
  speed = 1.f;
  int life = 2;
}

Entity::Entity(int xc, int yc, float spd, int l)
{
  std::cout << "CONSTRUCTOR WITH PARAMETERS" << std::endl;
  x = xc;
  y = yc;
  speed = spd;
  life = l;
}


void Entity::move()
{
  std::cout << "MOVE" << std::endl;
}

void Entity::die()
{
  delete this;
}

int Entity::GetX() const
{
  return x;
}
int Entity::GetY() const
{
  return y;
}
