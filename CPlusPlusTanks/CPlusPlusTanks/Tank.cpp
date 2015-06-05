#include "stdafx.h"
#include <iostream>
#include "Tank.h"

using namespace std;

Tank::Tank() {
	init(0, 0, 100);
}

Tank::Tank(float x, float y, int health) {
	init(x, y, health);
}

void Tank::init(float x, float y, int health) {
	this->x = x;
	this->y = y;
	this->health = health;
}

void Tank::move(float xa) {
	x += xa;
}

void Tank::setLocation(float x, float y) {
	this->x = x;
	this->y = y;
}

void Tank::modAngle(float angle) {
	this->angle += angle;
}

void Tank::setAngle(float angle) {
	this->angle = angle;
}

void Tank::modHealth(int health) {
	this->health += health;
}

void Tank::setHealth(int health) {
	this->health = health;
}