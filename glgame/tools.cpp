#include "tools.h"

CurrentPosition::CurrentPosition() {

	xPosition = 0;
	yPosition = 0;

}

CurrentPosition::CurrentPosition(int x, int y) {

	xPosition = x;
	yPosition = y;

}

CurrentPosition::~CurrentPosition() {


}

int CurrentPosition::getCPx() const {
	return xPosition;
}

int CurrentPosition::getCPy() const {
	return yPosition;
}

CurrentPosition CurrentPosition::getCP() const {
	CurrentPosition CP;
	CP.xPosition = xPosition;
	CP.yPosition = yPosition;
	return CP;
}

void CurrentPosition::setCPx(int x) {
	xPosition = x;
}
void CurrentPosition::setCPy(int y) {
	yPosition = y;
}
void CurrentPosition::setCP(CurrentPosition CP) {
	xPosition = CP.xPosition;
	yPosition = CP.yPosition;
}

bool CurrentPosition::operator==(CurrentPosition CP_) {
	return true;
}

