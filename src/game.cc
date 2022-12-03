//g++ test.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
#include "game.h"
#include <jsoncpp/json/json.h>
#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>
#include <filesystem>
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
  Player player((windowWidth - playerWidth)/2, (600 - playerHeight), 10.0, 2, 15);
  playerSprite.setPosition(player.GetX(), player.GetY());

  std::cout << "CURRENT PATH IS " << std::filesystem::current_path() << std::endl;
}

void Game::collisionCheck()
{
  //TO DO
  //CHECK IF OBJECT COORDS OVERLAP
  //USE GAME VECTOR FOR ENEMY PROJECTILE TO CHECK AGAISNT PLAYER
}

void Game::update(sf::Event& e, sf::RenderWindow& w)
{
  //RUN EVERYTHING TO HAPPEN EVERY TICK

  while (w.pollEvent(e))
  {
    if (e.type == sf::Event::Closed)
       w.close();
    else if(e.type == sf::Event::KeyPressed)
      player.move(e);
    
 }  
}

void Game::render(sf::RenderWindow& w) const
{
  w.draw(playerSprite);
}
