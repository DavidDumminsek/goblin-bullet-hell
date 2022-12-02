#ifndef ENEMY_H
#define ENEMY_H
#include "entity.h"
#include "projectile.h"
class Enemy : public Entity
{
  private:
    Projectile pro;
  public:
    Enemy(int xc, int yc, float spd, int l, int dmg, std::map<std::string, int> mv) : Entity(xc, yc, spd, l){}
    ~Enemy() override;
    void shoot() override;
};
#endif
