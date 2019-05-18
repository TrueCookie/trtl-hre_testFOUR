#include "map.h"
using namespace sf;

Map::Map(){
	tileMap[0] = "0000000000000000000000000000000000000000";
	tileMap[1] = "0                                     f0";
	tileMap[2] = "0   s   s   s   s   s   s   s   s   s f0";
	tileMap[3] = "0                                     f0";
	tileMap[4] = "0                                     f0";
	tileMap[5] = "0000000000000000000000000000000000000000";
	image.loadFromFile("images/map.png");
	texture.loadFromImage(image);
	sprite.setTexture(texture);
}

Map::~Map(){}
