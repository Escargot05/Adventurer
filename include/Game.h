#ifndef GAME_H_
#define GAME_H_
#include <fstream>
#include "Window.h"
#include "Hero.h"
#include "Entity.h"
#include "Wall.h"
#include "Hero.h"
#include "Key.h"
#include "Door.h"
#include "AdvancedMonster.h"
#include "EscapingKey.h"

class Game
{
private:
    enum Entities{ space, wall, hero, key, monster, door, advancedMonster, escapingKey, exit };
    sf::Texture m_T;                        //Menu texture
    sf::Sprite m_menu;                      //Menu sprite
    bool m_menuOpen;                        //Flag to checking if menu should be open
    sf::Clock m_clock;                      //Timer
    float m_elapsed;                        //Stored time of one program iteration
    Window m_window;
    Hero m_hero;
    std::vector<Wall> m_walls;
    std::vector<Key> m_keys;
    std::vector<Monster> m_monsters;
    std::vector<Door> m_doors;
    std::vector<AdvancedMonster> m_advancedMonsters;
    std::vector<EscapingKey> m_escapingKeys;
    sf::Vector2f m_exit;                    //Coordinates of exit from level

    void ShowMenu();                        //Displaying menu
    void LoadLevel(std::string level);      //Loading level from text file
    void CleanLevel();                      //Cleaning level from object, that change parameters during the game
    void CheckCollisions();                 //Checking all collisions with walls and doors
    void SpecifyDirections();               //Specifying directions of monsters and escaping keys
    void MoveObjects();                     //Moving objects in fixed directions
    void CheckCollected();                  //Checking that keys are collected
    void End();                             //Checking end game conditions
    void Save(std::string game);            //Saving game progress to binary file
    void Load(std::string game);            //Loading game progress from binary file

public:
    Game();
    ~Game();

    void HandleInput();                     //Store pressed keys to specify direction of the player
    void Update();                          //Updating the game in during given time
    void Render();                          //Rendering all objects

    void RestartClock();
    Window* GetWindow();
};

#endif
