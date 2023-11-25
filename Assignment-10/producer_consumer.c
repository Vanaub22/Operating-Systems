// AIM: To simulate the Producer-Consumer Problem using multiple threads and simple array
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<semaphore.h>
#include<pthread.h>
#include<sys/wait.h>
#define BUFFER_SIZE 5
sem_t mutex,empty,full;
int in=0,out=0;
int buffer[BUFFER_SIZE];
void* producer(void* args) {
	while(1) {
		sem_wait(&empty);
		sem_wait(&mutex);
		int item;
		printf("\nEnter the item that you wish to produce or enter -1 to terminate: ");
		scanf("%d",&item);
		if(item==-1) {
			printf("Execution Terminated...");
			exit(0);
		} // end of if block
		printf("\nProducer is Adding %d to the Buffer\n",item);
		buffer[in]=item;
		in=(in+1)%BUFFER_SIZE;
		sleep(1);
		sem_post(&mutex);
		sleep(1);
		sem_post(&full);
	} // end of while loop
	pthread_exit(NULL);
} // end of fn.

void* consumer(void* args) {
	while(1) {
		sem_wait(&full);
		sem_wait(&mutex);
		int item=buffer[out];
		printf("\nConsumer: Reading %d from the Buffer\n",item);
		out=(out+1)%BUFFER_SIZE;
		sleep(1);
		sem_post(&mutex);
		sleep(1);
		sem_post(&empty);
	} // end of while loop
	pthread_exit(NULL);
} //  end of fn.

void main() {
	sem_init(&full,0,0);
	sem_init(&empty,0,BUFFER_SIZE);
	sem_init(&mutex,0,1);
	pthread_t prod,cons;
	pthread_create(&prod,NULL,producer,NULL);
	pthread_create(&cons,NULL,consumer,NULL);
	pthread_join(prod,NULL);
	pthread_join(cons,NULL);
	sem_destroy(&full);
	sem_destroy(&empty);
	sem_destroy(&mutex);
}
