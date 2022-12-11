#ifndef ENTITY_H
#define ENTITY_H
#include <utility>
#include<string>
#include<map>
class Entity
{
  protected:
    int x{0};
    int y{0};
    float speed{0.0};
    int life{0};
  public:
    Entity();
    Entity( int xc, int yc, float spd, int l);
    //copy constructor
    Entity(const Entity& rhs) = default;
    //move constructor
    Entity(Entity&& rhs) = default;
    virtual ~Entity() = default;
    //copy assigment
    Entity& operator=(const Entity& rhs) = default;
    //move assigment
    Entity& operator=(Entity&& rhs) = default;
    void virtual move();
    void die();
    int GetX() const;
    int GetY() const;
};

#endif
