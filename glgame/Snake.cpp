#include "Snake.h"
#include <GL\glut.h>
#include <GL\GL.h>
#include <iostream>


Snake::Snake(){
	snakePosition = new CurrentPosition[3];
	snakePosition[0].setCP(CurrentPosition(200, 0));
	snakePosition[1].setCP(CurrentPosition(160, 0));
	snakePosition[2].setCP(CurrentPosition(120, 0));

	snakePosition2 = new CurrentPosition[3];
	snakePosition2[0].setCP(CurrentPosition(200, 0));
	snakePosition2[1].setCP(CurrentPosition(160, 0));
	snakePosition2[2].setCP(CurrentPosition(120, 0));
}

Snake::Snake(int snakeSize_) : snakeSize(snakeSize_){
	int a = 200;

	snakePosition = new CurrentPosition[snakeSize];
	snakePosition2 = new CurrentPosition[snakeSize];

	for (int i = 0; i < snakeSize; i++) {
		snakePosition[i].setCP(CurrentPosition(a, 0));
		a = a - 40;
	}

	a = 200;

	for (int i = 0; i < snakeSize; i++) {
		snakePosition2[i].setCP(CurrentPosition(a, 0));
		a = a - 40;
	}
		
}

Snake::~Snake(){
	delete[] snakePosition;
	delete[] snakePosition2;
}

void Snake :: snakeDisplay() {

	glColor3f(0.5f, 0.2f, 0.4f);

	for (int i = 0; i < snakeSize; i++) {
		glRecti(snakePosition[i].getCPx(), snakePosition[i].getCPy(),
			snakePosition[i].getCPx() + rectSize, snakePosition[i].getCPy() + rectSize);
	}

	glutSwapBuffers();
	glutPostRedisplay();

}



bool Snake::snakeMoving() {

	int step1 = 40;

	for (int i = 0; i < snakeSize; i++) {

		snakePosition2[i].setCP(snakePosition[i].getCP());

	}

	switch (moveDirection) {
	case 1: //UP
		snakePosition[0].setCPy(snakePosition[0].getCPy() + step1);
		break;

	case 2: //DOWN
		snakePosition[0].setCPy(snakePosition[0].getCPy() - step1);
		break;

	case 3: //LEFT
		snakePosition[0].setCPx(snakePosition[0].getCPx() - step1);
		break;

	case 4: //RIGHT
		snakePosition[0].setCPx(snakePosition[0].getCPx() + step1);
		break;

	default:

		std::cout << "����������� �������� �� ��������";
		return false;
		break;

	}

	for (int i = 1; i < snakeSize; i++) {

		if (snakePosition[0] == snakePosition[i]) {
			return false;
		}
			

	}





	for (int i = 1; i != snakeSize; i++) {

		snakePosition[i].setCP(snakePosition2[i - 1].getCP());

	}

	return true;

}

bool Snake :: direction(int mMove) {

	if (moveDirection + mMove == 3 || moveDirection + mMove == 7)
		return false;

	moveDirection = mMove;

	return true;

}

CurrentPosition Snake::getHeadCP() {

	return snakePosition[0];

}

int Snake :: getMD() {

	return moveDirection;

}

CurrentPosition Snake :: getTailCP(int a) {

	if (a > snakeSize && a < 0)
		return snakePosition[0].getCP();
	return snakePosition[a].getCP();

}

int Snake :: getSnakeSize() const {
	return snakeSize;
}

void Snake::addSnakeSize() {

	CurrentPosition *arrBuff;
	
	arrBuff = new CurrentPosition[snakeSize];

	for (int i = 0; i < snakeSize; i++) {
		arrBuff[i].setCP(snakePosition[i].getCP());
	}

	delete[] snakePosition;
	delete[] snakePosition2;

	snakePosition = new CurrentPosition [snakeSize + 1];
	snakePosition2 = new CurrentPosition [snakeSize + 1];

	for (int i = 0; i < snakeSize; i++) {

		snakePosition[i].setCP(arrBuff[i].getCP());

	}

	snakePosition[snakeSize].setCP(snakePosition[snakeSize - 1].getCP());

	for (int i = 0; i < snakeSize + 1; i++) {

		snakePosition2[i].setCP(snakePosition[i].getCP());

	}

	snakeSize++;

	delete[] arrBuff;

}

Snake snake;
	

