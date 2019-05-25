#include "Turtle.h"
#include "Init.h"
#include <iostream>

Turtle::Turtle(){
	type = "turtle";
	Ypos = Init::TURTLE_Y_POS;
	texture.loadFromFile("images/trtl_list.png");
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(0, 0, 150, 150));

	sprite.setPosition(10, Init::TURTLE_Y_POS);
	sprite.setScale(0.2, 0.2);
}

Turtle::~Turtle(){}

int Turtle::defMove() {
	energy -= 2;
	correct(&energy, 0, 20);
	int randNum = defNum();
	if (randNum >= 1 && randNum <= 5) {
		return 3;
	}else if (randNum >= 6 && randNum <= 7) {
		return -9;
	}else{
		return 1;
	}
}