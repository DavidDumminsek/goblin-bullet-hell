#ifndef PROJECTILE_H
#define PROJECTILE_H
#include <map>
#include <string>
#include "entity.h" 
class Projectile : public Entity
{
  private:
    int dmg{0};
  public:
    Projectile();
    Projectile(int xc, int yc, float spd, int l, int dmg, std::map<std::string, int> mv) : Entity(xc, yc, spd, l){}
    ~Projectile() = default;
    //Copy conttructor
    //to be added



};

#endif
