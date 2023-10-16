// WAP where two threads will synchronize each other to print the pattern "baabbaabbaab".
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<pthread.h>
#include<semaphore.h>
sem_t mutex;
void* print_ab(void* args){
	sem_wait(&mutex);
	printf("ab");
	sem_post(&mutex);
	pthread_exit(NULL);
} // end of func.
void* print_ba(void* args){
	sem_post(&mutex);
	printf("ba");
	sem_wait(&mutex);
	pthread_exit(NULL);
} // end of func.
void main(){
	sem_init(&mutex,0,1);
	pthread_t thread1,thread2;
	int i;
	for(i=0;i<3;i++){
		pthread_create(&thread1,NULL,print_ba,NULL);
		pthread_create(&thread2,NULL,print_ab,NULL);
		pthread_join(thread1,NULL);
		pthread_join(thread2,NULL);
	}
	sem_destroy(&mutex);
	printf("\n");
} // end of main