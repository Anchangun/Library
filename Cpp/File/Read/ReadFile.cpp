#include "ReadFile.h"

ReadFile::ReadFile()
{
}

ReadFile::ReadFile(std::string interface_file_name)
{
	string_read_msg.clear();
	string_temp_msg.clear();
	string_return_msg.clear();
	string_read_file_name = interface_file_name;
}


std::string ReadFile::getterReadFile()
{
	ifstream_read_file.open(string_read_file_name);
		if (ifstream_read_file.is_open()) {
			while (!ifstream_read_file.eof())
			{
				getline(ifstream_read_file, string_temp_msg);
				
				if (true== string_read_msg.empty())
					string_read_msg = string_temp_msg + " ";
				else
					string_read_msg = string_read_msg + " " + string_temp_msg + " ";
			}
		}
		else {
			string_return_msg = "Empty";
			return string_return_msg;
		}
		
		ifstream_read_file.close();
	
	return string_read_msg;
}
