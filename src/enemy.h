#ifndef ENEMY_H
#define ENEMY_H
#include "entity.h"
#include "projectile.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <string>
class Enemy : public Entity
{
  private:
    int enemyNumber;
    std::string movement;
    std::string movementProjectile;
    float pSpeed;
    int fireRate;

    int moveTimer{0};
    int shootTimer{0};
  public:
    Enemy(float xc, float yc, float spd, int l, int dmg, std::string mv, std::string mvPro, float pSpeed, int fireRate, int current);
    ///Changes x and y coordinates 
    ///
    ///This function changes the x and y variable members based on
    ///the \ref movment variable member and \ref tick parameter
    ///@param tick Current tick from \ref Game class, can be used to change movement behaviour
    void move(int tick) override;
    ///Creates and returns a \ref Projectile pointer
    ///
    ///This function creates a projectile pointer.
    ///@param tick Current tick from \ref Game class, used to detirmine how often to create a \ref Projectile
    ///@returns A \ref Projectile if tick is divisible by \ref fireRate
    ///@return nullptr If tick is not divisible by \ref fireRate
    std::unique_ptr<Projectile> shoot(int tick);
    void update(int tick) override;

};
#endif
