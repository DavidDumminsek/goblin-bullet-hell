//g++ test.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
#include "game.h"
#include <jsoncpp/json/json.h>
#include <iostream>
#include <fstream>
Game::Game()
{ 
  std::ifstream file("levels/level1.json");
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
}
