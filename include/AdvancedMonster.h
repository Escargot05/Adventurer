#ifndef ADVANCEDMONSTER_H_
#define ADVANCEDMONSTER_H_
#include "Monster.h"
#include "Wall.h"
#include "Hero.h"

class AdvancedMonster : virtual public Monster
{
protected:
    sf::Vector2f m_aim;                     //Coordinates of detected hero
    Direction m_assistant;                  //Direction of move in case of wall collision
public:
    AdvancedMonster();
    AdvancedMonster(sf::Color l_color, int x, int y);
    ~AdvancedMonster();

    virtual void Search(Hero& l_hero);      //Checking absence of hero in range of monster and moving in its direction
    Direction GetAssistant();
};

#endif
