#include<iostream>
#include<cctype>
#include<algorithm>
class StringTrim{
	private :
		std::string trim_msg;
	public :
		StringTrim();
		void rightTrim();
		void leftTrim();
		void setterTrimMsg(std::string msg);
		std::string getterTrimMsg();

};
