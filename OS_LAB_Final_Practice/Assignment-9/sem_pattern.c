// To generate a pattern using thread synchronization
#include<stdio.h>
#include<stdlib.h>
#include<semaphore.h>
#include<unistd.h>
#include<pthread.h>
sem_t mutex;
void* print_ab(void* args);
void* print_ba(void* args);
void main() {
	int i;
	pthread_t th1,th2;
	sem_init(&mutex,0,1);
	for(i=0;i<3;i++) {
		pthread_create(&th1,NULL,print_ba,NULL);
		pthread_create(&th2,NULL,print_ab,NULL);
		pthread_join(th1,NULL);
		pthread_join(th2,NULL);
	}
	printf("\n");
	sem_destroy(&mutex);
}
void* print_ab(void* args) {
	sem_wait(&mutex);
	printf("ab");
	sem_post(&mutex);
	pthread_exit(NULL);
}
void* print_ba(void* args) {
	sem_wait(&mutex);
	printf("ba");
	sem_post(&mutex);
	pthread_exit(NULL);
}
