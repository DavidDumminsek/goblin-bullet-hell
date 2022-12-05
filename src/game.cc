//g++ test.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
#include "game.h"
#include "enemy.h"
#include "projectile.h"
#include <SFML/Graphics/Texture.hpp>
#include <algorithm>
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
  std::ifstream file("../src/levels/level1.json");
  if(file) 
    std::cout << "FILE EXISTS" << std::endl;
  else
    std::cout << "FILE DOESN'T EXSIST" << std::endl;
  Json::Reader reader;
  reader.parse(file, data);
  currentEnemy = 0;
  initLevel();
  //test
  std::cout << "JSON DATA " << std::endl;
  std::cout << data << std::endl;
  std::cout << data[0]["textureFile"].asString() << std::endl;

  //init player sprite
  texture.loadFromFile("../src/sprites/player.png");
  //playerSprite = new sf::Sprite(texture);
  playerSprite.setTexture(texture);
  playerWidth = playerSprite.getTexture()->getSize().x;
  playerHeight = playerSprite.getTexture()->getSize().y;
  windowWidth = w.getSize().x;
  windowHeight = w.getSize().y;
  Player player((windowWidth - playerWidth)/2, (600 - playerHeight), 4.f, 2, 15);
  this -> player = player;
  playerSprite.setPosition(player.GetX(), player.GetY());
  
  //INIT PROJECTILE TEXTURES
  playerProjectileTexture.loadFromFile("../src/sprites/playerProjectile.png");
  std::cout << "CURRENT PATH IS " << std::filesystem::current_path() << std::endl;
}



void Game::collisionCheck()
{
  //TO DO
  //CHECK IF OBJECT COORDS OVERLAP
  //USE GAME VECTOR FOR ENEMY PROJECTILE TO CHECK AGAISNT PLAYER
  if(playerProjectile.size() > 0)
  {
    //std::cout << playerProjectile[0]->GetY() << std::endl;
    auto it=playerProjectile.begin();
    auto it1 = playerProjectileSprite.begin();

    for(; it != playerProjectile.end() && it1 != playerProjectileSprite.end(); /*--it, --it1*/ )
    {
      if( it->get()->GetY() < 0) 
      {
        it = playerProjectile.erase(it);
        it1 = playerProjectileSprite.erase(it1);
      }
      else
      {
        ++it;
        ++it1;
      }
    }
  
  }
}

void Game::update(sf::Event& e, sf::RenderWindow& w)
{
  //RUN EVERYTHING TO HAPPEN EVERY TICK
  while(w.pollEvent(e))
  {
    if (e.type == sf::Event::Closed)
       w.close();
  }
  player.move(e);

  //PLAYER SHOOT
  updateProjectile(); 
  spawnEnemy();
  updateEnemies();
  collisionCheck();
  ++tick;
}

void Game::updateProjectile()
{
  std::unique_ptr<Projectile>  temp = player.shoot();
  
  if(temp)
  {
    //MÅSTE ANVÄNDA MOVE PÅ SMART PEKARE!"!!"
    playerProjectile.push_back(std::move(temp));
    std::unique_ptr<sf::Sprite> tmpSprite(new sf::Sprite);
    tmpSprite->setTexture(playerProjectileTexture);
    playerProjectileSprite.push_back(std::move(tmpSprite));
  }
  //std::vector<std::unique_ptr<Projectile>> old = playerProjectile;
  //std::transform(old, old + old.size(), playerProjectile, [](Projectile* p){ p->move(); });
  //MOVE EVERY PLAYER PROJECTILE
  //std::cout << "PLAYER PROJECTILE SIZE:  " << playerProjectile.size() << std::endl;
  /*auto movePro = [&](std::unique_ptr<Projectile>& p, std::unique_ptr<sf::Sprite>& sp){
    p->move();
    sp->setPosition(p->GetX(),p->GetY());  
  };
  std::transform(playerProjectile.begin(), playerProjectile.begin() + playerProjectile.size(), playerProjectileSprite.begin(), movePro);*/
  auto it=playerProjectile.begin();
  auto it1 = playerProjectileSprite.begin();
  for(; it != playerProjectile.end() && it1 != playerProjectileSprite.end(); ++it, ++it1 )
  {
    it->get()->move();
    it1->get()->setPosition(it->get()->GetX(), it->get()->GetY());
  }

}


