#include"StringMsg/DataTypeConvert.h"

float DataTypeConvert::stringToFloat(std::string string_data){
	float temp_float;
	temp_float=std::stof(string_data);
	return temp_float;
}
