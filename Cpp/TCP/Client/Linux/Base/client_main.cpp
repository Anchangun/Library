#include "cl_client_socket.h"
#include "cl_socket_exception.h"
#include"common.h"

int main(int argc, int **argv)
{
	try
	{
		const std::string ip = "192.168.0.1";
		const int port= 1234
		cl_client_socket client_socket(ip, port);

		std::string reply;

		try
		{
			client_socket.sendMessage("Test message");
			reply=client_socket.fn_recv_message(reply);
		}
		catch (cl_socket_exception&) {}

		std::cout << "from the server:\n\"" << reply << "\"\n";;

	}
	catch (cl_socket_exception& e)
	{
		std::cout << "Exception was caught:" << e.description() << "\n";
	}

	return 0;
}
