#include<stdafx.h>
#include<iostream>

// Include custom classes
#include"Tank.h"
#include"BaseGameLogic.h"

double MOVE_BACK;
double MOVE_FORWARD;

Tank tank1;
Tank tank2;

BaseGameLogic::BaseGameLogic() {
	init();
}
void BaseGameLogic::init() {
	/*
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
	*/
	
	MOVE_BACK = -.1;
	MOVE_FORWARD = .1;
}
void BaseGameLogic::update() {

}