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

//GAME CLASS FOR INITIATION OF OBJECTS AND GAME LOOP

//LEVEL CLASS FOR JSON LEVEL FILE

//OBJECT MANAGER FOR UPDATING OBJECTS


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
  projectileTexture.loadFromFile("../src/sprites/playerProjectile-sheet.png");
  playerProjectileTexture.loadFromFile("../src/sprites/playerProjectile.png");
  std::cout << "CURRENT PATH IS " << std::filesystem::current_path() << std::endl;

  //VERTEX ARRAY
  enemyProjectileVertices.setPrimitiveType(sf::Quads);
  enemyProjectileVertices.resize(totalBullets);

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

  if(enemies.size() > 0)
  {

    auto it = enemies.begin();
    auto it1 = enemiesSprite.begin();
    
    for(; it != enemies.end() && it1 != enemiesSprite.end();)
    {
      if( it->get()->GetY() > 640 || it->get()->GetX()> 340)
      {
        it = enemies.erase(it);
        it1 = enemiesSprite.erase(it1);
      }
      else
      {
        ++it;
        ++it1;
      }
    }
  }

  if(enemyProjectile.size() > 0)
  {
      for(int i = 0; i < enemyProjectile.size(); i++)
      {
        if(enemyProjectile[i] != nullptr)
        {
          if(enemyProjectile[i]->GetY() > 640 || 
             enemyProjectile[i]->GetX() > 350 ||
            enemyProjectile[i]->GetX() < 0)
          {
           enemyProjectile[i].reset(nullptr);

          sf::Vertex* currentVertex = &enemyProjectileVertices[i*4];
          //MOVE AWAY TIL IT WILL BE REUSED
          currentVertex[0] = sf::Vector2f(0,0);
          currentVertex[1] = sf::Vector2f(0,0);
          currentVertex[2] = sf::Vector2f(0,0);
          currentVertex[3] = sf::Vector2f(0,0);
          std::cout << "COLLISION DONE" << std::endl;
          }
        }
      }

    //separete loop for player collision
      for(int i = 0; i < enemyProjectile.size(); i++)
      {
        if(enemyProjectile[i] != nullptr)
        {
          sf::FloatRect a(enemyProjectile[i]->GetX(), enemyProjectile[i]->GetY(), 8, 8);
          if(AABB(playerSprite.getGlobalBounds(), a))
          {
            if(player.takeDmg(1))
            {
              std::cout << "YOUR DIED" << std::endl;
            }
           enemyProjectile[i].reset(nullptr);

          sf::Vertex* currentVertex = &enemyProjectileVertices[i*4];
          //MOVE AWAY TIL IT WILL BE REUSED
          currentVertex[0] = sf::Vector2f(0,0);
          currentVertex[1] = sf::Vector2f(0,0);
          currentVertex[2] = sf::Vector2f(0,0);
          currentVertex[3] = sf::Vector2f(0,0);
          std::cout << "COLLISION DONE" << std::endl;
          }
        }
      }
  }

    /*auto it = enemyProjectile.begin();

    //separate loop for player collisions
    for(; it != enemyProjectile.end();)
    {
      if(it->get()->GetY() > 640 || 
         it->get()->GetX() > 350 ||
         it->get()->GetX() < 0)
      {
        it = enemyProjectile.erase(it); 
      }
      sf::FloatRect a(it->get()->GetX(), it->get()->GetY(), 8, 8);
      if(AABB(playerSprite.getGlobalBounds(), a))
      {
        std::cout << "PLAYER SPRTIE GOT HIT" << std::endl;
        it = enemyProjectile.erase(it);
        if(player.takeDmg(1))
        {
          std::cout << "YOUR DIED" << std::endl;
        }
      }
      else
        ++it;
      
    }*/
  
}

void Game::update(sf::Event& e, sf::RenderWindow& w)
{
  //RUN EVERYTHING TO HAPPEN EVERY TICK
  while(w.pollEvent(e))
  {
    if (e.type == sf::Event::Closed)
       w.close();
  }
  player.move(tick);

  //PLAYER SHOOT
  updatePlayerProjectile(); 
  spawnEnemy();
  updateEnemies();
  updateEnemyProjectile();
  collisionCheck();
  ++tick;
}

