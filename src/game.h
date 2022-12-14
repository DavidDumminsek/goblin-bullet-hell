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
    sf::Texture playerProjectileTexture;

    Player player;
    float playerWidth;
    float playerHeight;

    float windowWidth;
    float windowHeight;
  public:
    Game(sf::RenderWindow& w);
    void collisionCheck();
    void update(sf::Event& e, sf::RenderWindow&  w);
    void updatePlayerProjectile();
    void updateEnemyProjectile();
    void spawnEnemy();
    void updateEnemies();
    void render(sf::RenderWindow& w);
    void victory();
    void initLevel();
    bool AABB(sf::FloatRect a, sf::FloatRect b);
    
};
#endif // !GAME_H
