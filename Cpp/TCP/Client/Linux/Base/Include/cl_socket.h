// Definition of the Socket class

#ifndef Socket_class
#define Socket_class
#include"common.h"
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <arpa/inet.h>


const int MAXHOSTNAME = 200;
const int MAXCONNECTIONS = 5;
const int MAXRECV = 500;

class cl_socket
{
private : 
	std::string recv_msg;	
	int m_sock;
	sockaddr_in m_addr;


public:
	cl_socket();
	virtual ~cl_socket();

	//@brief Server initialization
	bool create();
	bool bind(const int port);
	bool listen() const;
	bool accept(cl_socket&) const;

	//@brief Client initialization
	bool connect(const std::string host, const int port);

	//@brief Data Transimission
	bool send(const std::string) const;
	int recv(std::string&) const;


	void set_non_blocking(const bool);

	bool is_valid() const { return m_sock != -1; }

};


#endif
