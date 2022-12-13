#include "objectmanager.h"
#include "level.h"
#include "player.h"
#include <SFML/Graphics/PrimitiveType.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics.hpp>
#include <jsoncpp/json/value.h>
#include <iostream>
#include <memory>
#include <string>


ObjectManager::ObjectManager(sf::RenderWindow& w, std::string pathToLevel)
{
  this->initPlayer(w);

  enemyProjectileVertices.setPrimitiveType(sf::Quads)  ;
  enemyProjectileVertices.resize(totalBullets);

  Level l(pathToLevel);
  this->level = l;

  projectileTexture.loadFromFile("../src/sprites/playerProjectile-sheet.png");
}

void ObjectManager::initPlayer(sf::RenderWindow& w)
{
  playerTexture.loadFromFile("../src/sprites/player.png");
  playerSprite.setTexture(playerTexture);
  Player p(
         (w.getSize().x - playerTexture.getSize().x)*0.5,
         (600 - playerTexture.getSize().y),
          4.f, 2, 15);
  this->player = p;

  playerSprite.setPosition(player.GetX(), player.GetY());
}

void ObjectManager::update()
{
  //poll event will be in game loop

  player.move(tick);
  spawnEnemy(level) ;
  updateEnemies();
  updateEnemyProjectiles();
  deleteNonVisible();

}

void ObjectManager::updatePlayer()
{
  player.move(tick);

  int playerX = player.GetX() - playerTexture.getSize().x;
  int playerY = player.GetY() - playerTexture.getSize().y;

  playerSprite.setPosition(playerX, playerY);
}

void ObjectManager::spawnEnemy(Level level)
{
  Json::Value data = level.getData();

  if( data[currentEnemy]["tickSpawn"].asBool() && 
      data[currentEnemy]["tickSpawn"].asInt() == tick)
  {
    std::cout << "CREATING ENEMY: " << "\n"
              << "X: " << data[currentEnemy]["x"].asString() << "\n"
              << "Y: " << data[currentEnemy]["y"].asString() << "\n"
              << "spd: " << data[currentEnemy]["speed"].asString() << "\n"
              << "life: " << data[currentEnemy]["life"].asString() << "\n"
              << "damage: " << data[currentEnemy]["damage"].asString() << std::endl;
    
    std::unique_ptr<Enemy> tmpEnemy(new Enemy(
                                      data[currentEnemy]["x"].asInt(),
                                      data[currentEnemy]["y"].asInt(),
                                      data[currentEnemy]["speed"].asInt(),
                                      data[currentEnemy]["life"].asInt(),
                                      data[currentEnemy]["damage"].asInt(),
                                      data[currentEnemy]["move"].asString(),
                                      data[currentEnemy]["projectile"].asString(),
                                      currentEnemy
                                    ));
    
    std::unique_ptr<sf::Sprite> tmpSprite(new sf::Sprite);
    tmpSprite->setTexture(*enemiesSpriteTexture[currentEnemy]);
    //dont forget enemiesSpriteTexture.erase(it->getCurrent()) too free mem
    tmpSprite->setPosition(tmpEnemy.get()->GetX(), tmpEnemy.get()->GetY());
    enemiesSprite.push_back(std::move(tmpSprite));
    enemies.push_back(std::move(tmpEnemy));
    std::cout << "ENEMY SPAWNED" << std::endl;
    ++currentEnemy;
  }
}

void ObjectManager::loadEnemyTextures(Level level)
{
  Json::Value data = level.getData();

  for(auto& e : data)
  {
    std::unique_ptr<sf::Texture> tmpTexture(new sf::Texture);
    tmpTexture->loadFromFile(e["textureFile"].asString());
    enemiesSpriteTexture.push_back(std::move(tmpTexture));
  }
}

void ObjectManager::updateEnemies()
{
    auto it = enemies.begin();
    auto it1 = enemiesSprite.begin();
    
    for(; it != enemies.end() && it1 != enemiesSprite.end(); ++it, ++it1 )
    {
      it->get()->move(tick);
      it1->get()->setPosition(it->get()->GetX(),it->get()->GetY());
    }
}

void ObjectManager::updateEnemyProjectiles()
{
  //CREATE A BULLET FOR EVERY ENEMY
  for(auto& e : enemies)
  {
    if(e->shoot(tick))
    {
      enemyProjectile.push_back(std::move(e->shoot(tick)));
      int y{0};
      size_t i = enemyProjectile.size()-1;
      sf::Vertex* quad = &enemyProjectileVertices[i*4]; 
      

      //set quad position
      quad[0].position = sf::Vector2f(e->GetX(), 
                             e->GetY());
      quad[1].position = sf::Vector2f(e->GetX() + 8,  e->GetY());
      quad[2].position = sf::Vector2f(e->GetX() + 8, e->GetY() + 8);
      quad[3].position = sf::Vector2f(e->GetX(), e->GetY() + 8);


      //TEXTURE COORDS IN SPIRTE SHEET HAVE NO SPRITE SHEET ATM  SO SCARY
      quad[0].texCoords = sf::Vector2f(0,0);
      quad[1].texCoords = sf::Vector2f(8 , 0);
      quad[2].texCoords = sf::Vector2f(8, 8);
      quad[3].texCoords = sf::Vector2f(0 , 8);
    }
  }

  //UPDATE THE EXISTING BULLETS
  int y{0};
  for(auto& e : enemyProjectile)
  {
      //point to a quad in vertex array
      auto it = std::find(enemyProjectile.begin(), enemyProjectile.end(), e);     
      size_t i = std::distance(enemyProjectile.begin(), it);
      sf::Vertex* quad = &enemyProjectileVertices[i*4]; 
      e->move(tick); 

      //set quad position
      quad[0].position = sf::Vector2f(e->GetX(), 
                             e->GetY());
      quad[1].position = sf::Vector2f(e->GetX() + 8,  e->GetY());
      quad[2].position = sf::Vector2f(e->GetX() + 8, e->GetY() + 8);
      quad[3].position = sf::Vector2f(e->GetX(), e->GetY() + 8);

  }
}

void ObjectManager::render(sf::RenderWindow &w) const
{

}
