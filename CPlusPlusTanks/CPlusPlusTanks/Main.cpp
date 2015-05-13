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
#include "Main.h"


using namespace std;

//This is where the control keys are specified.
//In order to use it elsewhere in the program, it MUST be defined here.
//in order to get the key codes look at the link below and follow the format specified by the already defined keys.
//http://msdn.microsoft.com/en-us/library/windows/desktop/dd375731%28v=vs.85%29.aspx
#define VK_W 0x57
#define VK_S 0x53
#define VK_UP 0x26
#define VK_ESCAPE 0x1B
#define VK_DOWN 0x28
#define VK_SPACE 0x20
#define VK_NEXT 0x22 //page down key
#define VK_PRIOR 0x21 //page up key
#define VK_E 0x45 //E key
#define VK_Q 0x51 //Q key

int windowWidth = GetSystemMetrics(SM_CXSCREEN);
int windowHeight = GetSystemMetrics(SM_CYSCREEN);
int targetFramerate = 60;

//Window title string
string windowTitle;

//Class objects
RenderHandler* renderHandler;


//Methods
void enable2D(int width, int height);
void init();
void draw();
void update(int useless);
void keyboard();

Main::Main(int argc, char** argv) {
	openGLInit(argc, argv);
	init();

    glutMainLoop();
}

Main::~Main() {

}

//Enables the 2D ability of OpenGL
void Main::enable2D(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0f, width, 0.0f, height, 0.0f, 1.0f);
    glMatrixMode (GL_MODELVIEW);
    glLoadIdentity();
}

//Initialize OpenGl
void Main::openGLInit(int argc, char** argv) {
	glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    //glutInitWindowSize(windowWidth, windowHeight);
	glutInitWindowSize(windowWidth, windowHeight);
    glutCreateWindow("Tanks");

	glutDisplayFunc(draw);
    glutTimerFunc(targetFramerate, update, 0);

    enable2D(windowWidth, windowHeight);
    glColor3f(1.0f, 1.0f, 1.0f);

	//(Un)comment if full screen is (not) desired
	//TODO: Add a fullscreen option in the options menu
	glutFullScreen();
}

//Initialize the program
void Main::init() {
	renderHandler = new RenderHandler();
	//gameLogic = new BaseGameLogic();
}

void Main::c_main( int position, int health, int shells, float angle) {

}





/*
 * Note that all of the following methods are not members of the class
 * because OpenGL requires that. This should not be a problem because
 * all the calling will be done BY these methods and not too them. If
 * it becomes a problem for whatever reason, talk to me (Thomas) and I
 * will see if I can find a workaround for it.
*/





//Update game visuals
void draw() {
	renderHandler->draw();
}

//Update game variables and logic
void update(int useless) {
	glutTimerFunc(targetFramerate, update, 0);
	//Do updating stuff here!
	renderHandler->update();
	//gameLogic->update();
	keyboard();
}

//Do respective actions when keyboard is pressed
void keyboard() {
	//REMEMBER TO MAKE SURE THE KEY YOU ARE TRYING TO USE IS DEFINED AT THE TOP OF THIS PAGE!!!
	if (GetAsyncKeyState(VK_ESCAPE)) {
		exit(EXIT_SUCCESS);
	}

	if (GetAsyncKeyState(VK_S)) {
		BaseGameLogic.moveBack(); 
	}

	if (GetAsyncKeyState(VK_W)) {
		BaseGameLogic.moveForward(); 
	}

	if (GetAsyncKeyState(VK_UP)) {
		BaseGameLogic.aimUp(); 
	}

	if (GetAsyncKeyState(VK_DOWN)) {
		BaseGameLogic.aimDown(); 
	}

	if (GetAsyncKeyState(VK_SPACE)) {
		BaseGameLogic.shootRound(); 
	}

	if (GetAsyncKeyState(VK_SPACE)) {
		BaseGameLogic.shootRound(); 
	}

	/*
	Example 1 -- Calling a method inside your own class to do what you
	need to do. This example shows the game being paused when the 'esc'
	key is pressed. Note that it is using the fictional class 'Game',
	and the fictional method togglePause():

	if (GetAsyncKeyState(VK_ESCAPE)) {
		Game.togglePause(); 
	}

	Example 2 -- Doing what you need to do right here. This example shows
	the game exiting when the 'esc' key is pressed:
	if (GetAsyncKeyState(VK_ESCAPE)) {
		exit(EXIT_SUCCESS);
	}
	*/
}