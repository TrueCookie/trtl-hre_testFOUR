#include <SFML/Graphics.hpp>
#include <string>
#include "Init.h"
using namespace sf;
class Map{
private:
	Image image;
	Texture texture;
public:
	std::string tileMap[Init::MAP_HEIGHT];
	Sprite sprite;
	Map();
	~Map();

};
