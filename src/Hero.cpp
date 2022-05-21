#include "Hero.h"

Hero::Hero(){}

Hero::Hero(sf::Color l_color, int x, int y) : Entity(l_color, x, y), Monster(l_color, x, y){
    m_spawnPoint = sf::Vector2f(x * 16, y * 16);
    m_lives = 3;
    m_keys = 0;
    m_breath = false;
}

Hero::~Hero(){};

void Hero::KeyCollected(){
    m_keys++;
}

bool Hero::UseKey(){
    if (m_keys == 0) return false;
    else{
        m_keys--;
        return true;
    }
}

void Hero::HasBeenHitted(Monster &l_monster){
    sf::FloatRect heroBounds = m_body.getGlobalBounds();
    sf::FloatRect monsterBounds = l_monster.GetBounds();
    if(heroBounds.intersects(monsterBounds)){
        m_lives--;
        m_body.setPosition(0, 0);
        m_breath = true;
    }
}

bool Hero::IsDead(){
    if(m_lives <= 0) return true;
    else return false;
}

void Hero::TakeBreath(){
    if(m_breath == true){
        sf::Clock c;
        float t = c.restart().asSeconds() + 2;
        while(c.getElapsedTime().asSeconds() < t) {};
        m_body.setPosition(m_spawnPoint);
    }
    m_breath = false;
}

int Hero::GetLives(){ return m_lives; }

int Hero::GetKeys(){ return m_keys; }

void Hero::SetEquipment(int l_lives, int l_keys){
    m_lives = l_lives;
    m_keys = l_keys;
}
