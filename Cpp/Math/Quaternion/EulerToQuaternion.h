#pragma once
#include "QuaternionData.h"
class EulerToQuaternion :
    public QuaternionData
{
private :
	double cos_roll;
	double sin_roll;
	double cos_pitch;
	double sin_pitch;
	double cos_yaw;
	double sin_yaw;
	double origin_w_magnification; //w * 4
public :
	EulerToQuaternion();
	std::map<std::string, double> eulerToQuaternion(double roll, double pitch, double yaw);


};
