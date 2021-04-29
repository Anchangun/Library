#include "cl_client_socket.h"
#include "cl_socket_exception.h"


cl_client_socket::cl_client_socket(std::string host, int port)
{
	if (!cl_socket::create())
	{
		throw cl_socket_exception("Could not create client socket.");
	}

	if (!cl_socket::connect(host, port))
	{
		throw cl_socket_exception("Could not bind to port.");
	}

}

void cl_client_socket::sendMessage(std::string send_msg)
{
	if(!cl_socket::send(send_msg)){
		throw cl_socket_exception("send msg error");	
	}
	//cl_socket::send(send_msg);
}

std::string cl_client_socket::fn_recv_message(std::string recv_message){
	if(!cl_socket::recv(recv_message)){
		throw cl_socket_exception("Could not read from socket.");
	}
	std::cout<<"test 1 "+recv_message<<std::endl;
	//std::cout<<"test 2"+cl_socket::fn_get_recv_msg();
	return recv_message;
}

