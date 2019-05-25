#include "Object.h"

Object::Object(){
	currentFrame = 0;
}

Object::Object(std::string type, std::string path, sf::IntRect rect, int x, int y, float scaleX, float scaleY) {
	this->type = type;
	texture.loadFromFile(path);
	sprite.setTexture(texture);
	sprite.setTextureRect(rect);

	sprite.setPosition(x, y);
	sprite.setScale(scaleX, scaleY);
}

Object::~Object(){}

void Object::setCurrentFrame(float num) {
	currentFrame += num;
}

float Object::getCurrentFrame() {
	return currentFrame;
}

Sprite Object::getSprite() {
	return sprite;
}

std::string Object::getType() {
	return type;
}