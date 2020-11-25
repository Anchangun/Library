#include "DegreeConvert.h"

double DegreeConvert::degreeToRadian(double degree){

	return degree * M_PI / 180;
}

double DegreeConvert::radianToDegree(double radian)
{


	return radian * 180 / M_PI;
}
