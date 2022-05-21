#include "Entity.h"

Entity::Entity(){}

Entity::Entity(sf::Color l_color, int x, int y){
    m_body.setSize(sf::Vector2f(16, 16));
    m_body.setFillColor(l_color);
    m_body.setPosition(sf::Vector2f((x * 16), (y * 16)));
}
Entity::~Entity(){}

sf::FloatRect Entity::GetBounds(){ return m_body.getGlobalBounds(); }

sf::Vector2f Entity::GetPosition(){ return m_body.getPosition(); }

void Entity::SetPosition(int x, int y){ m_body.setPosition(x, y); };

void Entity::Render(sf::RenderWindow& l_window){ l_window.draw(m_body); }
