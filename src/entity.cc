#include "entity.h"
#include <SFML/Graphics/PrimitiveType.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <iostream>
#include <utility>

Entity::Entity()
{
  x = 160;
  y = 320;
  speed = 1.f;
   life = 2;
  quad.setPrimitiveType(sf::Quads); 
  quad.resize(4);
  //POSITION
  changeQuadPos(); 
  //TEXCOORDS
  quad[0].texCoords = sf::Vector2f(0,0);
  quad[1].texCoords = sf::Vector2f(32,0);
  quad[2].texCoords = sf::Vector2f(0,32);
  quad[3].texCoords = sf::Vector2f(32,32);

}

Entity::Entity(float xc, float yc, float spd, int l)
{
  x = xc;
  y = yc;
  speed = spd;
  life = l;

  quad.setPrimitiveType(sf::Quads); 
  quad.resize(4);
  //POSITION
  changeQuadPos(); 
  std::cout << "VERTEX COUNT  " << quad.getVertexCount() << std::endl;
  //TEXCOORDS
  quad[0].texCoords = sf::Vector2f(0,0);
  quad[1].texCoords = sf::Vector2f(32,0);
  quad[2].texCoords = sf::Vector2f(32,32);
  quad[3].texCoords = sf::Vector2f(0,32);

}


void Entity::move(int tick)
{
  std::cout << "MOVE" << std::endl;
}

bool Entity::takeDmg(int dmg)
{
  life -= dmg;
  return life <= 0;
}
int Entity::GetX() const
{
  return x;
}
int Entity::GetY() const
{
  return y;
}

int Entity::getDmg()
{
  return dmg;
}

void Entity::changeQuadPos()
{
  quad[0].position = sf::Vector2f(x, y);
  quad[1].position = sf::Vector2f(x + 32 , y);
  quad[2].position = sf::Vector2f(x + 32 , y + 32);
  quad[3].position = sf::Vector2f(x , y + 32);
}

sf::VertexArray Entity::getQuad()
{
  return quad;
}
