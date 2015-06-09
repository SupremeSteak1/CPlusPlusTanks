#include "stdafx.h"
#include <iostream>
#include "Tank.h"
#include "Trajectory.h"

using namespace std;

int power;

Tank::Tank() {
	init(0, 0, 100, 50);
}

Tank::Tank(float x, float y, int health, int power) {
	init(x, y, health, power);
}

void Tank::init(float x, float y, int health, int power) {
	this->x = x;
	this->y = y;
	this->health = health;
	this->power = power;
}

void Tank::move(float xa) {
	x += xa;
}

void Tank::setLocation(float x, float y) {
	this->x = x;
	this->y = y;
}

int Tank::getAngle() {
	return angle;
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

int Tank::getPower() {
	return power;
}

void Tank::setPower(int power) {
	this->power = power;
}