#include "Game.h"

Game::Game(): m_window(){
    srand(time(NULL));
    m_menuOpen = true;
    m_elapsed = 0;
    if(!m_T.loadFromFile("resources/intro.png"));
    m_menu.setTexture(m_T);
}

Game::~Game(){}

void Game::ShowMenu(){
    m_window.BeginDraw();
    m_window.Draw(m_menu);
    sf::Event event;
    if (m_window.GetRenderWindow()->waitEvent(event))
    {
        if (event.type == sf::Event::KeyPressed){
            if(event.key.code == sf::Keyboard::Num1 || event.key.code == sf::Keyboard::Numpad1){
                m_menuOpen = false;
                m_walls.clear();
                CleanLevel();
                LoadLevel("resources/Level1.txt");
            }
            if(event.key.code == sf::Keyboard::Num2 || event.key.code == sf::Keyboard::Numpad2){
                m_menuOpen = false;
                LoadLevel("resources/Level1.txt");
                CleanLevel();
                Load("resources/game.dat");
            }
            if(event.key.code == sf::Keyboard::Num3 || event.key.code == sf::Keyboard::Numpad3){
                if(!m_T.loadFromFile("resources/help.png"));;
            }
            if(event.key.code == sf::Keyboard::Escape){
                if(!m_T.loadFromFile("resources/intro.png"));
            }
        }else if(event.type == sf::Event::Closed) { m_window.Close(); };
    }
    m_window.EndDraw();
    m_clock.restart();
}

void Game::LoadLevel(std::string level){
    std::ifstream infile(level);
    if(infile.is_open()){
        for(int j = 0; j < 30; j++){
            for(int i = 0; i < 50; i++){
                int z = infile.get() - '0';
                if(z == '\n' - '0') { i--; }
                else if(z == Entities::wall) { m_walls.push_back(Wall(sf::Color::Blue, i, j)); }
                else if(z == Entities::hero) { m_hero = Hero(sf::Color::Green, i, j); }
                else if(z == Entities::key) { m_keys.push_back(Key(sf::Color::Yellow, i, j)); }
                else if(z == Entities::monster) { m_monsters.push_back(Monster(sf::Color::Red, i, j)); }
                else if(z == Entities::door) { m_doors.push_back(Door(sf::Color::Cyan, i, j)); }
                else if(z == Entities::advancedMonster) { m_advancedMonsters.push_back(AdvancedMonster(sf::Color::Magenta, i, j)); }
                else if(z == Entities::escapingKey) { m_escapingKeys.push_back(EscapingKey(sf::Color::Yellow, i, j)); }
                else if(z == Entities::exit) { m_exit = sf::Vector2f(i * 16, j * 16); }
            }
        }
        infile.close();
    }else{
        std::cout << "Error: File cannot be open" << std::endl;
        std::exit(EXIT_FAILURE);
    }
}

void Game::CleanLevel(){
    m_keys.clear();
    m_monsters.clear();
    m_doors.clear();
    m_advancedMonsters.clear();
    m_escapingKeys.clear();
}

void Game::HandleInput(){
    if(!m_menuOpen){
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
            m_menuOpen = true;
            Save("resources/game.dat");
        }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
            m_hero.SetDirection(up);
        }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
            m_hero.SetDirection(down);
        }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
            m_hero.SetDirection(right);
        }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
            m_hero.SetDirection(left);
        }else{
        m_hero.SetDirection(none);
        }
    }
}

void Game::Update(){
    if(m_menuOpen){ ShowMenu(); }
    else{
        m_hero.TakeBreath();
        End();
        float frametime = 1.0f / 8;
        SpecifyDirections();
        if(m_elapsed >= frametime){
            CheckCollisions();
            MoveObjects();
            CheckCollected();
            m_elapsed -= frametime;
        }
        m_window.Update();
    }
}

void Game::Render(){
    m_window.BeginDraw();
    if(!m_menuOpen){
        m_hero.Render(*m_window.GetRenderWindow());
        for(auto &w : m_walls){
            w.Render(*m_window.GetRenderWindow());
        }
        for(auto &k : m_keys){
            k.Render(*m_window.GetRenderWindow());
        }
        for(auto &m : m_monsters){
            m.Render(*m_window.GetRenderWindow());
        }
        for(auto &d : m_doors){
            d.Render(*m_window.GetRenderWindow());
        }
        for(auto &a : m_advancedMonsters){
            a.Render(*m_window.GetRenderWindow());
        }
        for(auto &e : m_escapingKeys){
            e.Render(*m_window.GetRenderWindow());
        }
        m_window.EndDraw();
    }
}

void Game::CheckCollisions(){
    for(auto &w : m_walls){
        w.Collision(m_hero);
        for(auto &m : m_monsters){
            w.Collision(m);
        }
        for(auto &a : m_advancedMonsters){
            w.Collision(a);
        }
        for(auto &e : m_escapingKeys){
            w.Collision(e);
        }
    };
    for(auto &w : m_walls){
        for(auto &a : m_advancedMonsters){
            Monster& aux = static_cast<Monster&>(a);
            w.Collision(aux);
        }
        for(auto &e : m_escapingKeys){
            Monster& aux = static_cast<Monster&>(e);
            w.Collision(aux);
        }
    };
    for(unsigned int i = 0; i < m_doors.size(); i++){
        m_doors[i].Collision(m_hero);
        if(m_doors[i].GetOpened() == true) { m_doors.erase(m_doors.begin() + i); }
        for(auto &m : m_monsters){
            m_doors[i].Collision(m);
        }
        for(auto &a : m_advancedMonsters){
            m_doors[i].Collision(a);
        }
        for(auto &e : m_escapingKeys){
            m_doors[i].Collision(e);
        }
    };
}

