#ifndef SNAKE_H_
#define SNAKE_H_

#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4

#include "tools.h"

class Snake {

private:

	/*������� ������ ����. �� ��������� �� ����� 3*/
	int snakeSize = 3;

	/*������� ����������� ��������*/
	int moveDirection = RIGHT;

	/*���� ���������� ����� �� ���� ��������� ����-��. �� ��������� true (�����)*/
	bool canChange = true;

	/*������ ������������, ������� ���������� ������ � ����� ����*/
	int rectSize = 40;

	/*������� ���������� ���� ����*/
	CurrentPosition *snakePosition;

	/*������� ���������� ���� ���� � ������� ���������� ���������*/
	CurrentPosition *snakePosition2;

public:
	/*����������� �� ��������� ������� ���� �������� 3*/
	Snake();
	/*����������� ������� ���� ������ snakeSize_*/
	Snake(int snakeSize_);
	/*����������� �����������*/
	Snake(const Snake &s);
	/*���������� ��������� ������ ��� ���� � ��� ���������� ���������� ���������*/
	~Snake();
	/*������ �������� ���������� ������*/
	CurrentPosition getHeadCP();
	/* ������� ������ ������� ����������� ��������*/
	int getMD();
	/*������� ��������� ����������� ��������*/
	bool direction(int mMove);
	/*������� � ����������� �� ������� ������� �� ���������� ����������� ����, ����� ���������� ���� snakePosition*/
	bool snakeMoving();
	/*������� ���������� ���� � ���������� ������������*/
	void snakeDisplay();
	/*������� �������� ���������� ����� � ����� (������ ����)*/
	CurrentPosition getTailCP(int a);
	/*������� ������� ������ ���� ����� ��� ������� ������*/
	void addSnakeSize();
	/*������ ������� ������ ����*/
	int getSnakeSize() const;
	/*������ canChange. �� ���� ������� ����� �� � �����-�� ������ ������� ���� ���������*/
	bool getCanChange();
	/*��������� canChange*/
	void setCanChange(bool a);

};

extern Snake snake;



#endif //SNAKE_H_
