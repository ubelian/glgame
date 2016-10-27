#ifndef SNAKE_H_
#define SNAKE_H_
#include "tools.h"

#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4


class Snake {

private:

	/*Текущий размер змеи. По умолчанию он равен 3*/
	int snakeSize = 3;

	/*Текущее направление движения*/
	int moveDirection = RIGHT;

	/*Размер прямоуголька, который отображает голову и части змеи*/
	const int rectSize = 40;

	/*Текущие координаты тела змеи*/
	CurrentPosition *snakePosition;

	/*Текущие координаты тела змеи с которой происходит сравнение*/
	CurrentPosition *snakePosition2;

public:
	/*Конструктор по умолчанию создаст змею размером 3*/
	Snake();
	/*Конструктор создаст змею длиной snakeSize_*/
	Snake(int snakeSize_);
	/*Деструктор освободит память для змеи и для сохранённых предыдущих координат*/
	~Snake();
	/*Функци содержит координаты головы*/
	CurrentPosition getHeadCP();
	/* Функция вернет текущее направление движения*/
	int getMD();
	/*Функция установит направление движения*/
	bool direction(int mMove);
	/*Функция в зависимости от нажатой клавиши на клавиатуре передвигает змею, меняя координаты змеи snakePosition*/
	bool snakeMoving();
	/*Функция отображает змею с изменёнными координатами*/
	void snakeDisplay();
	/*Функция содержит координаты любой её части (головы тоже)*/
	CurrentPosition getTailCP(int a);
	/*Функция изменит размер змеи когда она съедает добычу*/
	void addSnakeSize();
	/*Вернет текущий размер змеи*/
	int getSnakeSize() const;
	

};



#endif //SNAKE_H_
