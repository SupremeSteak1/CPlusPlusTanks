#include <stdafx.h>
#include <iostream>
#include "stdafx.h"
#include <string>
#include <windows.h>
#include <iostream>
#include <conio.h>
#include <sstream> 
#include <math.h>

using namespace std;

// Include custom classes
#include"Tank.h"
#include"BaseGameLogic.h"
#include"RenderHandler.h"

double MOVE_BACK;
double MOVE_FORWARD;
double AIM_UP;
double AIM_DOWN;
double HEALTH_TANK;
double MOD_HEALTH;
double DAMAGE_TANK;
float EXPLOSION_RADIUS; 

Tank* tank1;
Tank* tank2;

BaseGameLogic::BaseGameLogic() {
	init();
}
void BaseGameLogic::init() {
	tank1 = new Tank();

	MOVE_BACK = -.1;
	MOVE_FORWARD = .1;

	AIM_UP = 5;
	AIM_DOWN = -5;

	HEALTH_TANK = 100;
	
	MOD_HEALTH-=DAMAGE_TANK;

	DAMAGE_TANK = 20;

	EXPLOSION_RADIUS = 10;
}

void BaseGameLogic::update() {
	// Game Start
}

void BaseGameLogic::tankForward() {
	tank1->move(MOVE_FORWARD);
}

void BaseGameLogic::tankBack() {
	tank1->move(MOVE_BACK);
}

void BaseGameLogic::tankUp() {
	tank1->setAngle(AIM_UP);
}

void BaseGameLogic::tankDown() {
	tank1->setAngle(AIM_DOWN);
}

void BaseGameLogic::tankShoot() {
	// For later
}

void BaseGameLogic::tankHealth() {
	tank1->setHealth(HEALTH_TANK);
}

void BaseGameLogic::changeHealth() {
	tank1->modHealth(MOD_HEALTH);
}

void BaseGameLogic::scoreBoard() {
}