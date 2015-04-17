// CPlusPlusTanks.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <windows.h>
#include <iostream>
#include <conio.h>
#include <sstream> 
#include <math.h> 
#include <gl\gl.h>
#include <gl\glu.h>
#include "GL/freeglut.h"
#pragma comment(lib, "Opengl32.lib")

//Include custom classes
#include "RenderHandler.h"

using namespace std;

//This is Gus's comment
//Another comment for Thomas to test with...

//This is where the control keys are specified.
//In order to use it elsewhere in the program, it MUST be defined here.
//in order to get the key codes look at the link below and follow the format specified by the already defined keys.
//http://msdn.microsoft.com/en-us/library/windows/desktop/dd375731%28v=vs.85%29.aspx
#define VK_W 0x57
#define VK_S 0x53
#define VK_ESCAPE 0x1B

int windowWidth = GetSystemMetrics(SM_CXSCREEN);
int windowHeight = GetSystemMetrics(SM_CYSCREEN);
int targetFramerate = 60;

string windowTitle;

//Class objects
RenderHandler* renderHandler;

//Methods
void enable2D(int width, int height);
void init();
void draw();
void update(int useless);
void keyboard();

int _tmain(int argc, char** argv) {
	glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    //glutInitWindowSize(windowWidth, windowHeight);
	glutInitWindowSize(1600,900);
    glutCreateWindow("Tanks");

	glutDisplayFunc(draw);
    glutTimerFunc(targetFramerate, update, 0);

    enable2D(windowWidth, windowHeight);
    glColor3f(1.0f, 1.0f, 1.0f);

	//Uncomment if full screen is desired
	//TODO: Add a fullscreen option in the options menu
	//glutFullScreen();

	init();

    glutMainLoop();
	return 0;
}

//Enables the 2D ability of OpenGL
void enable2D(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0f, width, 0.0f, height, 0.0f, 1.0f);
    glMatrixMode (GL_MODELVIEW);
    glLoadIdentity();
}

//Initialize the program
void init() {
	renderHandler = new RenderHandler();
}

//Update game visuals
void draw() {
	renderHandler->draw();
}

//Update game variables and logic
void update(int useless) {
	glutTimerFunc(targetFramerate, update, 0);
	//Do updating stuff here!
	renderHandler->update();
	keyboard();
}

//Do respective actions when keyboard is pressed
void keyboard() {
	//REMEMBER TO MAKE SURE THE KEY YOU ARE TRYING TO USE IS DEFINED AT THE TOP OF THIS PAGE!!!
	if (GetAsyncKeyState(VK_ESCAPE)) {
		exit(EXIT_SUCCESS);
	}
	/*
    if (GetAsyncKeyState(VK_W));
    if (GetAsyncKeyState(VK_S));

    if (GetAsyncKeyState(VK_UP));
    if (GetAsyncKeyState(VK_DOWN));
	*/
}