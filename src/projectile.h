#ifndef PROJECTILE_H
#define PROJECTILE_H
#include <map>
#include <string>
#include "entity.h" 
class Projectile : public Entity
{
  private:
    int dmg{0};
    std::map<std::string,int> movement;
  public:
    Projectile();
    Projectile(int xc, int yc, float spd, int l, int dmg, std::map<std::string, int> mv);
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



};

#endif
