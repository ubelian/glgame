#ifndef SNAKE_H_
#define SNAKE_H_
#include "tools.h"

#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4


class Snake {

private:

	int moveDirection = RIGHT;
	int screenWidth = 0;
	int screenHeight = 0;
	int xSnakeCoord = 0;
	int ySnakeCoord = 0;
	int snakeSize = 40;

public:
	Snake();
	~Snake();

	/* ������� ������ ������� ����������� ��������*/
	int getMD();
	/*������� ��������� ����������� ��������*/
	bool direction(int mMove);
	/*������� � ����������� �� ������� ������� �� ���������� ����������� ����, ����� ���������� ���� (xSnakeCoord, ySnakeCoord)*/
	void snakeMoving();
	/*������� ���������� ���� � ���������� ������������*/
	void snakeDisplay();


};

#endif //SNAKE_H_
