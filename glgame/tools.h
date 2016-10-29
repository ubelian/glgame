#ifndef _TOOLS_H_
#define _TOOLS_H_



class CurrentPosition {
	int xPosition;
	int yPosition;
public:

	/*����������� � ������������ */
	CurrentPosition();
	CurrentPosition(int x, int y);
	~CurrentPosition();
	/*****************************/

	/*�������� ������� ���������*/
	int getCPx() const;
	int getCPy() const;
	CurrentPosition getCP() const;
	/*****************************/

	/*������������� ������� ���������*/
	void setCPx(int x);
	void setCPy(int y);
	void setCP(CurrentPosition CP);
	/*********************************/

	bool CurrentPosition::operator==(CurrentPosition &CP_) const;
	CurrentPosition(CurrentPosition &a);

	CurrentPosition &operator=(const CurrentPosition &s);

};

#endif //!_TOOLS_H_