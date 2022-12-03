#include "game.h"
#include "player.h"
#include <SFML/Graphics.hpp>
#include <map>
#include <string>
int main (int argc, char *argv[])
{
  Player p{10,10,20.0,2, 20};
  sf::RenderWindow window(sf::VideoMode(360, 640 ), "SFML works!");
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
