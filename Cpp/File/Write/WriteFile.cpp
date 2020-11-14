#include "WriteFile.h"

WriteFile::WriteFile()
{
}

WriteFile::WriteFile(std::string interface_file_name) 
{
	string_write_file_name = interface_file_name;
}

bool WriteFile::setterWriteFile(std::string string_msg)
{
	ofstream_write_file.open(string_write_file_name);
	ofstream_write_file.write(string_msg.c_str(), string_msg.size());
	ofstream_write_file.close();
	return true;
}
