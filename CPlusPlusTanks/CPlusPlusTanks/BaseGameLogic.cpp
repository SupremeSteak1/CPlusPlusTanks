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

Tank tank1;
Tank tank2;

BaseGameLogic::BaseGameLogic() {
	init();
}
void BaseGameLogic::init() {
	MOVE_BACK = -.1;
	MOVE_FORWARD = .1;

	AIM_UP = 5;
	AIM_DOWN = -5;

	HEALTH_TANK = 100;

	DAMAGE_TANK = 20;

	EXPLOSION_RADIUS = 10;
}

void BaseGameLogic::update() {
	// Game Start
}

void BaseGameLogic::tankForward() {
	Tank.move(MOVE_FORWARD);
}

void BaseGameLogic::tankBack() {
	Tank.move(MOVE_BACK);
}

void BaseGameLogic::tankUp() {
	Tank.setAngle(AIM_UP);
}

void BaseGameLogic::tankDown() {
	Tank.setAngle(AIM_DOWN);
}

void BaseGameLogic::tankShoot() {

}