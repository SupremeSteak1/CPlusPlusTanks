#ifndef BASEGAMELOGIC_H
#define BASEGAMELOGIC_H

class BaseGameLogic {
private:
	void init();
public:
	BaseGameLogic();
	void update();
	void tankForward();
	void tankBack();
	void tankUp();
	void tankDown();
	void tankShoot();
	void tankHealth();
	void changeHealth();
	void scoreBoard();
};
#endif