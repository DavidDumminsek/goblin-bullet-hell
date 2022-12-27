#ifndef ENTITY_H
#define ENTITY_H
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Vertex.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <utility>
#include<string>
#include<map>
#include <SFML/Graphics.hpp>
//forward declaration
class Projectile;
class Entity
{
  protected:
    int dmg{0};
    float x{0};
    float y{0};
    float speed{0.0};
    int life{0};
    sf::VertexArray quad; 
    sf::FloatRect hitbox;
    std::string entityType;
    bool collision;
    std::string texture;
  public:
    Entity();
    Entity( std::string tex, float xc, float yc, float spd, int l);
    //copy constructor
    Entity(const Entity& rhs) = default;
    //move constructor
    Entity(Entity&& rhs) = default;
    ~Entity() = default;
    //copy assigment
    Entity& operator=(const Entity& rhs) = default;
    //move assigment
    Entity& operator=(Entity&& rhs) = default;
    //!Pure virtual function to be overwritten
    void virtual move(int tick) = 0;
    //!Pure virtual update function
    void virtual update(int tick) = 0;
    ///Changes \ref life variable
    ///
    ///This function changes life varible based on \ref dmg parameter
    ///@param dmg How much life is to be removed
    ///@returns true if life becomes 0, false if life is greater than 0
    bool takeDmg(int dmg);
    ///Returns \ref dmg
    ///
    ///@returns \ref dmg
    int getDmg();
    ///Returns \ref x
    ///
    ///@returns \ref x
    int GetX() const;
    ///Returns \ref y
    ///
    ///@returns \ref y
    int GetY() const;

    std::string getType() const;

    sf::FloatRect getHitbox() const;

    void virtual changeQuadPos();

    sf::VertexArray getQuad();

    std::unique_ptr<Projectile> virtual shoot(int tick) = 0;

    void virtual initTexCoords();

};

#endif
