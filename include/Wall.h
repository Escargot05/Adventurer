#ifndef WALL_H_
#define WALL_H_
#include "Monster.h"
#include "AdvancedMonster.h"

class AdvancedMonster;

class Wall : public Entity
{
public:
    Wall();
    Wall(sf::Color l_color, int x, int y);
    ~Wall();

    void Collision(Monster &l_monster);             //Checks moving entities collisions
    void Collision(AdvancedMonster &l_advanced);    //Checks moving entities collisions and allows to change direction
};

#endif
