#include "Split.h"

std::vector<std::string> Split::splitAll(std::string origin_msg){
	int i = 0;
	return_msg.clear();
	while (i < origin_msg.size()) {
		return_msg.push_back(origin_msg.substr(i,1));
		i++;
	}
	return return_msg;
}

std::vector<std::string> Split::splitRun(std::string origin_msg, char split_point){
	std::istringstream istream(origin_msg);
	std::string temp_msg;
	return_msg.clear();
	while (std::getline(istream, temp_msg, split_point)) {
		return_msg.push_back(temp_msg);
	}
	return return_msg;
}

std::vector<std::string> Split::splitMsg(std::string origin_msg, std::string cut_point){
	size_t prev_msg = 0, current_msg = 0;
	int size_cut_point = cut_point.length();
	std::vector<std::string> v_result;
	current_msg = origin_msg.find(cut_point);
	while (current_msg != std::string::npos) {
		std::string temp = origin_msg.substr(prev_msg, current_msg - prev_msg);
		v_result.push_back(temp);
		prev_msg = current_msg+ cut_point.length();
		current_msg = origin_msg.find(cut_point, prev_msg);
	}
	v_result.push_back(origin_msg.substr(prev_msg, current_msg - prev_msg));
	return v_result;
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


std::vector<std::string> Split::splitSpaceRun(std::string origin_msg) {
	std::istringstream istream(origin_msg);
	std::string temp_msg;
	return_msg.clear();
	while (std::getline(istream, temp_msg, ' ')) {
		return_msg.push_back(temp_msg);
	}
	return return_msg;
}

std::vector<std::string> Split::splitBackSlashRun(std::string origin_msg) {
	std::istringstream istream(origin_msg);
	std::string temp_msg;
	return_msg.clear();
	while (std::getline(istream, temp_msg, '\\')) {
		return_msg.push_back(temp_msg);
	}
	return return_msg;
}
