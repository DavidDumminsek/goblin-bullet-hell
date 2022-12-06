#include "enemy.h"
#include "projectile.h"
#include <iostream>

Enemy::Enemy(int xc, int yc, float spd, int l, int dmg, std::string mv, std::string mvPro, int current)
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
 std::unique_ptr<Projectile>Enemy::shoot(int tick)
{
  if(tick%20 == 0)
  {
    if(movementProjectile == "pentashot")
    {
      std::unique_ptr<Projectile> p(nullptr);
      return p;
    }
    else
    {
      std::unique_ptr<Projectile> 
      p(new Projectile{x+10,y+2,-5.f,1,dmg,movementProjectile});
      return p;
    }
  }
  else
  {
    return nullptr;
  }
}

sf::Sprite& Enemy::getSprite()
{
  return enemySprite;
}
