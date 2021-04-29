#include "cl_socket.h"
#include"common.h"

cl_socket::cl_socket() :
	m_sock(-1){
	memset(&m_addr,
		0,
		sizeof(m_addr));
}

cl_socket::~cl_socket(){
	if (is_valid())
		::close(m_sock);
}

bool cl_socket::create()
{
	m_sock = socket(AF_INET,
		SOCK_STREAM,
		0);

	if (!is_valid())
		return false;


	// TIME_WAIT - argh
	int on = 1;
	if (setsockopt(m_sock, SOL_SOCKET, SO_REUSEADDR, (const char*)&on, sizeof(on)) == -1)
		return false;

	return true;

}



bool cl_socket::bind(const int port)
{

	if (!is_valid())
	{
		std::cout<<"bind is Data unvaild Fail"<<std::endl;
		return false;
	}

	m_addr.sin_family = AF_INET;
	m_addr.sin_addr.s_addr = INADDR_ANY;
	m_addr.sin_port = htons(port);

	int bind_return = ::bind(m_sock,
		(struct sockaddr *) &m_addr,
		sizeof(m_addr));

	if (bind_return == -1)
	{
		return false;
	}

	return true;
}


bool cl_socket::listen() const
{
	if (!is_valid())
	{
		std::cout<<"listen is Data unvaild Fail"<<std::endl;
		return false;
	}

	int listen_return = ::listen(m_sock, MAXCONNECTIONS);


	if (listen_return == -1)
	{

		return false;
	}

	return true;
}


bool cl_socket::accept(cl_socket& new_socket) const
{
	int addr_length = sizeof(m_addr);
	new_socket.m_sock = ::accept(m_sock, (sockaddr *)&m_addr, (socklen_t *)&addr_length);

	if (new_socket.m_sock <= 0)
		return false;
	else
		return true;
}


bool cl_socket::send(const std::string send_msg) const
{
	int status = ::send(m_sock, send_msg.c_str(), send_msg.size(), MSG_NOSIGNAL);
	if (status == -1)
	{
			std::cout<< "send msg false" <<std::endl;
		return false;
	}
	else
	{
			std::cout<< "send msg true" <<std::endl;
		return true;
	}
}


int cl_socket::recv(std::string& recv_msg) const
{
	char buf[MAXRECV + 1];

	recv_msg = "";

	memset(buf, 0, MAXRECV + 1);

	int status = ::recv(m_sock, buf, MAXRECV, 0);

	if (status == -1)
	{
		std::cout << "status == -1   errno == " << errno << "  in Socket::recv\n";
		return 0;
	}
	else if (status == 0)
	{
		return 0;
	}
	else
	{
		recv_msg = buf;
		return status;
	}
}



bool cl_socket::connect(const std::string host, const int port)
{
	if (!is_valid()) return false;

	m_addr.sin_family = AF_INET;
	m_addr.sin_port = htons(port);

	int status = inet_pton(AF_INET, host.c_str(), &m_addr.sin_addr);

	if (errno == EAFNOSUPPORT) return false;

	status = ::connect(m_sock, (sockaddr *)&m_addr, sizeof(m_addr));

	if (status == 0)
		return true;
	else
		return false;
}

void cl_socket::set_non_blocking(const bool b)
{

	int opts;

	opts = fcntl(m_sock,
		F_GETFL);

	if (opts < 0)
	{
		return;
	}

	if (b)
		opts = (opts | O_NONBLOCK);
	else
		opts = (opts & ~O_NONBLOCK);

	fcntl(m_sock,
		F_SETFL, opts);

}


