#include "enemy.h"
#include "projectile.h"
#include <iostream>

Enemy::Enemy(std::string tex, float xc, float yc, float spd, 
             int l, int dmg, std::string mv, std::string mvPro, 
             float pSpeed, int fireRate, int current, std::string proTex)
: Entity::Entity(tex,xc,yc,spd,l)
{
  this->dmg = dmg;
  this->pSpeed = pSpeed;
  this->fireRate = fireRate;
  movement = mv;
  movementProjectile = mvPro;
  /*enemyTexture = texture;
  enemySprite.setTexture(enemyTexture); 
  if(enemySprite.getTexture())
    std::cout << "ENEMY TEXTURE LOADED" << std::endl;
  enemySprite.setPosition((xc - enemyTexture.getSize().x),(yc - enemyTexture.getSize().y));*/
  std::cout << "X: " << x << std::endl;
  std::cout << "Y: " << y << std::endl;
  std::cout << "SPEED: " << speed << std::endl;
  std::cout << "LIFE: " << life << std::endl;
  entityType = "enemy";
  collision = true;

  projectileTex = proTex;


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
  else if(movement == "left")
  {
    y += speed;
    x -= speed;
  }
  else if(movement == "zigzag")
  {
    if(moveTimer < 50)
    {
      y += speed;
      x -= speed;
    }
    else if(moveTimer > 50)
    {
      y += speed;
      x += speed;
    }
    moveTimer++;
    if(moveTimer == 100)
      moveTimer = 0;
  }
  else
  {
    y += speed;
  }

}
 std::unique_ptr<Projectile> Enemy::shoot(int tick)
{
  if(tick%fireRate == 0)
  {
      std::unique_ptr<Projectile> 
      p(new Projectile{texture, x+10,y+10,pSpeed,1,dmg,movementProjectile});
      return p;
  }
  else
  {
    return nullptr;
  }
}
void Enemy::update(int tick)
{
  move(tick);
  changeQuadPos();
  hitbox.height = 32;
  hitbox.width = 32;
  hitbox.top = y;
  hitbox.left = x; 
}


