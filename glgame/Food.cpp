#include "Food.h"
#include <GL\glut.h>
#include <GL\GL.h>
#include <cmath>
#include <ctime>
#include <iostream>

Food::Food(){

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

	glColor3f(1, 1, 0);
	glPushMatrix();
	glTranslated(foodPosition.getCPx() - 20, foodPosition.getCPy() - 20, 0);

	GLfloat theta;
	GLfloat pi = acos(-1.0);
	GLfloat radius = 12.0f; // радиус 
	GLfloat step = 6.0f; // чем больше шаг тем хуже диск

						 // рисуем диск по часовой стрелки GL_CW
	glBegin(GL_TRIANGLE_FAN);
	for (GLfloat a = 0.0f; a < 360.0f; a += step) {
		theta = 2.0f * pi * a / 180.0f;
		glVertex3f(radius * cos(theta), radius * sin(theta), 0.0f);
	}
	glEnd();
	glPopMatrix();
	
}

bool Food :: isEated() {

	

	return true;




}