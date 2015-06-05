#ifndef TRAJECTORY_H
#define TRAJECTORY_H

#include<vector>
class Trajectory {
	std::vector<std::vector<double>> trajectory(int xinitial, int yinitial, int yfinal, int speed, int angle, int count);
};
#endif