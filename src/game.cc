//g++ test.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
#include "game.h"
#include "enemy.h"
#include "projectile.h"
#include <SFML/Graphics/PrimitiveType.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/System/Vector2.hpp>
#include <algorithm>
#include <iterator>
#include <jsoncpp/json/json.h>
#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>
#include <filesystem>
#include <jsoncpp/json/writer.h>
#include <memory>
#include <ostream>
#include <string>

Game::Game(sf::RenderWindow& w)
{ 
  initLevel();
  //init player sprite
  playerTexture.loadFromFile("../src/sprites/player.png");
  //playerSprite = new sf::Sprite(playerTexture);
  playerSprite.setTexture(playerTexture);
  playerWidth = playerSprite.getTexture()->getSize().x;
  playerHeight = playerSprite.getTexture()->getSize().y;
  windowWidth = w.getSize().x;
  windowHeight = w.getSize().y;
  Player player("red",(windowWidth - playerWidth)/2, (600 - playerHeight), 4.f, 2, 25);
  this -> player = player;
  playerSprite.setPosition(player.GetX(), player.GetY());
  
  //INIT PROJECTILE TEXTURES
  playerProjectileTexture.loadFromFile("../src/sprites/playerProjectile.png");
  std::cout << "CURRENT PATH IS " << std::filesystem::current_path() << std::endl;

  gameRunning = true;

}



void Game::collisionCheck()
{
  for(int i = 0; i < sprites.size(); i++)
  {
    if(sprites[i] != nullptr)
    {
      auto& e = sprites[i];
      if(e->GetX() < 0 ||e->GetX() > 360 || e->GetY() > 650)
      {
        sprites[i].reset(nullptr);
      }

    }
  }
}

void Game::render(sf::RenderWindow& w)
{
  int playerX = (player.GetX() - playerWidth);
  int playerY = (player.GetY() - playerHeight);
  playerSprite.setPosition(playerX, playerY);
  w.draw(playerSprite);

  //DRAW PROJECTILES
  for(auto& e : playerProjectileSprite)
  {
    w.draw(*e);
  }
   w.draw(appendVertices(),&spriteSheet);

}
void Game::update()
{
  spawnEnemy();
  spawnProjectiles();
  collisionCheck();
  
  int i{0};
  for(auto& e: sprites)
  {
    if(e != nullptr)
      e->update(tick);
  }
  ++tick;
}
void Game::spawnEnemy()
{
  if(data[currentEnemy]["tickSpawn"].asBool() && data[currentEnemy]["tickSpawn"].asInt() == tick)
  {
    std::unique_ptr<Enemy> tmpEnemy(new Enemy(
        data[currentEnemy]["texture"].asString(),
        data[currentEnemy]["x"].asInt(),
        data[currentEnemy]["y"].asInt(),
        data[currentEnemy]["speed"].asFloat(),
        data[currentEnemy]["life"].asInt(),
        data[currentEnemy]["damage"].asInt(),
        data[currentEnemy]["move"].asString(),
        data[currentEnemy]["projectile"].asString(),
        data[currentEnemy]["projectileSpeed"].asInt(),
        data[currentEnemy]["fireRate"].asInt(),
        currentEnemy, "red"
      ));
    sprites.push_back(std::move(tmpEnemy));
    ++currentEnemy;
  }
}

void Game::spawnProjectiles()
{
  if(sprites.size() > 0)
  {
    std::vector<std::unique_ptr<Entity>> tmpSprites;
    for(auto& e : sprites)
    {
      if(e != nullptr && e->getType() == "enemy")
      {
        tmpSprites.push_back(std::move(e->shoot(tick)));
      }
    }
    sprites.insert(sprites.end(),
                   std::make_move_iterator(tmpSprites.begin()),
                   std::make_move_iterator(tmpSprites.end()));
  }
}

void Game::victory()
{
  if(data[data.size()-1]["victory"].asInt() <= tick &&
     player.GetY() < 100)
  {
    std::cout << "YOU WIN" << std::endl;
    gameRunning = false;
  }
}


void Game::initLevel()
{
  std::ifstream file("../src/levels/level1.json");
  if(file) 
    std::cout << "FILE EXISTS" << std::endl;
  else
    std::cout << "FILE DOESN'T EXSIST" << std::endl;
  Json::Reader reader;
  reader.parse(file, data);
  currentEnemy = 0;
  //test
  std::cout << "JSON DATA " << std::endl;
  std::cout << data << std::endl;
  std::cout << data[0]["textureFile"].asString() << std::endl;
  //load textures
  spriteSheet.loadFromFile("../src/sprites/spritesheet.png");
}


bool Game::AABB(sf::FloatRect a, sf::FloatRect b) const
{
  return 
         (b.left < a.left + a.width) &&
         (b.left + b.width > a.left) &&
         (b.top < a.top + a.height) &&
         (b.top + b.height > a.top);   
}

sf::VertexArray Game::appendVertices()
{
  sf::VertexArray tmpArr;
  tmpArr.resize(sprites.size()*4);
  tmpArr.setPrimitiveType(sf::Quads);
  int i{0};
  for(auto& e: sprites)
  {
    if(e != nullptr)
    {
      sf::VertexArray tmpQuad = e->getQuad();
      tmpArr[i] = tmpQuad[0];
      tmpArr[i+1] = tmpQuad[1];
      tmpArr[i+2] = tmpQuad[2];
      tmpArr[i+3] = tmpQuad[3];
      i += 4;
    }
  }
  return tmpArr; 
}


