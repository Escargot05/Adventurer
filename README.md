# The Adventurer

## Overview
Tha main idea behind this project was to learn basic features of C++ language and practice OOP. It was a final assigment for third semester of computer programming course. The form of game was choosen to leave a freedom with impleneting ideas that used required features. So the main inspiration was Atari 2600 game "Adventure". The graphic library was an addition to simply use some external library.

## Technologies

* C++
* SFML 2.5.1

## Detailed description

### Aim

The aim of game is to collect all keys, open the gates and escape from the temple. The player should try to avoid monsters, because he has only three lives.

### Legend

![hero](https://via.placeholder.com/15/00FF00/000000?text=+) Hero
![wall](https://via.placeholder.com/15/0000FF/000000?text=+) Wall
![key](https://via.placeholder.com/15/FFFF00/000000?text=+) Key
![wall](https://via.placeholder.com/15/00FFFF/000000?text=+) Door
![wall](https://via.placeholder.com/15/FF0000/000000?text=+) Monster
![wall](https://via.placeholder.com/15/FF00FF/000000?text=+) Advanced Monster

### Classes
* Entity - the abstract base class for the rendered game objects. It contains getters to the object position and bounds, setter to position, and the render method.
* Hero - contains information about the player: lives and keys numbers, the spawn point position, and a flag to pause the game for a few seconds after player death. It also checks if the player was hit or is dead.
* Wall - checks collisions with moving entities and does not let them pass through the wall objects.
* Key - the collectible that disappears after being collected by the player and affects its keys counter.
* Door - behave like the wall, but the player can open it if a collision with the player is detected and the player has the key.
* Monster - describes the enemy, which moves randomly and can hit the player.
* Advanced monster - the monster that starts to chase the player if it is in the range. He stores coordinates of the last player's position in his range and additional direction if the monster encounters the wall.
* Escaping key - the key that moves opposite to the advanced monster - tries to run away from the player.
* Window - describes SFML render window object and interactions with it.
* Game - the main class that uses classes mentioned above as members. Handles input to specify a player direction, set time of all program iterations and framerate, renders objects, saves, and loads progress.

### UML classes diagram

![uml](https://user-images.githubusercontent.com/72464031/170147462-1ef080ae-e015-486c-8b53-791d147757fd.png)

## Preview

![menu](https://user-images.githubusercontent.com/72464031/170148177-6bd3323c-375d-4680-8e04-22e849456f83.png)
![menu2](https://user-images.githubusercontent.com/72464031/170148187-da305af7-6515-4d7c-a2bb-7e93683622b9.png)
![map](https://user-images.githubusercontent.com/72464031/170148196-ab456487-9a3a-461f-9bc9-2d0623b17c38.png)
![map2](https://user-images.githubusercontent.com/72464031/170148201-7584fe11-7ced-4817-ba03-904a84eb7359.png)