void Game::updatePlayerProjectile()
{
  //INITIERA EN PLAYER PROJEKTIL OM SHOOT FUNKTIONEN RETURNERAR NÅGOT
  std::unique_ptr<Projectile>  temp = player.shoot();
  if(temp)
  {
    playerProjectile.push_back(std::move(temp));
    std::unique_ptr<sf::Sprite> tmpSprite(new sf::Sprite);
    tmpSprite->setTexture(playerProjectileTexture);
    playerProjectileSprite.push_back(std::move(tmpSprite));
  }

  //updatera varje player projectile
  auto it=playerProjectile.begin();
  auto it1 = playerProjectileSprite.begin();
  for(; it != playerProjectile.end() && it1 != playerProjectileSprite.end(); ++it, ++it1 )
  {
    it->get()->move(tick);
    it1->get()->setPosition(it->get()->GetX(), it->get()->GetY());
  }

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
          data[currentEnemy]["move"].asString(),
          data[currentEnemy]["projectile"].asString(),
          currentEnemy
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

void Game::updateEnemyProjectile()
{
  //vertex array attempt
  //add bullet to vertex array
  
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
      quad[1].position = sf::Vector2f(e->GetX() + 8, 
                             e->GetY());
      quad[2].position = sf::Vector2f(e->GetX() + 8,
                             e->GetY() + 8);
      quad[3].position = sf::Vector2f(e->GetX(), 
                             e->GetY() + 8);


      //TEXTURE COORDS IN SPIRTE SHEET HAVE NO SPRITE SHEET ATM  SO SCARY
      quad[0].texCoords = sf::Vector2f(0,0);
      quad[1].texCoords = sf::Vector2f(8, 0);
      quad[2].texCoords = sf::Vector2f(8, 8);
      quad[3].texCoords = sf::Vector2f(0 , 8);
    }

  }

  int y{0};
  for(auto& e : enemyProjectile)
  {
      //skip if projectile is null
      if(e != nullptr)
      {
      
      //point to a quad in vertex array
      auto it = std::find(enemyProjectile.begin(), enemyProjectile.end(), e);     
      size_t i = std::distance(enemyProjectile.begin(), it);
      sf::Vertex* quad = &enemyProjectileVertices[i*4]; 
      e->move(tick); 

      //set quad position
      quad[0].position = sf::Vector2f(e->GetX(), 
                             e->GetY());
      quad[1].position = sf::Vector2f(e->GetX() + enemyProjectileSpriteTexture[y]->getSize().x, 
                             e->GetY());
      quad[2].position = sf::Vector2f(e->GetX() + enemyProjectileSpriteTexture[y]->getSize().x,
                             e->GetY() + enemyProjectileSpriteTexture[y]->getSize().y);
      quad[3].position = sf::Vector2f(e->GetX(), 
                             e->GetY() + enemyProjectileSpriteTexture[y]->getSize().y);
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

  //draw enemy projectiels
  w.draw(enemyProjectileVertices, &projectileTexture);
}

void Game::victory()
{
  std::cout << "YOU WIN" << std::endl;
}


void Game::initLevel()
{
  //load textures
  for(auto e: data)
  {
    //load enemy texture
    std::cout << "LOAD ENEMY TEXTURES" << std::endl;
    std::unique_ptr<sf::Texture> tmpTexture(new sf::Texture);
    tmpTexture->loadFromFile(e["textureFile"].asString());
    enemiesSpriteTexture.push_back(std::move(tmpTexture));

    //load enemy projectile textures
    std::cout << "LOAD ENEMY PROJECTILES" << std::endl;
    std::unique_ptr<sf::Texture> tmpTexture1(new sf::Texture);
    tmpTexture1->loadFromFile(e["projectileFile"].asString());
    enemyProjectileSpriteTexture.push_back(std::move(tmpTexture1));

  }
}


bool Game::AABB(sf::FloatRect a, sf::FloatRect b)
{
  return 
         (b.left < a.left + a.width) &&
         (b.left + b.width > a.left) &&
         (b.top < a.top + a.height) &&
         (b.top + b.height > a.top);   
}


