#include "Animal.h"
#include "Init.h"
#include <ctime>

using namespace sf;

Animal::Animal() {
	point = 0;
	energy = 20;
}

Animal::~Animal() {}

int Animal::defNum() {
	srand((unsigned int)time(nullptr));
	return rand() % 10 + 1;
}

void Animal::setEnergy(int val) {
	energy = val;
}

int Animal::getEnergy() {
	return energy;
}

float Animal::getPos() {
	return sprite.getPosition().x;
}

void Animal::correct(int* val, int min, int max) {
	if (*val < min) {
		*val = min;
	}else if (*val > max) {
		*val = max;
	}
}

void Animal::moveToPoint(float x, float y, float time) {
	currentFrame += 0.005*time;
	if (currentFrame > 3) { currentFrame = 0; }
	sprite.setTextureRect(sf::IntRect(150 * (int)getCurrentFrame(), 0, 150, 150));
	if (sprite.getPosition().x < x) {
		sprite.setPosition(sprite.getPosition().x + 0.1*time, y);
	}
	else if (sprite.getPosition().x > x) {
		sprite.setPosition(sprite.getPosition().x - 0.1*time, y);
	}
	if (sprite.getPosition().x > Init::FINISH_LINE) {
		sprite.setPosition(Init::FINISH_LINE, y);
	}
	else if (sprite.getPosition().x < 0) {
		sprite.setPosition(0, y);
	}
}

int Animal::getYpos() {
	return Ypos;
}