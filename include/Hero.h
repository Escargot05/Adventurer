#ifndef HERO_H_
#define HERO_H_
#include "Monster.h"
#include "Key.h"

class Hero : public Monster
{
private:
    int m_lives;
    int m_keys;
    bool m_breath;                  //Flag to pause game after player death
    sf::Vector2f m_spawnPoint;
public:
    Hero();
    Hero(sf::Color l_color, int x, int y);
    ~Hero();

    void KeyCollected();                            //Collecting key
    bool UseKey();                                  //Opening door
    void HasBeenHitted(Monster &l_monster);         //Set player on spawn point
    bool IsDead();                                  //Checking if player still alive
    void TakeBreath();                              //Pausing game for few second after player death
    int GetLives();
    int GetKeys();
    void SetEquipment(int l_lives, int l_keys);

};

#endif
