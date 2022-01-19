#pragma once

#include<iostream>
#include<string>
#include<vector>
#include<sstream>


class Split
{
private :

	std::vector<std::string> return_msg;

public :
	std::vector<std::string> splitRun(std::string origin_msg,char split_point);
	std::vector<std::string> splitMsg(std::string origin_msg, std::string cut_point);
	std::vector<std::string> splitCommaRun(std::string origin_msg);
	std::vector<std::string> splitAll(std::string origin_msg);
	std::vector<std::string> splitSpaceRun(std::string origin_msg);
	std::vector<std::string> splitBackSlashRun(std::string origin_msg);
};
