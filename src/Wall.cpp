#include "Wall.h"

Wall::Wall(){};

Wall::Wall(sf::Color l_color, int x, int y): Entity(l_color, x, y){};

Wall::~Wall(){};

void Wall::Collision(Monster &l_monster){

    sf::FloatRect wallBounds = m_body.getGlobalBounds();
    sf::FloatRect monsterBounds = l_monster.GetBounds();
    Direction dir = l_monster.GetDirection();

        if(dir == right){
            monsterBounds.left += 5;
            if(wallBounds.intersects(monsterBounds)){
                l_monster.SetDirection(none);
                }
        }else if(dir == left){
            monsterBounds.left -= 5;
            if(wallBounds.intersects(monsterBounds)){
                l_monster.SetDirection(none);
                }
        }else if(dir == up){
            monsterBounds.top -= 5;
            if(wallBounds.intersects(monsterBounds)){
                l_monster.SetDirection(none);
                }
        }else if(dir == down){
            monsterBounds.top += 5;
            if(wallBounds.intersects(monsterBounds)){
                l_monster.SetDirection(none);
                }
        }
}

void Wall::Collision(AdvancedMonster &l_advanced){

    sf::FloatRect wallBounds = m_body.getGlobalBounds();
    sf::FloatRect monsterBounds = l_advanced.GetBounds();
    Direction dir = l_advanced.GetDirection();

        if(dir == right){
            monsterBounds.left += 1;
            if(wallBounds.intersects(monsterBounds)){
                l_advanced.SetDirection(l_advanced.GetAssistant());
                }
        }else if(dir == left){
            monsterBounds.left -= 1;
            if(wallBounds.intersects(monsterBounds)){
                l_advanced.SetDirection(l_advanced.GetAssistant());
                }
        }else if(dir == up){
            monsterBounds.top -= 1;
            if(wallBounds.intersects(monsterBounds)){
                l_advanced.SetDirection(l_advanced.GetAssistant());
                }
        }else if(dir == down){
            monsterBounds.top += 1;
            if(wallBounds.intersects(monsterBounds)){
                l_advanced.SetDirection(l_advanced.GetAssistant());
                }
        }
}

