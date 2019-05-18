#include <SFML/Graphics.hpp>
#include "map.h"
#include "Hare.h"
#include "Turtle.h"
class Game{
private:
	sf::RenderWindow window;
	Map map;
	float time;
	int racersNum;
	Hare hare;
	Turtle turtle;
	Animal** racers;
	Animal* winner;
	bool gameOver;

	Font font;
	Text text;
	
public:
	Game();
	~Game();
	
	void update();
	void correct(int* val);
	void moveThemAll();
	void interactionWithMap();
	void drawItAll();
	Animal* whoFinished();
	void endMessage();
};

