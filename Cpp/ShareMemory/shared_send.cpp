#include<sys/ipc.h>
#include<sys/shm.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
int main(){
	int shmid;
	int *num;
	int loop_i=1;
	int check_i=1000000;
	key_t key=12345;

	void *memory_segment=NULL;
	shmid=shmget(key,sizeof(int),IPC_CREAT|0666);
	if(shmid==-1){
		printf("shmget failed\n");
		exit(0);
	}

	memory_segment=shmat(shmid,NULL,0);
	if(memory_segment==(void*)-1){
			printf("shmat faild\n");
			exit(0);
	}
	
	num=(int*)memory_segment;

	while(1){
		(*num)++;
		printf("num is %d",(int)*num);
		sleep(1);
	}
	return 0;

}
