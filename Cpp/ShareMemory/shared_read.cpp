#include<unistd.h>                                         
#include<sys/ipc.h>
#include<sys/shm.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>

int main(){
	int shmid;
	key_t key =12345;
	int share_delete;
	void* memory_segment;
	shmid=shmget(key,sizeof(int),0666);
	if(shmid==-1){
		printf("shmget failed\n");
		exit(0);
	}
	memory_segment=shmat(shmid,NULL,0);
	if(memory_segment==(void*)-1){
		printf("shmat failed \n");
		exit(0);
	}
	while(1){
		
		int* num=(int*)memory_segment;
		if(*num==1000){
			share_delete=shmctl(shmid,IPC_RMID,0);
			if(share_delete==-1){
				printf("delete failed\n");
				return -1;
			}		
			else{
				printf("delte success\n");
				break;
			}	
		}

		printf("share number : %d\n",*num);
		sleep(1);

	}



return 0;
}
