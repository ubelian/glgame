#ifndef _TOOLS_H_
#define _TOOLS_H_

class CurrentPosition {
	int xPosition;
	int yPosition;
public:

	/*Деструкторы и конструкторы */
	CurrentPosition();
	CurrentPosition(int x, int y);
	~CurrentPosition();
	/*****************************/

	/*Получают текущее положение*/
	int getCPx() const;
	int getCPy() const;
	CurrentPosition getCP() const;
	/*****************************/

	/*Устанавливают текущее положение*/
	void setCPx(int x);
	void setCPy(int y);
	void setCP(CurrentPosition CP);
	/*********************************/

	bool operator==(CurrentPosition CP_);

};

#endif //!_TOOLS_H_