void Game::SpecifyDirections(){
    for(auto &m : m_monsters){
        m.DrawDirection();
    }
    for(auto &a : m_advancedMonsters){
        a.Search(m_hero);
    }
    for(auto &e : m_escapingKeys){
        e.Search(m_hero);
    }
}
void Game::MoveObjects(){
        for(auto &m : m_monsters){
            m.Move();
            m_hero.HasBeenHitted(m);
        }
        for(auto &a : m_advancedMonsters){
            a.Move();
            m_hero.HasBeenHitted(a);
        }
        for(auto &e : m_escapingKeys){
            e.Move();
        }
        m_hero.Move();
        for(auto &m : m_monsters){
            m_hero.HasBeenHitted(m);
        }
        for(auto &a : m_advancedMonsters){
            m_hero.HasBeenHitted(a);
        }
}

void Game::CheckCollected(){
    for(unsigned int i = 0; i < m_keys.size(); i++){
        if(m_keys[i].isCollected(m_hero)) { m_keys.erase(m_keys.begin() + i); }
    }
    for(unsigned int i = 0; i < m_escapingKeys.size(); i++){
        if(m_escapingKeys[i].isCollected(m_hero)) { m_escapingKeys.erase(m_escapingKeys.begin() + i); };
    }
}

void Game::End(){
    if(m_hero.IsDead()){
        m_menuOpen = true;
        if(!m_T.loadFromFile("resources/defeat.png"));
        m_menu.setTexture(m_T);
    }else if(m_hero.GetPosition() == m_exit){
        m_menuOpen = true;
        if(!m_T.loadFromFile("resources/victory.png"));
        m_menu.setTexture(m_T);
    }
}

void Game::Save(std::string game)
{
    std::fstream out_file;
    out_file.open(game, std::ios::out | std::ios::binary);
    if (m_hero.IsDead()) return;
    if(out_file.good())
    {
        out_file << m_monsters.size() << std::endl;
        for(auto &m : m_monsters){
            out_file << m.GetPosition().x << std::endl;
            out_file << m.GetPosition().y << std::endl;
        }
        out_file << m_advancedMonsters.size() << std::endl;;
        for(auto &a : m_advancedMonsters){
            out_file << a.GetPosition().x << std::endl;
            out_file << a.GetPosition().y << std::endl;
        }
        out_file << m_doors.size() << std::endl;;
        for(auto &d : m_doors){
            out_file << d.GetPosition().x << std::endl;
            out_file << d.GetPosition().y << std::endl;
        }
        out_file << m_keys.size() << std::endl;;
        for(auto &k : m_keys){
            out_file << k.GetPosition().x << std::endl;
            out_file << k.GetPosition().y << std::endl;
        }
        out_file << m_escapingKeys.size() << std::endl;;
        for(auto &e : m_escapingKeys){
            out_file << e.GetPosition().x << std::endl;
            out_file << e.GetPosition().y << std::endl;
        }
        out_file << m_hero.GetPosition().x << std::endl;
        out_file << m_hero.GetPosition().y << std::endl;
        out_file << m_hero.GetLives() << std::endl;
        out_file << m_hero.GetKeys() << std::endl;
        out_file.close();
    }else{
        std::cout << "ERROR: Save file cannot be open" << std::endl;
        std::exit(EXIT_FAILURE);
    }
}

void Game::Load(std::string game)
{
    std::fstream in_file;
    in_file.open(game, std::ios::in | std::ios::binary);
    if(in_file.is_open())
    {
        int i, s, x, y;
        in_file >> s;
        for(i = 0; i < s; i++){
            in_file >> x >> y;
            m_monsters.push_back(Monster(sf::Color::Red, 0, 0));
            m_monsters[i].SetPosition(x, y);
        }
        in_file >> s;
        for(i = 0; i < s; i++){
            in_file >> x >> y;
            m_advancedMonsters.push_back(AdvancedMonster(sf::Color::Magenta, 0, 0));
            m_advancedMonsters[i].SetPosition(x, y);
        }
        in_file >> s;
        for(i = 0; i < s; i++){
            in_file >> x >> y;
            m_doors.push_back(Door(sf::Color::Cyan, 0, 0));
            m_doors[i].SetPosition(x, y);
        }
        in_file >> s;
        for(i = 0; i < s; i++){
            in_file >> x >> y;
            m_keys.push_back(Key(sf::Color::Yellow, 0, 0));
            m_keys[i].SetPosition(x, y);
        }
        in_file >> s;
        for(i = 0; i < s; i++){
            in_file >> x >> y;
            m_escapingKeys.push_back(EscapingKey(sf::Color::Yellow, 0, 0));
            m_escapingKeys[i].SetPosition(x, y);
        }
        in_file >> x >> y;
        m_hero.SetPosition(x, y);
        in_file >> x >> y;
        m_hero.SetEquipment(x, y);
        in_file.close();
    }else{
        std::cout << "ERROR: Save file cannot be open" << std::endl;
        std::exit(EXIT_FAILURE);
    }
}

Window* Game::GetWindow(){ return &m_window; }

void Game::RestartClock(){ m_elapsed += m_clock.restart().asSeconds(); }
