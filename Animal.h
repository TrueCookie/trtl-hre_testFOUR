#pragma once
#include <SFML/Graphics.hpp>
#include "Object.h"

class Animal : public Object{
protected:
	int energy;
	int Ypos;
public:
	int point;
	Animal();
	~Animal();
	int defNum();
	virtual int defMove() = 0;
	void setEnergy(int val);
	int getEnergy();
	void moveToPoint(float x, float y, float time);
	float getPos();
	void correct(int* val, int min, int max);
	int getYpos();
};