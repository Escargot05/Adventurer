#include "Window.h"

Window::Window(){
    Setup("The Adventurer", sf::Vector2u(800,480));
    m_window.setFramerateLimit(8);
    sf::Image icon;
    icon.loadFromFile("resources/icon.png");
    m_window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
}

Window::~Window(){ Destroy(); }

void Window::Setup(const std::string& l_title, const sf::Vector2u& l_size){
    m_windowTitle = l_title;
    m_windowSize = l_size;
    m_isOpen = true;
    Create();
}

void Window::Create(){
    auto style = (sf::Style::Default);
    m_window.create({m_windowSize.x, m_windowSize.y, 32},m_windowTitle, style);
}

void Window::Destroy(){
    m_window.close();
}

void Window::BeginDraw(){ m_window.clear(sf::Color::Black); }

void Window::Draw(const sf::Drawable&l_drawable){ m_window.draw( l_drawable); }

void Window::EndDraw(){ m_window.display(); }

void Window::Update(){
    sf::Event event;
    while(m_window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed){ m_isOpen = false; }

    }
}

bool Window::IsOpen(){ return m_isOpen; }

void Window::Close(){ m_isOpen = false; }

sf::RenderWindow* Window::GetRenderWindow(){ return &m_window; }
