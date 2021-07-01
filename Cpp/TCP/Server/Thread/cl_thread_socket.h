#include <stdio.h>  
#include <stdlib.h>  
#include <unistd.h>  
#include <errno.h>  
#include <string.h>  
#include <sys/types.h>  
#include <sys/socket.h>  
#include <netinet/in.h>  
#include <netdb.h>  
#include <arpa/inet.h>  
#include <sys/wait.h>  
#include <pthread.h>  
#include <signal.h>  

#define PORT 7316

typedef struct thread_data{
	int fd;
	char ip[20];
}THREAD_DATA;

class cl_thread_socket{
	private :
		static void* fn_thread_run(void* arg);
		void* fn_get_in_addr(struct sockaddr* sa);

		//fn_run 
		int sockfd, new_fd;     
		struct sockaddr_storage client_addr;   
		struct sockaddr_in servaddr;   
		socklen_t sin_size;   
		char address[20];   
		int ret;   
		pthread_t thread_id;
		const unsigned int port;
		
		bool fn_setting();

		bool fn_bind();
		bool fn_listen();

		void fn_socket_run();


	public :
	 	void fn_run();	
		cl_thread_socket();
};
