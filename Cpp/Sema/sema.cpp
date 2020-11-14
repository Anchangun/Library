#include <pthread.h>

#include <semaphore.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>


static sem_t sem_one;
static sem_t sem_two;
static int num;

void * read(void*data){
int loop_i;
for(loop_i=0;loop_i<10;loop_i++){
	printf("num : ");
	sem_wait(&sem_two);
	scanf("%d",&num);
	sem_post(&sem_one);
}
	return NULL;
}
void* sumData(void*data){
	int sum=0;
	int loop_i;
	for(loop_i=0;loop_i<10;loop_i++){
		sem_wait(&sem_one);
		sum=sum+num;
		sem_post(&sem_two);
	}
	printf("result : [%d]/n",sum);
	return NULL;
}
int main(){
	pthread_t t1,t2;
	sem_init(&sem_one,0,0);
	sem_init(&sem_two,0,1);

	pthread_create(&t1,NULL,read,NULL);
	pthread_create(&t2,NULL,sumData,NULL);

	pthread_join(t1,NULL);
	pthread_join(t2,NULL);

	sem_destroy(&sem_one);
	sem_destroy(&sem_two);
	return 0;
}

