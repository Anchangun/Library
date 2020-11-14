#include"string_msg/StringTrim.h"

StringTrim::StringTrim(){}

void StringTrim::rightTrim(){
	trim_msg.erase(std::find_if(trim_msg.rbegin(), trim_msg.rend(), [](int int_ch)
			       	{
				return !std::isspace(int_ch);
				}).base(), trim_msg.end());
}

void StringTrim::leftTrim(){
	trim_msg.erase(trim_msg.begin(), std::find_if(trim_msg.begin(), trim_msg.end(), [](int int_ch) {
				return !std::isspace(int_ch);
				}));
}

void StringTrim::setterTrimMsg(std::string msg){
	trim_msg=msg;
}

std::string StringTrim::getterTrimMsg(){
	return trim_msg;
}
