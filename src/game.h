#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/Window/Window.hpp>
#include <memory>
#include <vector>
#include <map>
#include <string>
#include "entity.h"
#include "enemy.h"
#include "player.h"
#include "projectile.h"
#include <SFML/Graphics.hpp>
#include <filesystem>
#include <jsoncpp/json/json.h>
#include <any>
class Game{
  private:
    std::vector<std::map<std::string, std::any>> level;
    Json::Value data;
    int currentEnemy;
    int tick{0};

    std::vector<std::unique_ptr<Enemy>> enemies;
    std::vector<std::unique_ptr<sf::Sprite>> enemiesSprite;
    std::vector<std::unique_ptr<sf::Texture>> enemiesSpriteTexture;
    
    std::vector<std::unique_ptr<Projectile>> enemyProjectile;
    std::vector<std::unique_ptr<sf::Sprite>> enemyProjectileSprite;
    sf::Texture projectileTexture; 

    sf::VertexArray enemyProjectileVertices;
    size_t const totalBullets{48000};
    std::vector<std::unique_ptr<sf::Texture>> enemyProjectileSpriteTexture;

    std::vector<std::unique_ptr<Projectile>> playerProjectile;
    std::vector<std::unique_ptr<sf::Sprite>> playerProjectileSprite;


    bool gameRunning{false};

    sf::Texture texture;
    sf::Sprite playerSprite; 
    sf::FloatRect playerHitbox;
    sf::Texture playerProjectileTexture;

    Player player;
    float playerWidth;
    float playerHeight;

    float windowWidth;
    float windowHeight;
  public:
    Game(sf::RenderWindow& w);
    ///Handles all collision between player and enemy objects. Including culling out of view enemies.
    ///
    ///This function loops through every vector of objects and deletes and modifies objects where relevent
    void collisionCheck();
    ///Updates all the object.
    ///
    ///This function updates all the object by calling the relevant update functions found in the \ref Game class
    void update();
    ///Creates and updates \ref Projectile object belonging to the \ref Player class
    ///
    ///This function creates a \ref Projectile object by calling the \ref Player::shoot function and 
    ///pushing it into a vector of \ref Projectile pointers. 
    ///After createing a projectile the function loops through all existing projectiles and updates them with 
    ///by calling the \ref Projectile::move function
    void updatePlayerProjectile();
    ///Updates and creates enemy \ref Projectile objects
    ///
    ///This function loops through all \ref Enemy objects and calls their shoot function.
    ///The shoot function creates a \ref Projectile object with gets pushed to the \ref Game::enemyProjectile vector.
    ///A vertex also get added to \ref enemyProjectileVertices vertex array. 
    ///After the first loop a second loop is used to update all the enemy \ref Projectile objects and their equivilant vertices.
    void updateEnemyProjectile();
    void spawnEnemy();
    void updateEnemies();
    void render(sf::RenderWindow& w);
    void victory();
    void initLevel();
    bool AABB(sf::FloatRect a, sf::FloatRect b);
    
};
#endif // !GAME_H
