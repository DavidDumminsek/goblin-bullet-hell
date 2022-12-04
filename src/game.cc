//g++ test.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
#include "game.h"
#include "projectile.h"
#include <algorithm>
#include <jsoncpp/json/json.h>
#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>
#include <filesystem>
#include <ostream>
Game::Game(sf::RenderWindow& w)
{ 
  std::ifstream file("../src/levels/level1.json");
  if(file) 
    std::cout << "FILE EXISTS" << std::endl;
  else
    std::cout << "FILE DOESN'T EXSIST" << std::endl;
  Json::Reader reader;
  Json::Value data;
  reader.parse(file, data);

  //test
  std::cout << "JSON DATA " << std::endl;
  std::cout << data << std::endl;

  //init player sprite
  texture.loadFromFile("../src/sprites/player.png");
  //playerSprite = new sf::Sprite(texture);
  playerSprite.setTexture(texture);
  playerWidth = playerSprite.getTexture()->getSize().x;
  playerHeight = playerSprite.getTexture()->getSize().y;
  windowWidth = w.getSize().x;
  windowHeight = w.getSize().y;
  Player player((windowWidth - playerWidth)/2, (600 - playerHeight), 1.f, 2, 15);
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
  if(playerProjectile.size() > 1)
  {
    std::cout << playerProjectile[0]->GetY() << std::endl;
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
  collisionCheck();
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
}
