#include<stdafx.h>
#include<iostream>
#include "stdafx.h"
#include <string>
#include <windows.h>
#include <iostream>
#include <conio.h>
#include <sstream> 
#include <math.h> 


// Include custom classes
#include"Tank.h"
#include"BaseGameLogic.h"
#include"RenderHandler.h"

double MOVE_BACK;
double MOVE_FORWARD;

Tank tank1;
Tank tank2;

int score;

BaseGameLogic::BaseGameLogic() {
	init();
}
void BaseGameLogic::init() {

	/*
	tank1 = new Tank();
	tank2 = new Tank();

	
	tank1.tank_health=100;
	tank1.tank_posx=5;
	tank1.tank_posy=0
	tank1.tank_shells=0;
	tank1.tank_angle=30;
	
	tank2.tank_health=100;
	tank2.tank_posx=95;
	tank2.tank_posy=0
	tank2.tank_shells=0;
	tank2.tank_angle=30;
	
	
	MOVE_BACK = -.1;
	MOVE_FORWARD = .1;
	*/
}
void BaseGameLogic::update() {
	// Game Start

	cout << "Hi";


}

int aimUp;
int aimDown;

int moveBack;
int moveForward;

moveBack = -.1;
moveForward = .1;

aimUp=5;
aimDown= 5;

tank_posx+=moveBack;
tank_posx+=moveForward;

tank_angle+=aimUp;
tank_angle+=aimDown;

keyboard();