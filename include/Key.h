#ifndef KEY_H_
#define KEY_H_
#include "Hero.h"

class Hero;

class Key : virtual public Entity
{
public:
    Key();
    Key(sf::Color l_color, int x, int y);
    ~Key();

    bool isCollected(Hero &l_hero);             //Checking being collected by player
};

#endif
