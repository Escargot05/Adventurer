#ifndef ESCAPINGKEY_H_
#define ESCAPINGKEY_H_
#include "Key.h"
#include "AdvancedMonster.h"
#include "Hero.h"

class EscapingKey : public Key, public AdvancedMonster
{
public:
    EscapingKey();
    EscapingKey(sf::Color l_color, int x, int y);
    ~EscapingKey();

    void Search(Hero l_hero);           //Checking absence of hero in range and moving opposite to its direction
};

#endif
