#ifndef FOOD_H_
#define FOOD_H_
#include <cstdlib>

//>>>>>>>>>>>>>>>>>
#include "Food.h"
#include "tools.h"
#include "Snake.h"
//<<<<<<<<<<<<<<<<<


class Food {

private:

	CurrentPosition foodPosition;
	bool foodIsEated = true;

public:
	Food();
	~Food();
	void birth();
	void printCoords();
	bool isEated();
	CurrentPosition getCP();
	

};

extern Food food;

#endif // !FOOD_H_


