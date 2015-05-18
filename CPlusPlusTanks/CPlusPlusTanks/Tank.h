#ifndef TANK_H
#define TANK_H

class Tank
	{	private:
			int health;
			int shells;
			int pos;
			float angle;
			int power;
		public:
			int getHealth(void); //gets defined
			int getShells(void);
			int getPos(void);
			float getAngle(void);
			int getPower(void);
			void setHealth(int); //sets defined
			void setShells(int);
			void setPos(int);
			void setAngle(float);
			void setPower(int);
			Tank();					//tank constructor
			
	}; 
#endif