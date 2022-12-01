#ifndef GAME_H
#define GAME_H
#include <vector>
#include <map>
#include <string>
#include "enemy.h"
#include "projectile.h"
class Game{
  private:
    std::vector< std::map<std::string, int> > level;
    int tick{0};
    std::vector<Enemy> enemies;
    std::vector<Projectile> enemyProjectile;
    std::vector<Projectile> playerProjectile;
    bool gameRunning{false};
  public:
    Game();
    void collisionCheck();
    void update();
    void render();
    void victory();
    void spawnEnemy();
    void updateProjectile();
    
};
#endif // !GAME_H
