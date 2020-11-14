#pragma once

#include<iostream>
#include<fstream>
#include<string>

class ReadFile
{
private :
	std::ifstream ifstream_read_file;
	std::string string_read_msg;
	std::string string_temp_msg;
	std::string string_return_msg;

public:
	ReadFile();
	ReadFile(std::string interface_file_name);
	std::string getterReadFile();
protected :
	std::string string_read_file_name;
};

