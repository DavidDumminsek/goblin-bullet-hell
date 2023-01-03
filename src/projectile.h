#ifndef PROJECTILE_H
#define PROJECTILE_H
#include <map>
#include <memory>
#include <string>
#include "entity.h" 
class Projectile : public Entity
{
  private:
    std::string movement;
    int moveTimer{0};
  public:
    Projectile();
    Projectile(std::string tex, float xc, float yc, float spd, int l, int dmg);
    Projectile(std::string tex, float xc, float yc, float spd, int l, int dmg, std::string mv);
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
    ///Changes x and y coordinates 
    ///
    ///This function changes the x and y variable members based on
    ///the \ref movment variable member and \ref tick parameter
    ///@param tick Current tick from \ref Game class, can be used to change movement behaviour
    void move(int tick) override;
    ///Calls move and changeQuads functions
    void update(int tick) override;
    ///Creates and returns a projectile object
    std::unique_ptr<Projectile> shoot(int tick) override;
    ///Assigns texcoords for the quads to all the projectile textures in the sprite sheet
    void initTexCoords() override;
    ///Projectle quads is 8x8 while other entities are 32x32
    void changeQuadPos() override;



};

#endif
