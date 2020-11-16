#include "EulerToQuaternion.h"

EulerToQuaternion::EulerToQuaternion()
{
	settingQuaternionData();
	cos_roll=0;
	sin_roll=0;
	cos_pitch=0;
	sin_pitch=0;
	cos_yaw=0;
	sin_yaw=0;
	origin_w_magnification=0; //w * 4
}

std::map<std::string, double> EulerToQuaternion::eulerToQuaternion(double roll, double pitch, double yaw)
{
	cos_roll = std::cos(roll);
	sin_roll = std::sin(roll);
	cos_pitch = std::cos(pitch);
	sin_pitch = std::sin(pitch);
	cos_yaw = std::cos(yaw);
	sin_yaw = std::sin(yaw);
	w = std::sqrt(1.0 + cos_roll * cos_pitch + cos_roll * cos_yaw - sin_roll * sin_pitch * sin_yaw + cos_pitch * cos_yaw) / 2.0;
	map_euler.insert({"w",w});
	origin_w_magnification = (4.0 * w);

	x = (cos_pitch * sin_yaw + cos_roll * sin_yaw + sin_roll * sin_pitch * cos_yaw) / origin_w_magnification;
	map_euler.insert({ "x",x });

	y = (sin_roll * cos_pitch + sin_roll * cos_yaw + cos_roll * sin_pitch * sin_yaw) / origin_w_magnification;
	map_euler.insert({ "y",y });
	z = (-sin_roll * sin_yaw + cos_roll * sin_pitch * cos_yaw + sin_pitch) / origin_w_magnification;
	map_euler.insert({ "z",z });
	return map_euler;
}
