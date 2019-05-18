#include "Hare.h"
#include <iostream>

Hare::Hare(){
	type = "hare";

	texture.loadFromFile("images/hareSL.png");
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(0, 0, 295, 355));

	sprite.setPosition(10, 10);
	sprite.setScale(0.2, 0.2);
}

Hare::~Hare(){}

int Hare::defMove() {
	energy -= 2;
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

void Hare::moveToPoint(float x, float y, float time) {
		currentFrame += 0.005*time;
		if (currentFrame > 12) { currentFrame = 0; }
		sprite.setTextureRect(sf::IntRect(295 * (int)getCurrentFrame(), 0, 295, 355));
		if (sprite.getPosition().x < x) {
			sprite.setPosition(sprite.getPosition().x+0.1*time, 0);//sprite.move(x, y);
		}else if (sprite.getPosition().x > x) {
			sprite.setPosition(sprite.getPosition().x-0.1*time, 0);//sprite.move(x, y);
		}
		if (sprite.getPosition().x > 1248) {
			sprite.setPosition(1248, 0);
		}else if(sprite.getPosition().x < 0) {
			sprite.setPosition(0, 0);
		}
}