#pragma once
#include "Animal.h"
class Turtle : virtual public Animal{
public:
	Turtle();
	~Turtle();
	int defMove();
};