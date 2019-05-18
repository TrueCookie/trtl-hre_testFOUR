#include "Animal.h"
#include <ctime>

using namespace sf;

Animal::Animal() {
	point = 0;
	energy = 20;
	sleepFlag = false;
	//targetPos = 0;
	//moveFlag = false;
}

Animal::~Animal() {}

/*void Animal::setTargetPos(int val) {
	targetPos += val;
}

int Animal::getTargetPos() {
	return targetPos;
}

bool Animal::isMovin() {
	return moveFlag;
}

void Animal::setMoveFlag(bool val) {
	moveFlag = val;
}*/

int Animal::defNum() {
	srand((unsigned int)time(nullptr));
	return rand() % 10 + 1;
}

bool Animal::isOut() {
	return sprite.getPosition().x < 0;
}

void Animal::setEnergy(int val) {
	energy = val;
}

void Animal::getUp() {
	sleepFlag = false;
}

bool Animal::isSleep() {
	return sleepFlag;
}

int Animal::getEnergy() {
	return energy;
}

void Animal::eatSnack() {
	if (energy >= 15) {
		energy = 20;
	}else {
		energy += 5;
	}
}

void Animal::bite() {
	energy -= 10;
}

float Animal::getPos() {
	return sprite.getPosition().x;
}

float Animal::getPosY() {
	return sprite.getPosition().y;
}