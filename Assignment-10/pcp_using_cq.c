// AIM: To simulate the Producer-Consumer Problem using multiple threads
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<semaphore.h>
#include<pthread.h>
#include<sys/wait.h>
#include "buffer.h"
sem_t mutex,empty,full;
int shared=0;
Buffer* buf;
void* producer(void*);
void* consumer(void*);

void main() {
	pthread_t producer_th,consumer_th;
    buf=(Buffer*)malloc(sizeof(Buffer));
    buf=buff_init(buf,10); // Initializing the Circular Queue from buffer.h
	sem_init(&mutex,0,1);
	sem_init(&full,0,0);
	sem_init(&empty,0,buf->size);
	pthread_create(&producer_th,NULL,producer,NULL);
	pthread_create(&consumer_th,NULL,consumer,NULL);
	pthread_join(producer_th,NULL);
	pthread_join(consumer_th,NULL);
    buff_destroy(buf);
	sem_destroy(&mutex);
	sem_destroy(&full);
	sem_destroy(&empty);
} // end of main

void* producer(void* args) {
	while(1) {
		sem_wait(&empty);
		sem_wait(&mutex);
		int item=shared;
        buff_insert(buf,item);
		printf("\nProducer added %d to the Buffer\n",item);
        shared+=1;
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
		int item=buff_delete(buf);
		printf("\nConsumer: Reading %d from the Buffer\n",item);
		sleep(1);
		sem_post(&mutex);
		sleep(1);
		sem_post(&empty);
	} // end of while loop
	pthread_exit(NULL);
} //  end of fn.
