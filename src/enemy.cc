#include "enemy.h"
#include <iostream>

Enemy::~Enemy()
{
  std::cout << "INIT DESTRUCT" << std::endl;
}
void Enemy::shoot()
{
  std::cout << "SHOOT" << std::endl;
}
