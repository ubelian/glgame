#include <GL\glut.h>
#include <GL\GL.h>
#include <iostream>
#include "tools.h"

#include "Food.h"
#include "Snake.h"

//<<<<<<VARIABLES>>>>>>
static int xMove = 0;
static int yMove = 0;
static int windowHeight = 480;
static int windowWidth = 640;
bool gameIsEnded = false;

//<<<<<<<<<<<PROTOTIPES>>>>>>>>>>>>

void init();
void gameScene();
void gameKeyboard(unsigned char key, int x, int y);
void gameReshape(int w, int h);
void gameTimer(int value);
void grid();
void endGame();


int main(int argc, char** argv) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("������");
	init();
	glutTimerFunc(600, gameTimer, 0);
	glutDisplayFunc(gameScene);
	glutKeyboardFunc(gameKeyboard);
	glutReshapeFunc(gameReshape);
	glutMainLoop();
	return 0;

}

void gameScene() {

	glClear(GL_COLOR_BUFFER_BIT);
	
	grid();

	food.birth();

	snake.snakeDisplay();

}


void gameTimer(int value){
	
	/*������� ������������ ����*/
	/*������� ������ false ���� ���� ����� ���� ���� ��� ���� ��� ����� �� ������� ������*/
	/*��������� ������� endgame() ������� �������������� ����� ����*/
	if (!snake.snakeMoving())
		endGame();

	

	/*�������� �� �������� �����. ����� ��������� �������� �����, 
	����� ���������� ������ � ����� ���������*/
	if (snake.getHeadCP() == food.getCP() ) {
		food.isEated();
		snake.addSnakeSize();
	}

	/*���������� ���������� gameIsEnded ����������� � true ���� ��������� ������� endGame() */
	if(!gameIsEnded)
		glutTimerFunc(120,gameTimer, 0);

}



void gameKeyboard(unsigned char key, int x, int y) {

	using std::cout;
	using std::endl;

	switch (key) {

	case 'd': //RIGHT
	
		if (snake.getCanChange())
		snake.direction(4);
		

		break;

	case 'a': //LEFT
		
		if (snake.getCanChange())
		snake.direction(3);
		

		break;
		 
	case 'w': //UP

		if (snake.getCanChange())
		snake.direction(1);
		
		break;

	case 's': //DOWN

		if (snake.getCanChange())
		snake.direction(2);
	
		break;

	case 'p':

		
			
		break;
		
	default:
		break;

	}

}

void gameReshape(int w, int h) {

	windowHeight = h;
	windowWidth = w;
	glViewport(0, 0, w, h);

}

void init() {
	glClearColor(0.2f, 0.4f, 0.1f, 0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 640, 0, 480);
	glViewport(0, 0, 640, 480);

}

void grid() {

	glColor3f(1, 1, 1);
	glPushMatrix();

	glBegin(GL_LINES);
	int z = 0;
	for (int i = 0; i < 16; i++) {

		glVertex2d(40 + z, 0);
		glVertex2d(40 + z, 480);
		z += 40;
	}
	glEnd();

	glBegin(GL_LINES);
	z = 0;
	for (int i = 0; i < 12; i++) {

		glVertex2d(0, 40 + z);
		glVertex2d(640, 40 + z);
		z += 40;
	}
	glEnd();


}

void endGame() {
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(1,0,0,0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glRecti(40, 40, 600, 440);
	glFlush();
	gameIsEnded = true;
}