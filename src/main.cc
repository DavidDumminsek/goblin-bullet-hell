#include "game.h"
#include "player.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <map>
#include <string>
int main (int argc, char *argv[])
{
  sf::RenderWindow window(sf::VideoMode(360, 640 ), "SFML works!");
  window.setFramerateLimit(60);
  Game game(window);  

  while (window.isOpen())
  {
      sf::Event event;
      game.update();

      window.clear(sf::Color(135,206,235));
      //render
      game.render(window); 
      window.display();
  }

  return 0;
}
