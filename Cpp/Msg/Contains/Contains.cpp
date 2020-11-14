#include "StringMsg/Contains.h"

bool Contains::dataCheck(std::string msg,std::string check_data)
{
	if (msg.find(check_data) != std::string::npos) {
		return true;
	}
	else
		return false;
}
