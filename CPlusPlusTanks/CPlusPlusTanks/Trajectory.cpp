#include "stdafx.h"
#include "Trajectory.h"
#include <vector>
#include<math.h>

std::vector<std::vector<double>> trajectory(int xinitial, int yinitial, int yfinal, int speed, int angle, int count)
{
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	////the basic trajectory math is based on the projectile starting
	////at zero elevation and returning to zero elevation.  If that is
	////not the case the flight time is not twice the time it takes 
	////for Vy to be zero 0=Vy-gt(top) t(flight)=Vy/g
	////in the asymmetric case it is the greater of the two solutions
	////to yfinal = yinitial + Vytflight – 1/2*g*tflight^2
	////using the quadratic formula to solve ax^2+bx+c=0
	////x=(-b+(b^2-4ac)^0.5)/2a and x=(-b-(b^2-4ac)^0.5)/2a
	////in our case the answer is surprisingly the second solution
	////making the indicated substitutions we find
	////tfight=(-Vy-(Vy^2-4*(-g)*(yinitial-yfinal))^0.5)/2/(-g) 
	////(my apologies for the ugly notation – here ^2 is squared and 
	////^0.5 is square root
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	////
	//// g is the gravitational constant in ft/sec/sec
	float g = float(16);
	////
	//// assuming xinitial is zero but it could be something else to 
	//// make the UI easier (in ft)
	////xinitial = float(input("xinitial(ft)="))
	////xinitial = float(0)
	////
	//// yinitial is the height of the muzzle in feet and should be fixed
	////yinitial = float(input("yinitial(ft)="))
	////yinitial = float(0)
	////
	////input angle in degrees from horizontal
	////yfinal = float(input("yfinal(ft)="))
	////
	////input angle in degrees from horizontal
	////angle = float(input("angle(degrees)="))
	////
	////input the muzzle velocity/speed should be a constant 
	////it should be displayed in the UI
	////speed = float(input("speed(ft/sec)="))
	////
	////input count, this is an internal value used to determine 
	////how many points along the trajectory we will calculate and
	////display eventually
	////count = float(input("count(int)="))
	//converting angle to radians for use in trig functions
	//radians = degrees * pi / 180 
	double angleR = angle*3.14159265358979323846/180;
	//
	//calculating the horizontal and vertical components of the initial velocity
	float VY = float(speed * sin(angleR));
	float VX = float(speed * cos(angleR));
	//
	//print is only for initial debugging
	//print ('VX=', VX)
	//print ('VY=', VY)
	//
	//if we were starting from y=0 and returning to y=0, then
	// flight time = 2*time to top of flight or when VY=0
	// the 1000 in the following line give us mill
	// tflight=int(2*(VY/16)*1000)
	//
	// for an asymmetric trajectory the flight time in seconds is
	// tfight=(-VY-(VY^2-4*(-g)*(yinitial-yfinal))^0.5)/2/(-g)
	float tflight=(VY+sqrt(VY*VY-4*(-g)*(yinitial-yfinal)))/2/g;
	//
	// tinterval in milliseconds
	//
	float tinterval=2*1000*tflight/count;
	float xmax=xinitial+VX*tflight;
	float ymax=yinitial+VY*tflight/2-2*tflight*tflight;
	double icount=int(count);
	float tt=float(0);

	//print ('Flight time in seconds=', tflight)
	//print ('time interval in milliseconds=', tinterval)
	//print ('range=', xmax)
	//print ('peak=', ymax)
	//print ('icount=', icount)
	//print ('t=', t)
	//
	// using a dictionary to store two dimensional results
	// we'll put t in col 0, x in col 1, and y in col 2
	std::vector<double> t(icount,0);
	std::vector<double> x(icount,0);
	std::vector<double> y(icount,0);
	std::vector<std::vector<double>> txy;
	txy.resize(4);
	t.resize(9999);
	x.resize(9999);
	y.resize(9999);
	for (int i=0;i<icount+1;i++)
	{
		t[i]=t.at(0)*3;
	}
	//time to loop
	for (int i=0;i<icount+1;i++)
	{
	    double xx= xinitial+VX*tt;
	    double yy= yinitial+(VY*tt)-(g/2*tt*tt);
	    t[i]=tt;
	    x[i]=xx;
	    y[i]=yy;
	    // increment the time
	    tt = tt + tinterval/1000;
	}

	//t;
	//x.resize();
	//y.resize();

	txy[0]=t;
	txy[1]=x;
	txy[2]=y;
	return txy;
}