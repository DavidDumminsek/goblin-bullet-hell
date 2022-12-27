#include "projectile.h"
#include <string>
#include <iostream>
#include <math.h>
Projectile::Projectile()
{
  movement = {};
}
Projectile::Projectile(std::string tex, float xc, float yc, float spd, int l, int dmg)
: Entity::Entity(tex, xc, yc, spd, l)
{
  this->dmg = dmg;
  entityType = "projectile";
  collision = true;
}
Projectile::Projectile(std::string tex, float xc, float yc, float spd, int l, int dmg, std::string mv) 
: Entity::Entity(tex,xc, yc, spd, l)
{
  this->dmg = dmg;
  movement = mv;
  entityType = "projectile";
  collision = true;
  initTexCoords();
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
void Projectile::update(int tick)
{
  move(tick);
  changeQuadPos();
}

std::unique_ptr<Projectile> Projectile::shoot(int tick)
{
  return nullptr;
}

void Projectile::changeQuadPos()
{
  //POSSIBILITY TO CHANGE PROJECTILE SIZE
  quad[0].position = sf::Vector2f(x, y);
  quad[1].position = sf::Vector2f(x + 8 , y);
  quad[2].position = sf::Vector2f(x + 8 , y + 8);
  quad[3].position = sf::Vector2f(x , y + 8);
  hitbox = quad.getBounds();
}

void Projectile::initTexCoords()
{
  if(texture == "green")
  {
    quad[0].texCoords = sf::Vector2f(80,0);
    quad[1].texCoords = sf::Vector2f(88,0);
    quad[2].texCoords = sf::Vector2f(88,8);
    quad[3].texCoords = sf::Vector2f(80,8);
  }
  else if(texture == "purple")
  {
    quad[0].texCoords = sf::Vector2f(72,0);
    quad[1].texCoords = sf::Vector2f(80,0);
    quad[2].texCoords = sf::Vector2f(80,8);
    quad[3].texCoords = sf::Vector2f(72,8);
  }
  else if(texture == "red")
  {
    quad[0].texCoords = sf::Vector2f(64,0);
    quad[1].texCoords = sf::Vector2f(72,0);
    quad[2].texCoords = sf::Vector2f(72,8);
    quad[3].texCoords = sf::Vector2f(64,8);
  }

}
