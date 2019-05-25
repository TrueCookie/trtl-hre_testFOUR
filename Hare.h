#pragma once
#include "Animal.h"
class Hare : virtual public Animal{
public:
	Hare();
	~Hare();
	int defMove();
};