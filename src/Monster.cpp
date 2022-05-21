#include "Monster.h"

Monster::Monster(){}

Monster::Monster(sf::Color l_color, int x, int y) : Entity(l_color, x, y){
m_direction = none;
}

Monster::~Monster(){}

void Monster::Move(){
    if(m_direction == up){
        m_body.move(0, -16);
    }else if(m_direction == down){
        m_body.move(0, 16);
    }else if(m_direction == right){
        m_body.move(16, 0);
    }else if(m_direction == left){
        m_body.move(-16, 0);
    }
}

void Monster::DrawDirection(){
    m_direction =  static_cast<Direction>(rand() % 4 + 1);
}

Direction Monster::GetDirection() { return m_direction; }

void Monster::SetDirection(Direction l_direction) { m_direction = l_direction; }
