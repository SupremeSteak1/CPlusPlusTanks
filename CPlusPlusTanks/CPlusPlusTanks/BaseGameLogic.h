#ifndef BASEGAMELOGIC_H
#define BASEGAMELOGIC_H


class BaseGameLogic {
private:
	void init();
public:
	BaseGameLogic();
	void update();
	void toggleTank();
	void tankForward();
	void tankBack();
	void tankUp();
	void tankDown();
	void tankShoot();
	void tankHealth();
	void changeHealth();
	void scoreboard();
	void setPower(int power);
	int getPower();
	void setAngle(int angle);
	int getAngle();
};
#endif