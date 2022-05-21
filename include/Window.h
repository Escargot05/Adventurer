#ifndef WINDOW_H_
#define WINDOW_H_
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Window
{
private:
    sf::RenderWindow m_window;
    sf::Vector2u m_windowSize;
    std::string m_windowTitle;
    bool m_isOpen;

    void Setup(const std::string& l_title, const sf::Vector2u& l_size);     //Support for the constructor
    void Create();                                                          //
    void Destroy();                                                         //Closing window
public:
    Window();
    ~Window();

    void BeginDraw();                               //Clearing screen
    void Draw(const sf::Drawable& l_drawable);      //Drawing objects
    void EndDraw();                                 //Displaying objects
    void Update();                                  //Checking if window is open
    bool IsOpen();                                  //Flag
    void Close();                                   //Changing flag to false
    sf::RenderWindow* GetRenderWindow();
};

#endif
