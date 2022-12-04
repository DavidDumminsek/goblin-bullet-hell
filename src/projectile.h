#ifndef PROJECTILE_H
#define PROJECTILE_H
#include <map>
#include <string>
#include "entity.h" 
class Projectile : public Entity
{
  private:
    int dmg{0};
    std::string movement;
  public:
    Projectile();
    Projectile(int xc, int yc, float spd, int l, int dmg);
    Projectile(int xc, int yc, float spd, int l, int dmg, std::string mv);
    ~Projectile() = default;
    //Copy conttructor
    //to be added
    Projectile(const Projectile& rhs) = default;
    //move constructor
    Projectile(Projectile&& rhs) = default;
    //copy assigment
    Projectile& operator=(const Projectile& rhs) = default;
    //move assigment
    Projectile& operator=(Projectile&& rhs) = default;
    //move
    void move();



};

#endif
