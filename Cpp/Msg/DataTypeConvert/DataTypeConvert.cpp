#include"StringMsg/DataTypeConvert.h"
float DataTypeConvert::stringToFloat(std::string string_data){
	float temp_float;
	temp_float=std::stof(string_data);
	return temp_float;
}

int DataTypeConvert::stringToInt(std::string string_data)
{
	int convert = std::stoi(string_data);
	return convert;
}
