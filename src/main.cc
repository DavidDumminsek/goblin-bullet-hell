#include "game.h"
#include "player.h"
#include <SFML/Graphics.hpp>
#include <map>
#include <string>
int main (int argc, char *argv[])
{
  Game game;  
  std::map<std::string, int> mv = {{"a", 0}};
  Player p{10,10,20.0,2, 20, mv};
  sf::RenderWindow window(sf::VideoMode(360, 640 ), "SFML works!");

  while (window.isOpen())
  {
      sf::Event event;
      while (window.pollEvent(event))
      {
        if (event.type == sf::Event::Closed)
           window.close();
      }

      window.clear();
      window.display();
  }

  return 0;
}
