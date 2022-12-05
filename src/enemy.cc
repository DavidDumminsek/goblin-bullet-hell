#include "enemy.h"
#include <iostream>

Enemy::Enemy(int xc, int yc, float spd, int l, int dmg, std::string mv)
: Entity::Entity(xc,yc,spd,l)
{
  this->dmg = dmg;
  movement = mv;
  /*enemyTexture = texture;
  enemySprite.setTexture(enemyTexture); 
  if(enemySprite.getTexture())
    std::cout << "ENEMY TEXTURE LOADED" << std::endl;
  enemySprite.setPosition((xc - enemyTexture.getSize().x),(yc - enemyTexture.getSize().y));*/
  std::cout << "X: " << x << std::endl;
  std::cout << "Y: " << y << std::endl;
  std::cout << "SPEED: " << speed << std::endl;
  std::cout << "LIFE: " << life << std::endl;

}

Enemy::~Enemy()
{
  std::cout << "INIT DESTRUCT" << std::endl;
}
void Enemy::move(int tick)
{
  if(movement == "straight")
  {
    y+=speed;
  }
  else if(movement == "right")
  {
    y += speed;
    x += speed;
  }
  else if(movement == "zigzag")
  {
    if(x >= 360)
    {
      y += speed;
      x -= speed;
    }
    else
    {
      y+= speed;
      x+= speed;
    }
  }
  else
  {
    y += speed;
  }

}
void Enemy::shoot()
{
  std::cout << "SHOOT" << std::endl;
}

sf::Sprite& Enemy::getSprite()
{
  return enemySprite;
}
