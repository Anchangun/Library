
#ifndef ClientSocket_class
#define ClientSocket_class

#include "cl_socket.h"
#include"common.h"

class cl_client_socket : private cl_socket
{
public:

	cl_client_socket(std::string host, int port);
	virtual ~cl_client_socket() {};
	void sendMessage(std::string send_msg);
	std::string fn_recv_message(std::string recv_message);
};


#endif
