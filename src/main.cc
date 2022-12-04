#include "game.h"
#include "player.h"
#include <SFML/Graphics.hpp>
#include <map>
#include <string>
int main (int argc, char *argv[])
{
  sf::RenderWindow window(sf::VideoMode(360, 640 ), "SFML works!");
  window.setFramerateLimit(144);
  Game game(window);  

  while (window.isOpen())
  {
      sf::Event event;
      game.update(event, window);

      window.clear();
      //render
      game.render(window); 
      window.display();
  }

  return 0;
}
