#include <GL\glut.h>
#include <GL\GL.h>
#include <cmath>
#include <ctime>
#include <iostream>


//>>>>>>>>>>>>>>>>>
#include "Food.h"
#include "tools.h"
#include "Snake.h"
#include <iostream>
//<<<<<<<<<<<<<<<<<

extern Snake snake;

Food::Food(){

	std :: cout <<  snake.getCanChange();

	

	srand(time(0));

	int x = rand();

	int y = rand();

	x = (x % 640) - (x % 640) % 40;

	y = (y % 480) - (y % 480) % 40;

	foodPosition.setCPx(x);
	foodPosition.setCPy(y);

}

Food::~Food(){
}

void Food::printCoords() {

	std::cout << foodPosition.getCPx() << " " << foodPosition.getCPy() << " ";

}


void Food::birth() {
	 {

		snake.getHeadCP();

		glColor3f(1, 1, 0);
		glPushMatrix();
		glTranslated(foodPosition.getCPx() + 20, foodPosition.getCPy() + 20, 0);

		GLfloat theta;
		GLfloat pi = acos(-1.0);
		GLfloat radius = 12.0f;
		GLfloat step = 6.0f;

		glBegin(GL_TRIANGLE_FAN);
		for (GLfloat a = 0.0f; a < 360.0f; a += step) {
			theta = 2.0f * pi * a / 180.0f;
			glVertex3f(radius * cos(theta), radius * sin(theta), 0.0f);
		}

		glEnd();
		glPopMatrix();

		

	}

	
}


CurrentPosition Food :: getCP() {
	return foodPosition;
}


bool Food::isEated() {
	
	foodIsEated = true;

	srand(time(0));

	int x = rand();

	int y = rand();

	if ((x % 640) % 40 > 20)
		x = (x % 640) + (40 - ((x % 640) % 40));
	else
		x = (x % 640) - (x % 640) % 40;


	if((y % 480) % 40 > 20)
		y = (y % 480) + (40 - ((y % 480) % 40));
	else
		y = (y % 480) - ((y % 480) % 40);

	if (x >= 640)
		x = 600;
	if (y >= 480)
		y = 440;

	foodPosition.setCPx(x);
	foodPosition.setCPy(y);


	return true;
}

Food food;

