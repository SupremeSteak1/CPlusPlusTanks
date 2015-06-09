#include <stdafx.h>
#include <iostream>
#include "stdafx.h"
#include <string>
#include <windows.h>
#include <iostream>
#include <conio.h>
#include <sstream> 
#include <math.h>
#include <vector>

using namespace std;

// Include custom classes
#include"Tank.h"
#include"BaseGameLogic.h"
#include"RenderHandler.h"
#include"Trajectory.h"

double MOVE_BACK;
double MOVE_FORWARD;
double AIM_UP;
double AIM_DOWN;
double HEALTH_TANK;
double MOD_HEALTH;
double DAMAGE_TANK;
float EXPLOSION_RADIUS; 
int tank = 1;
int swatch = 1;
vector<vector<int>>* data;

Tank* tank1;
Tank* tank2;
Tank* currentTank;
Trajectory* trajectory;
RenderHandler* renderHandlerB;

BaseGameLogic::BaseGameLogic() {
	init();
}
void BaseGameLogic::init() {
	tank1 = new Tank();
	tank2 = new Tank();
	currentTank = tank1;
	trajectory = new Trajectory();
	renderHandlerB = new RenderHandler();

	MOVE_BACK = -.1;
	MOVE_FORWARD = .1;

	AIM_UP = 1;
	AIM_DOWN = -1;

	HEALTH_TANK = 100;
	
	MOD_HEALTH-=DAMAGE_TANK;

	DAMAGE_TANK = 20;

	EXPLOSION_RADIUS = 10;
}

void BaseGameLogic::toggleTank() {
	if (swatch == 1) {
		currentTank = tank1;
		swatch = 0;
	}

	if (swatch == 0) {
		currentTank = tank2;
		swatch = 1;
	} 
}
void BaseGameLogic::update() {
	// Game Start
	tankHealth();
	changeHealth();
	scoreboard();
	toggleTank();
}

void BaseGameLogic::tankForward() {
	currentTank->move(MOVE_FORWARD);
}

void BaseGameLogic::tankBack() {
	currentTank->move(MOVE_BACK);
}

void BaseGameLogic::tankUp() {
	currentTank->setAngle(AIM_UP);
}

void BaseGameLogic::tankDown(){
	currentTank->setAngle(AIM_DOWN);
}
void BaseGameLogic::tankShoot(){
	renderHandlerB->shoot(trajectory->trajectory(currentTank->x, currentTank->y, currentTank->y, currentTank->getPower(), currentTank->getAngle(), 999));
}
void BaseGameLogic::tankHealth(){
	currentTank->setHealth(HEALTH_TANK);
}
void BaseGameLogic::changeHealth(){
	currentTank->modHealth(MOD_HEALTH);
}
void BaseGameLogic::scoreboard() {
	// Every hit gives points equal to the amount of damage given
	// Amount of health for a tank is 100
}