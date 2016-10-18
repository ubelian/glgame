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

	/* Функция вернет текущее направление движения*/
	int getMD();
	/*Функция установит направление движения*/
	bool direction(int mMove);
	/*Функция в зависимости от нажатой клавиши на клавиатуре передвигает змею, меняя координаты змеи (xSnakeCoord, ySnakeCoord)*/
	void snakeMoving();
	/*Функция отображает змею с изменёнными координатами*/
	void snakeDisplay();


};

#endif //SNAKE_H_
