#include "EscapingKey.h"

EscapingKey::EscapingKey(){};

EscapingKey::EscapingKey(sf::Color l_color, int x, int y): Entity(l_color, x, y), Monster(l_color, x, y), Key(l_color, x, y){};

EscapingKey::~EscapingKey(){};

void EscapingKey::EscapingKey::Search(Hero l_hero){

    int ax = l_hero.GetPosition().x + 8;
    int ay = l_hero.GetPosition().y + 8;
    int x = m_body.getPosition().x + 8;
    int y = m_body.getPosition().y + 8;
    float range = sqrt(pow(ax - x, 2) + pow(ay - y, 2));

    if(range < 46) { m_aim = sf::Vector2f(ax, ay); };

    if((m_aim.x == 0 && m_aim.y == 0) || (range > 46)){
        m_direction = none;
    }else if(m_aim.x == x && m_aim.y < y){
        m_direction =  down;
        m_assistant = right;
    }else if(m_aim.x > x && m_aim.y == y){
        m_direction =  left;
        m_assistant = up;
    }else if(m_aim.x == x && m_aim.y > y){
        m_direction =  up;
        m_assistant = right;
    }else if(m_aim.x < x && m_aim.y == y){
        m_direction = right;
        m_assistant = up;
    }else if(m_aim.x > x && m_aim.y < y){
        m_direction =  static_cast<Direction>(rand() % 2 + 3);
    }else if(m_aim.x > x && m_aim.y > y){
        int aux = rand() % 2 + 4;
        if(aux == 5) { aux = 1; };
        m_direction =  static_cast<Direction>(aux);
    }else if(m_aim.x < x && m_aim.y > y){
        m_direction =  static_cast<Direction>(rand() % 2 + 1);
    }else if(m_aim.x < x && m_aim.y < y){
        m_direction =  static_cast<Direction>(rand() % 2 + 2);
    }
};
