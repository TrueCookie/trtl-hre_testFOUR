#include "Turtle.h"
#include <iostream>

Turtle::Turtle(){
	type = "turtle";
	
	texture.loadFromFile("images/turtleSL.png");
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(0, 0, 350, 237));

	sprite.setPosition(10, 30);
	sprite.setScale(0.2, 0.2);
}

Turtle::~Turtle(){}

int Turtle::defMove() {
	energy -= 2;
	int randNum = defNum();
	if (randNum >= 1 && randNum <= 5) {
		return 3;
	}
	else if (randNum >= 6 && randNum <= 7) {
		return -9;
	}
	else{
		return 1;
	}
}

void Turtle::moveToPoint(float x, float y, float time) {
		currentFrame += 0.005*time;
		if (currentFrame > 2) { currentFrame = 0; }
		sprite.setTextureRect(sf::IntRect(350 * (int)getCurrentFrame(), 0, 350, 237));
		if (sprite.getPosition().x < x) {
			sprite.setPosition(sprite.getPosition().x + 0.1*time, 0);//sprite.move(x, y);
		}else if (sprite.getPosition().x > x) {
			sprite.setPosition(sprite.getPosition().x - 0.1*time, 0);//sprite.move(x, y);
		}
		if (sprite.getPosition().x > 1248) {
			sprite.setPosition(1248, 0);
		}else if (sprite.getPosition().x < 0) {
			sprite.setPosition(0, 0);
		}
}