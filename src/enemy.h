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
    int dmg;
    int enemyNumber;
    sf::Sprite enemySprite;
    sf::Texture enemyTexture;
    std::string movement;
    std::string movementProjectile;
    void triShot();
    void zigzagShoot();
    void standardShoot();

    void moveRight();
    void moveLeft();
  public:
    Enemy(float xc, float yc, float spd, int l, int dmg, std::string mv, std::string mvPro, int current);
    ~Enemy() override;
    void move(int tick) override;
    std::unique_ptr<Projectile> shoot(int tick);
    sf::Sprite& getSprite();
};
#endif
