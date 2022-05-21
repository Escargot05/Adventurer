#ifndef ENTITY_H_
#define ENTITY_H_
#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>

class Entity
{
protected:
    sf::RectangleShape m_body;
public:
    Entity();
    Entity(sf::Color l_color, int x, int y);
    virtual ~Entity() = 0;

    sf::FloatRect GetBounds();
    sf::Vector2f GetPosition();
    void SetPosition(int x, int y);
    void Render(sf::RenderWindow& l_window);    //Rendering shape in the window
};

#endif
