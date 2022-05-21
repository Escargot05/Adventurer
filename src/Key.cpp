#include "Key.h"
#include "Hero.h"

Key::Key(){};

Key::Key(sf::Color l_color, int x, int y): Entity(l_color, x, y){};

Key::~Key(){};

bool Key::isCollected(Hero &l_hero){
    sf::FloatRect keyBounds = m_body.getGlobalBounds();
    sf::FloatRect heroBounds = l_hero.GetBounds();
    if(keyBounds.intersects(heroBounds)){
        l_hero.KeyCollected();
        return true;
    }else { return false; };
}
