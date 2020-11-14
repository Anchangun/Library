#include "Split.h"

std::vector<std::string> Split::splitRun(std::string origin_msg, char split_point){
	std::istringstream istream(origin_msg);
	std::string temp_msg;
	return_msg.clear();
	while (std::getline(istream, temp_msg, split_point)) {
		return_msg.push_back(temp_msg);
	}
	return return_msg;
}

std::vector<std::string> Split::splitCommaRun(std::string origin_msg)
{
	std::istringstream istream(origin_msg);
	std::string temp_msg;
	return_msg.clear();
	while (std::getline(istream, temp_msg, ',')) {
		return_msg.push_back(temp_msg);
	}


	return return_msg;
}
