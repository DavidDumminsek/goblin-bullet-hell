//g++ test.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
#include "game.h"
#include <jsoncpp/json/json.h>
#include <iostream>
#include <fstream>
Game::Game()
{ 
  std::ifstream file("levels/level1.json");
  Json::Reader reader;
  Json::Value completeJsonData;
  reader.parse(file, completeJsonData);

  //test
  std::cout << "JSON DATA " << std::endl << completeJsonData << std::endl;
}
