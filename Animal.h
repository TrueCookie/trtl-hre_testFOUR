#pragma once
#include <SFML/Graphics.hpp>
#include "Object.h"

//using namespace sf;
class Animal : public Object{
protected:
	int energy;
	bool sleepFlag;
	//int targetPos;
	//bool moveFlag;
	
public:
	int point;
	//const int mult = 5;
	//int delta;
	Animal();
	~Animal();
	void setTargetPos(int val);
	int getTargetPos();
	bool isMovin();
	void setMoveFlag(bool val);
	int defNum();
	virtual int defMove() = 0;
	void setEnergy(int val);
	int getEnergy();
	bool isSleep();
	void getUp();
	bool isOut();
	void eatSnack();
	void bite();
	virtual void moveToPoint(float x, float y, float time) = 0;
	float getPos();
	float getPosY();
};