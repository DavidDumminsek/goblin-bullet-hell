#ifndef OBJECT_H
#define OBJECT_H

#include <SFML/Graphics.hpp>
#include <string>
#include <memory>

//header files
#include "enemy.h"
#include "player.h"
#include "projectile.h"
#include "level.h"

class ObjectManager
{
  private:
    //enemies
    std::vector<std::unique_ptr<Enemy>> enemies;
    std::vector<std::unique_ptr<sf::Sprite>> enemiesSprite;
    std::vector<std::unique_ptr<sf::Texture>> enemiesSpriteTexture;

    //enemy projectiles
    std::vector<std::unique_ptr<Projectile>> enemyProjectile;
    std::vector<std::unique_ptr<sf::Sprite>> enemyProjectileSprite;
    std::vector<std::unique_ptr<sf::Texture>> enemyProjectileSpriteTexture;

    //player
    Player player;
    sf::Texture playerTexture;
    sf::Sprite playerSprite; 

    //player projectiles
    sf::Texture playerProjectileTexture;
    std::vector<std::unique_ptr<Projectile>> playerProjectile;
    std::vector<std::unique_ptr<sf::Sprite>> playerProjectileSprite;
    
  public:
    ///Function for initiating player object
    ///
    ///This function creates a player object and assigns it 
    ///to the local \ref ObjectManager::player.
    ///With the x coordinates equivilant to the middle of the window.
    ///And the y coordinates 600 - the height of the player texture.
    ///@returns void
    void initPlayer();


    ///Function for creating enemies
    ///
    ///This function creates a pointer \ref Enemy object based on 
    /// the \ref Level object member variables. The pointer is then pushed into a vector 
    /// of Enemy pointers... TO BE CHANGED 
    /// @param level A level object which contains data from the level. Describing the enemy to be created.
    /// @returns void
    void spawnEnemy(Level level);

    ///Function for updating enemies
    ///
    /// This function updates the enemies by changing their coordinates and moving their sprites.
    /// @returns void
    void updateEnemies();

    ///Function for updating and creating projectiles for enemies
    ///
    ///This function loops through every enemy in the \ref ObjectManager::enemies and calls their
    /// \ref Enemy::shoot function to create a \ref Projectile object which gets pushed into a 
    ///  \ref sf::VertexArray.
    void updateEnemyProjectiles();

    
};
#endif
