#pragma once


#include<iostream>
#include<fstream>
#include<string>

class WriteFile
{
	private :
		std::ofstream ofstream_write_file;
	public :
		WriteFile();
		WriteFile(std::string interface_file_name);
		bool setterWriteFile(std::string string_msg);

	protected:
		std::string string_write_file_name;

};

