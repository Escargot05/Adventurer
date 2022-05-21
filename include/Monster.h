#ifndef MONSTER_H_
#define MONSTER_H_
#include<time.h>
#include "Entity.h"

enum Direction{none, up, right, down, left};

class Monster : virtual public Entity
{
protected:
    Direction m_direction;          //The intended direction of movement
public:
    Monster();
    Monster(sf::Color l_color, int x, int y);
    ~Monster();

    void Move();                    //Moving in saved direction by one space
    void DrawDirection();           //Drawing one from four possible directions
    Direction GetDirection();
    void SetDirection(Direction l_direction);

};

#endif

