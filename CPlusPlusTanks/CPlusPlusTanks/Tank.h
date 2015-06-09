#ifndef TANK_H
#define TANK_H
class Tank {
private:
	void init(float x, float y, int health, int power);
	int health;
	int power;
	float angle;
public:
	Tank();
	Tank(float x, float y, int health, int power);
	float x;
	float y;
	void moveForward();
	void move(float xa);
	void setLocation(float x, float y);
	int getAngle();
	void modAngle(float angle);
	void setAngle(float angle);
	void modHealth(int health);
	void setHealth(int health);
	int getPower();
	void setPower(int power);
};
#endif