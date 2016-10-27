#ifndef FOOD_H_
#define FOOD_H_
#include "tools.h"
#include <cstdlib>

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



#endif // !FOOD_H_


