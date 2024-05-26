#include <iostream>
#include <cmath>
#include <vector>

#include <SFML/Graphics.hpp>

 using namespace  sf;
 using namespace std;

  RenderWindow gameWin(sf::VideoMode(1200, 800), L"Ку!");

	#include "./vec2/vec2Lib.h"
	 #include "./SAT/satLib.h"

/***************************************************************************\
\***************************************************************************/

int main(){
	std::cout << "Hello world!\n";

	sf::Clock clock;
	sf::Clock deltaClock;
	int frames = 0;

	while (gameWin.isOpen()){
		Event event;
			while (gameWin.pollEvent(event)){
				if (event.type == sf::Event::Closed){
					gameWin.close();
				}
		}
		float deltaTime = deltaClock.restart().asSeconds();
		gameWin.clear();
			gameWin.display();

			frames++;
			 if (clock.getElapsedTime().asSeconds() >= 1.0f) {
				 std::cout << "FPS: " << frames << "  " << deltaTime << std::endl;
					clock.restart();
					 frames = 0;
			}
	}

	std::cout << "It's closed.\n";
	return 0;
}

/*\
|*|путь до проекта:
|*|  cd ~/proj/cpp/game
|*|
|*|Сторка для компиляцыи проекта:
|*|  g++ -c main.cpp && g++ main.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
|*|
|*|Сторка для запуска проекта:
|*|  ./sfml-app
\*/
