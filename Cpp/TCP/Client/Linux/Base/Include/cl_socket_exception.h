#ifndef SocketException_class
#define SocketException_class

#include <string>

class cl_socket_exception
{
public:
	cl_socket_exception(std::string s) : m_s(s) {};
	~cl_socket_exception() {};

	std::string description() { return m_s; }

private:

	std::string m_s;

};

#endif
