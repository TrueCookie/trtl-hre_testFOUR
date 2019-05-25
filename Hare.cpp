#include "Hare.h"
#include "Init.h"
#include <iostream>

Hare::Hare(){
	type = "hare";
	Ypos = Init::HARE_Y_POS;
	texture.loadFromFile("images/hre_list.png");
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(0, 0, 150, 150));

	sprite.setPosition(10, Init::HARE_Y_POS);
	sprite.setScale(0.2, 0.2);
}

Hare::~Hare(){}

int Hare::defMove() {
	energy -= 2;
	correct(&energy, 0, 20);
	int randNum = defNum();
	if (randNum <= 2) {
		return 0;
	}else if(randNum >= 3 && randNum <= 4){
		return 9;
	}else if (randNum == 5) {
		return -12;
	}else if (randNum >= 6 && randNum <= 8) {
		return 1;
	}else if (randNum >= 9) {
		return -2;
	}
}