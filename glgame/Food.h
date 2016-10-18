#ifndef FOOD_H_
#define FOOD_H_
#include "tools.h"
#include <cstdlib>

class Food {

private:

	CurrentPosition foodPosition;

public:
	Food();
	~Food();
	void birth();
	void printCoords();
	bool isEated();

};

#endif // !FOOD_H_


