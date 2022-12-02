#include "game.h"
#include <SFML/Graphics.hpp>
int main (int argc, char *argv[])
{
  Game game;  
  
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
