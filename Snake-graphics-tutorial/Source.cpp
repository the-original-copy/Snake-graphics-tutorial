
#include<GL/freeglut.h>
#include "Draw.h"
#include <string>
#include<stdlib.h>

#define COLUMNS 100
#define ROWS 100
#define FPS 10

int score = 0;

extern short sDirection;
bool gameOver;
void reshape_callback(int, int);
void display_callback();
void timer_callback(int);
void keyboard_callback(int, int, int);

void init() {
	glClearColor(0.5, 1.0, 1, 1.0);
	initGrid(COLUMNS, ROWS);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Plastino");
	glutDisplayFunc(display_callback);
	glutReshapeFunc(reshape_callback);
	glutTimerFunc(0,timer_callback,0);
	glutSpecialFunc(keyboard_callback);
	init();
	glutMainLoop();
	return 0;
}


void display_callback() {
	glClear(GL_COLOR_BUFFER_BIT);
	//drawGrid();
	drawSnake();
	drawFood();
	glutSwapBuffers();
	if (gameOver) {
		char _score[10];
		_itoa_s(score, _score, 10);
		char text[50] = "Your score: ";
		strcat_s(text, _score);
		MessageBox(NULL,(LPCWSTR) text, L"GAME OVER", 0);
		exit(0);
	}
}

void reshape_callback(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, COLUMNS, 0.0, ROWS, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);

}

void timer_callback(int) {
	glutPostRedisplay();
	glutTimerFunc(1000 / FPS, timer_callback, 0);
}

void keyboard_callback(int key, int, int) {
	switch (key) {
	case GLUT_KEY_UP:
		if (sDirection != UP)
			sDirection = UP;
		break;

	case GLUT_KEY_DOWN:
		if (sDirection != DOWN)
			sDirection = DOWN;
		break;

	case GLUT_KEY_RIGHT:
		if (sDirection != RIGHT)
			sDirection = RIGHT;
		break;

	case GLUT_KEY_LEFT:
		if (sDirection != LEFT)
			sDirection = LEFT;
		break;

	}
}