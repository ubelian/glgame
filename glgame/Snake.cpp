#include "Snake.h"
#include <GL\glut.h>
#include <GL\GL.h>
#include <iostream>

Snake::Snake(){



}

Snake::~Snake(){

}

void Snake :: snakeDisplay() {

	glColor3f(0.5f, 0.2f, 0.4f);
	glRecti(xSnakeCoord, ySnakeCoord, xSnakeCoord + snakeSize, ySnakeCoord + snakeSize);
	glutSwapBuffers();
	glutPostRedisplay();

}

void Snake :: snakeMoving() {

	glClear(GL_COLOR_BUFFER_BIT);

	static int step = 40;

	switch (moveDirection) {

		case 1: // UP

			if (ySnakeCoord >= 480 - snakeSize)
				ySnakeCoord = 480 - snakeSize;
			else
				ySnakeCoord += step;

		break;

		case 2: // DOWN

			if (ySnakeCoord <= 0)
				ySnakeCoord = 0;
			else
				ySnakeCoord -= step;

		break;

		case 3: //LEFT

			if (xSnakeCoord <= 0)
				xSnakeCoord = 0;
			else
			xSnakeCoord -= step;

		break;

		case 4: //RIGHT

			if (xSnakeCoord >= 640 - snakeSize)
				xSnakeCoord = 640 - snakeSize;
			else
			xSnakeCoord += step;

		break;

	}

}

bool Snake :: direction(int mMove) {

	if (moveDirection + mMove == 3 || moveDirection + mMove == 7)
		return false;

	moveDirection = mMove;
	return true;

}

int Snake :: getMD() {

	return moveDirection;

}







	

