#pragma once
#include<iostream>
#include<map>
#include<cmath>
#include<math.h>
#define _USE_MATH_DEFINES
#include <corecrt_math_defines.h>
class QuaternionData
{
	
protected :
	double x, y, z, w;
	double roll, pitch, yaw;

	bool settingQuaternionData();
};

