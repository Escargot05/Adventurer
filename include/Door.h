#ifndef DOOR_H_
#define DOOR_H_
#include "Wall.h"
#include "Hero.h"

class Door : public Wall
{
private:
    bool m_opened;
public:
    Door();
    Door(sf::Color l_color, int x, int y);
    ~Door();

    void Collision(Monster &l_monster);     //Checking collisions with monsters and player and set flag if is open
    bool GetOpened();

};

#endif
