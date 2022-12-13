#include "level.h"
#include <jsoncpp/json/writer.h>
#include <jsoncpp/json/json.h>
#include <iostream>
#include <fstream>

Level::Level()
{
  std::ifstream file("../src/levels/level1.json");
  if(file) 
    std::cout << "FILE EXISTS" << std::endl;
  else
    std::cout << "FILE DOESN'T EXSIST" << std::endl;
  Json::Reader reader;
  reader.parse(file, data);

  std::cout << "JSON DATA " << std::endl;
  std::cout << data << std::endl;

}

Level::Level(std::string path)
{
  std::ifstream file(path);
  if(file) 
    std::cout << "FILE EXISTS" << std::endl;
  else
    std::cout << "FILE DOESN'T EXSIST" << std::endl;
  Json::Reader reader;
  reader.parse(file, data);

  std::cout << "JSON DATA " << std::endl;
  std::cout << data << std::endl;
}

Json::Value Level::getData()
{
  return data;
}
