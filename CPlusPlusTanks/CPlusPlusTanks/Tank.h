#ifndef TANK_H
#define TANK_H
class Tank {
private:
	void init(float x, float y, int health);
	int health;
	float x;
	float y;
	float angle;
public:
	Tank();
	Tank(float x, float y, int health);
	void moveForward();
	void move(float xa);
	void setLocation(float x, float y);
	void modAngle(float angle);
	void setAngle(float angle);
	void modHealth(int health);
	void setHealth(int health);
};
#endif