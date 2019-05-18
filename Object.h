#pragma once
#include <SFML/Graphics.hpp>
#include <string>

using namespace sf;
class Object{
protected:
	std::string type;
	Texture texture;
	Sprite sprite;
	float currentFrame;
public:
	Object();
	Object(std::string type, std::string path, sf::IntRect rect, int x, int y, float scaleX = 1, float scaleY = 1);
	~Object();

	Sprite getSprite();
	void setCurrentFrame(float num);
	float getCurrentFrame();
	std::string getType();
};

