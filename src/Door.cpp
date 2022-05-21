#include "Door.h"

Door::Door(){};

Door::Door(sf::Color l_color, int x, int y): Wall(l_color, x, y){
    m_opened = false;
};

Door::~Door(){};

void Door::Collision(Monster &l_monster){
    sf::FloatRect doorBounds = m_body.getGlobalBounds();
    sf::FloatRect monsterBounds = l_monster.GetBounds();
    Direction dir = l_monster.GetDirection();
    Hero* l_hero = dynamic_cast<Hero*>(&l_monster);

        if(dir == right){
            monsterBounds.left += 1;
            if(doorBounds.intersects(monsterBounds)){
                if(l_hero == NULL || !l_hero->UseKey()){
                l_monster.SetDirection(none);
                }else{ m_opened = true; };
            }
        }else if(dir == left){
            monsterBounds.left -= 1;
            if(doorBounds.intersects(monsterBounds)){
                if(l_hero == NULL || !l_hero->UseKey()){
                l_monster.SetDirection(none);
                }else{ m_opened = true; };
            }
        }else if(dir == up){
            monsterBounds.top -= 1;
            if(doorBounds.intersects(monsterBounds)){
                if(l_hero == NULL || !l_hero->UseKey()){
                l_monster.SetDirection(none);
                }else{ m_opened = true; };
            }
        }else if(dir == down){
            monsterBounds.top += 1;
            if(doorBounds.intersects(monsterBounds)){
                if(l_hero == NULL || !l_hero->UseKey()){
                l_monster.SetDirection(none);
                }else{ m_opened = true; };
            }
        }
}

bool Door::GetOpened() { return m_opened; }
