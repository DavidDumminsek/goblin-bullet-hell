#ifndef OBJECT_H
#define OBJECT_H

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/VertexArray.hpp>
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
    size_t const totalBullets{48000};
    sf::VertexArray enemyProjectileVertices;
    std::vector<std::unique_ptr<Projectile>> enemyProjectile;
    std::vector<std::unique_ptr<sf::Sprite>> enemyProjectileSprite;

    //player
    Player player;
    sf::Texture playerTexture;
    sf::Sprite playerSprite; 

    //player projectiles
    sf::VertexArray playerProjectileVertices;
    std::vector<std::unique_ptr<Projectile>> playerProjectile;
    std::vector<std::unique_ptr<sf::Sprite>> playerProjectileSprite;

    //projectile sprite sheet
    sf::Texture projectileTexture;

    //level
    Level level;
    int currentEnemy{0};
 
    //tick
    int tick{0};


    
  public:
    ObjectManager(sf::RenderWindow& w, std::string pathToLevel);


    ///Function for initiating player object
    ///
    ///This function creates a player object and assigns it 
    ///to the local \ref ObjectManager::player.
    ///With the x coordinates equivilant to the middle of the window.
    ///And the y coordinates 600 - the height of the player texture.
    ///@param w Uses window to center the player sprite correclty
    ///@returns void
    void initPlayer(sf::RenderWindow& w);

    ///Updates all objects
    ///
    ///This function updates all the object in this class.
    ///By calling all the relevant functions 
    void update();

    ///Update player object and sprite
    ///
    ///Calls the move function of player object and 
    ///sets the sprite position to new player coordinates
    void updatePlayer();

    ///Function for creating enemies
    ///
    ///This function creates a pointer \ref Enemy object based on 
    /// the \ref Level object member variables. The pointer is then pushed into a vector 
    /// of Enemy pointers... TO BE CHANGED 
    /// @param level A level object which contains data from the level. Describing the enemy to be created.
    /// @returns void
    void spawnEnemy(Level level);

    ///Function to load textures
    ///
    ///Stores textures into a vector of textures.
    ///@param level A level object which contains data from the level. Tells how many enemies and what
    ///order they will be created in. 
    void loadEnemyTextures(Level level);

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
    ///@returns void
    void updateEnemyProjectiles();

    ///Function which deletes sprites that are not visible
    ///
    ///Erases enemies and enemy bullets from their respective vectors.
    ///In turn freeing the memory allocated to them
    ///@returns void
    void deleteNonVisible();

    ///Renders all sprites and vertices
    ///
    ///Goes through all the sprites in the vectors
    ///and draws the VertexArray for enemy projectiles
    ///@param w Window to where to draw the sprites
    void render(sf::RenderWindow& w) const;

    //!Get function for tick integer
    int getTick() const;

  

    
};
#endif
