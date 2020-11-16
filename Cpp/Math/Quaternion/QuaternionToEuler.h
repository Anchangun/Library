#pragma once

#include "QuaternionData.h"


class QuaternionToEuler : public QuaternionData
{
private :
	double square_w;
	 double square_x;
	 double square_y;
	 double square_z;
	 double square_sum;
	 double origin_sum;
	 double siny_cosp;
	 double cosy_cosp;
	 std::map<std::string, double> map_quaternion;
	
public :
	QuaternionToEuler();
	std::map<std::string, double> QuaternionToEulerAngles();
	void squareQuaternion();
	void setterX(double setX);
	void setterY(double setY);
	void setterZ(double setZ);
	void setterW(double setW);
};

