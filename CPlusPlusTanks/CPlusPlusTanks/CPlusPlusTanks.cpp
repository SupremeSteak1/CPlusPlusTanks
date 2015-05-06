// CPlusPlusTanks.cpp : Defines the entry point for the console application.
//
//Include precompiled headers
#include "stdafx.h"

//Include custom classes
#include "Main.h"

int _tmain(int argc, char** argv) {
	new Main(argc, argv);
}


void tank_main( int position, health, shells, angle)
	class Tank
	{
		std::gettank_health;
		std::gettank_pos;
		std::gettank_shells;
		std::gettank_angle;
    
	}
/*
This area is being used to describe how the Main class works.
Main::Main()       -- This is used to initialize all the OpenGL stuff, and any other things.
					  This should not be touched unless adding custom init methods.
Main::openGLInit() -- Don't touch
Main::init()	   -- Put anything that needs to be run ONCE in here.
					  If you have a lot of stuff, create your own init method to manage the code better.
void update()	   -- This is called 60 times a second.
					  All of the updating should be done from here, calling your own class' method.
					  THIS IS EFECTIVLY THE WHILE TRUE LOOP THAT WOULD OTHERWISE BE IN THE MAIN METHOD.
void draw()		   -- This is called as many times as possible a second, and should not be touched.
void keyboard()	   -- This gets keyboard input using if statments.
					  It is called from the update method, meaning that it is called 60 times a second
					  See examples in the method itself.
*/