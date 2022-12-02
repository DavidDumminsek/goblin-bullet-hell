#ifndef PLAYER_H
#define PLAYER_H
#include "entity.h"
#include "projectile.h"
class Player : public Entity
{
  private:
    Projectile pro;
  public:
    Player(int xc, int yc, float spd, int l, int dmg, std::map<std::string, int> mv) : Entity(xc, yc, spd, l){}
    ~Player() = default;
    void shoot() override;
    void move() override;
};
#endif
