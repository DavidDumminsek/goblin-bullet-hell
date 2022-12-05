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
    sf::Sprite enemySprite;
    sf::Texture enemyTexture;
    std::string movement;
    void triShot();
    void zigzagShoot();
    void standardShoot();

    void moveRight();
    void moveLeft();
  public:
    Enemy(int xc, int yc, float spd, int l, int dmg, std::string mv);
    ~Enemy() override;
    void move(int tick);
    void shoot();
    sf::Sprite& getSprite();
};
#endif
