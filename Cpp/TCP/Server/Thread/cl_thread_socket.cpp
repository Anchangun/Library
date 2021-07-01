#include "Communication/cl_thread_socket.h"
cl_thread_socket::cl_thread_socket():port(PORT){
}


void* cl_thread_socket::fn_thread_run(void* arg){
	THREAD_DATA* client_data;
	char buf[1024];
	pthread_detach(pthread_self());  
	client_data=(THREAD_DATA*)arg;
	int fd=client_data->fd;
	char ip[20];
	strcpy( ip, client_data->ip);  
	while(1)  
	{  
		int num;  
		num = read( fd, buf, sizeof(buf) );  
		if ( num == 0 ){
		       	break;  
		}
		printf("recv : [%s]\n", buf );  
		write(fd, buf, strlen(buf));  
	}  
	printf("disconnected client ip %s\n", ip );  
	free(client_data);  
	close(client_data->fd);  
}

void* cl_thread_socket::fn_get_in_addr(struct sockaddr *sa)  
{  
	if (sa->sa_family == AF_INET) {  
		return &(((struct sockaddr_in*)sa)->sin_addr);  
	}  

	return &(((struct sockaddr_in6*)sa)->sin6_addr);  
}  

bool cl_thread_socket::fn_bind(){	
	ret = bind(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr));  
	if ( ret != 0 )  
	{  
		perror("bind");  
		exit(-1);  
	}  
	return true;
}

bool cl_thread_socket::fn_listen(){
	ret = listen(sockfd, 5);  
	if ( ret != 0 )  
	{  
		perror("listen");  
		exit(-1);  
	}  
	return true;
}

void cl_thread_socket::fn_socket_run(){	
	while(1) { 
		std::cout<<"[Changun] Class cl_thread_socket, func fn_socket_run, data : start" <<std::endl; 

		sin_size = sizeof client_addr;  
		new_fd = accept(sockfd, (struct sockaddr *)&client_addr, &sin_size);  
		if (new_fd == -1) {  
			perror("accept");  
			continue;  
		}  

		inet_ntop(client_addr.ss_family,  
		fn_get_in_addr((struct sockaddr *)&client_addr),address, sizeof address);  
		printf("server: got connection from %s\n", address); 

		THREAD_DATA *data;  
		data= (THREAD_DATA*)malloc(sizeof(THREAD_DATA));    
		data->fd = new_fd;  
		strcpy( data->ip,address);   
		pthread_create( &thread_id, NULL, (&cl_thread_socket::fn_thread_run),(void*)data );  
	}  
}
bool cl_thread_socket::fn_setting(){
	signal( SIGPIPE, SIG_IGN );  
	sockfd = socket(AF_INET, SOCK_STREAM,0);  
	bzero( &servaddr, sizeof(servaddr));  
	servaddr.sin_family = AF_INET;  
	servaddr.sin_addr.s_addr = INADDR_ANY;  
	servaddr.sin_port = htons(port);  
}

void cl_thread_socket::fn_run(){
	fn_setting();
	fn_bind();
	fn_listen();		  
	fn_socket_run();
}
