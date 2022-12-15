#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/Window/Window.hpp>
#include <memory>
#include <vector>
#include <string>
#include "entity.h"
#include "enemy.h"
#include "player.h"
#include "projectile.h"
#include <SFML/Graphics.hpp>
#include <filesystem>
#include <jsoncpp/json/json.h>
class Game{
  private:
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

    std::vector<std::unique_ptr<Projectile>> playerProjectile;
    std::vector<std::unique_ptr<sf::Sprite>> playerProjectileSprite;
    sf::Texture playerProjectileTexture;


    bool gameRunning{false};

    sf::Texture playerTexture;
    sf::Sprite playerSprite; 
    sf::FloatRect playerHitbox;

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
    ///The shoot function creates a \ref Projectile object with gets pushed to the \ref enemyProjectile vector.
    ///A vertex also get added to \ref enemyProjectileVertices vertex array. 
    ///After the first loop a second loop is used to update all the enemy \ref Projectile objects and their equivilant vertices.
    void updateEnemyProjectile();
    ///Creates enemy objects 
    ///
    ///This function creates enemy objects based on the level json file.
    ///If the tick matches the tickSpawn an enemy object pointer is created and pushed
    ///to \ref enemies vector.
    ///The equivilant sprite is also pushed to the \ref enemiesSprite vector. 
    void spawnEnemy();
    ///Updates every enemy
    ///
    ///Loops through every \ref Enemy object in the \ref enemies vector.
    ///Every loop the \ref Enemy::move function is called and the sprite position is 
    ///moved based on the new coordinates of the \ref Enemy object
    void updateEnemies();
    ///Draws every sprite och vertices
    ///
    ///The function draws the player sprite, enemy sprite and playerProjectileSprite 
    ///indivudually with one draw call per sprite.
    ///But \ref enemyProjectileVertices is drawn using a single draw call because it is a VertexArray.
    ///@param w The window to which the sprites will be drawn on.
    void render(sf::RenderWindow& w);
    ///Checks win condition, closes game if satisfied
    ///
    ///This function checks the last element in the level json file
    ///the element specifies what tick the game will be over.
    ///If the tick has passed and there are no enemies on the screen and
    ///the player is close to the top of the screen the game closes.
    void victory();
    ///Loads enemy textures
    ///
    ///Loops through all the data in the json file but only
    ///pushing the texture png path. The png file is loaded to a texture and 
    ///the pushed to a vector of enemy textures
    void initLevel();
    ///Checks collision between to FloatRects
    ///
    ///This function checks if two rectangles collide.
    ///@param a The first rectangle
    ///@param b The second rectangle
    ///@returns true if the rectangles collide
    bool AABB(sf::FloatRect a, sf::FloatRect b) const;
    
};
#endif // !GAME_H
