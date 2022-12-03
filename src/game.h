#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Window/Window.hpp>
#include <vector>
#include <map>
#include <string>
#include "entity.h"
#include "enemy.h"
#include "player.h"
#include "projectile.h"
#include <SFML/Graphics.hpp>
#include <filesystem>
class Game{
  private:
    std::vector< std::map<std::string, int> > level;
    int tick{0};
    std::vector<Enemy> enemies;
    std::vector<Projectile> enemyProjectile;
    std::vector<Projectile> playerProjectile;
    bool gameRunning{false};
    sf::Texture texture;
    sf::Sprite playerSprite; 
    Player player;
    int playerWidth;
    int playerHeight;
    int windowWidth;
    int windowHeight;
  public:
    Game(sf::RenderWindow& w);
    void collisionCheck();
    void update(sf::Event& e, sf::RenderWindow&  w);
    void render(sf::RenderWindow& w) const;
    void victory();
    void spawnEnemy();
    void updateProjectile();
    
};
#endif // !GAME_H
