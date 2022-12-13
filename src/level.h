#ifndef LEVEL_H
#define LEVEL_H

#include <SFML/Graphics.hpp>
#include <jsoncpp/json/value.h>
#include <memory>
#include <string>
class Level
{
  private:
    Json::Value data;

  public:
    Level();
    Level(std::string path);

    ///Loads json file
    ///
    ///Takes path and loads json file into \ref Level::data
    ///@param path Path to json file
    void load(std::string path);
    
    Json::Value getData();


};

#endif
