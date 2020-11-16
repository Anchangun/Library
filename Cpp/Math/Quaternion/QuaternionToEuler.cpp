#include "QuaternionToEuler.h"

QuaternionToEuler::QuaternionToEuler()
{
	settingQuaternionData();
	 square_w=0;
	 square_x=0;
	 square_y=0;
	 square_z=0;
	 square_sum=0;
	 origin_sum=0;
	 siny_cosp=0;
	 cosy_cosp=0;
}

std::map<std::string, double> QuaternionToEuler::QuaternionToEulerAngles()
{
	squareQuaternion();
	square_sum = square_x + square_y + square_z + square_w;
	origin_sum = x * y + z * w;
	if (origin_sum > 0.499 * square_sum) {
		roll = 2 * std::atan2(x, w);
		pitch = M_PI / 2;
		yaw = 0;
		map_quaternion.insert({ "roll", roll });
		map_quaternion.insert({ "pitch", pitch });
		map_quaternion.insert({ "yaw", yaw });
		return map_quaternion;
	}
	else if (origin_sum < -0.499) {
		roll = -2 * std::atan2(x, w);
		pitch = -M_PI / 2;
		yaw = 0;
		map_quaternion.insert({ "roll", roll });
		map_quaternion.insert({ "pitch", pitch });
		map_quaternion.insert({ "yaw", yaw });
		return map_quaternion;
	}
	roll = std::atan2(2 * y * w - 2 * x * z, square_x - square_y - square_z + square_w);
	pitch = std::asin(2 * origin_sum / square_sum);



	siny_cosp = 2 * (x * w - y * z);

	cosy_cosp = -x * x + y * y - z * z + w * w;
	yaw = std::atan2(siny_cosp, cosy_cosp);
	map_quaternion.insert({ "roll", roll });
	map_quaternion.insert({ "pitch", pitch });
	map_quaternion.insert({"yaw", yaw});
	return map_quaternion;
}

void QuaternionToEuler::squareQuaternion()
{
	square_w = w * w;
	square_x = x * x;
	square_y = y * y;
	square_z = z * z;
}

void QuaternionToEuler::setterX(double setX)
{
	x = setX;
}

void QuaternionToEuler::setterY(double setY)
{
	
	y = setY;
}

void QuaternionToEuler::setterZ(double setZ)
{

	z = setZ;
}

void QuaternionToEuler::setterW(double setW)
{
	w = setW;
}