void Game::updateEnemies()
{
    auto it = enemies.begin();
    auto it1 = enemiesSprite.begin();
    
    for(; it != enemies.end() && it1 != enemiesSprite.end(); ++it, ++it1 )
    {
      it->get()->move(tick);
      it1->get()->setPosition(it->get()->GetX(),it->get()->GetY());
      //std::cout << it1->get()->getPosition().y << std::endl;
    }
}

void Game::render(sf::RenderWindow& w)
{
  int playerX = (player.GetX() - playerWidth);
  int playerY = (player.GetY() - playerHeight);
  playerSprite.setPosition(playerX, playerY);
  w.draw(playerSprite);

  //DRAW PROJECTILES
  // INIT TEXTURE THEN SET TEXTURE FOR ALL SPRITES IN VECTOR; THEN SET SPRITE POSITION
  //std::for_each(playerProjectileSprite.cbegin(), playerProjectileSprite.cend(),[&](std::unique_ptr<sf::Sprite> sp){ w.draw(*sp);  } );
  for(auto& e : playerProjectileSprite)
  {
    w.draw(*e);
  }

  for(auto& e: enemiesSprite)
  {
    w.draw(*e);
  }
}

void Game::victory()
{
  std::cout << "YOU WIN" << std::endl;
}

void Game::spawnEnemy()
{
  Json::StreamWriterBuilder builder;
 // std::cout << tick << std::endl;
  if( data[currentEnemy]["tickSpawn"].asBool() && std::stoi(Json::writeString(builder, data[currentEnemy]["tickSpawn"])) == tick)
  {
    std::cout <<
          "X: " << std::stoi(Json::writeString(builder, data[currentEnemy]["x"])) <<
          "Y  " << std::stoi(Json::writeString(builder, data[currentEnemy]["y"])) << 
          "spd  " <<  std::stof(Json::writeString(builder, data[currentEnemy]["speed"])) <<
          "life   " << std::stoi(Json::writeString(builder, data[currentEnemy]["life"])) << 
          "damage   " << std::stoi(Json::writeString(builder, data[currentEnemy]["damage"])) << std::endl;
    std::unique_ptr<Enemy> tmpEnemy(new Enemy(
          std::stoi(Json::writeString(builder, data[currentEnemy]["x"])),
          std::stoi(Json::writeString(builder, data[currentEnemy]["y"])),
          std::stof(Json::writeString(builder, data[currentEnemy]["speed"])),
          std::stoi(Json::writeString(builder, data[currentEnemy]["life"])),
          std::stoi(Json::writeString(builder, data[currentEnemy]["damage"])),
          data[currentEnemy]["move"].asString()
          ));

    std::unique_ptr<sf::Sprite> tmpSprite(new sf::Sprite);
    tmpSprite->setTexture(*enemiesSpriteTexture[currentEnemy]); 
    tmpSprite->setPosition(tmpEnemy.get()->GetX(), tmpEnemy.get()->GetY());
    enemiesSprite.push_back(std::move(tmpSprite));
    enemies.push_back(std::move(tmpEnemy));
    std::cout << "ENEMY SPAWNED" << std::endl;
    ++currentEnemy;
  }
}

void Game::initLevel()
{
  /*Json::StreamWriterBuilder builder;
  std::map<std::string, std::any> tmpMap;
  for( auto e: data)
  {
    tmpMap["id"] = std::stoi(Json::writeString(builder,e["id"]));
    tmpMap["textureFile"] = Json::writeString(builder,e["textureFile"]);
    tmpMap["tickSpawn"] = Json::writeString(builder,e["tickSpawn"]);
    tmpMap["x"] = std::stoi(Json::writeString(builder,e["x"]));
    tmpMap["y"] = std::stoi(Json::writeString(builder,e["y"]));
    tmpMap["move"] = Json::writeString(builder,e["move"]);
    tmpMap["projectile"] = Json::writeString(builder,e["projectile"]);
    
    //PUSH TO LEVEL VECTOR
    level.push_back(tmpMap);
  }
  std::cout << "MAP SIZE:  " << level[0].size() << std::endl;
  if(level.size() == 3)
    std::cout << "LEVEL LOADED" << std::endl;*/



  //load textures
  for(auto e: data)
  {
    std::cout << "LOAD TEXTURES" << std::endl;
    std::unique_ptr<sf::Texture> tmpTexture(new sf::Texture);
    tmpTexture->loadFromFile(e["textureFile"].asString());
    enemiesSpriteTexture.push_back(std::move(tmpTexture));

  }
}

