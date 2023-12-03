// To simulate the Producer-Consumer Problem using Multi-Threading and Semaphores
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>
#include<semaphore.h>
#include<sys/types.h>
#include<stdbool.h>
#define BUFF_SIZE 5
int shared_val=1,in=0,out=0,buff[BUFF_SIZE];
sem_t empty,full,mutex;
void* producer(void*);
void* consumer(void*);
void main() {
	pthread_t producer_th,consumer_th;
	sem_init(&empty,0,BUFF_SIZE);
	sem_init(&full,0,0);
	sem_init(&mutex,0,1);
	pthread_create(&producer_th,NULL,producer,NULL);
	pthread_create(&consumer_th,NULL,consumer,NULL);
	pthread_join(producer_th,NULL);
	pthread_join(consumer_th,NULL);
	sem_destroy(&empty);
	sem_destroy(&full);
	sem_destroy(&mutex);
}
void* producer(void* args) {
	while(true) {
		sem_wait(&empty);
		sem_wait(&mutex);
		int item=shared_val;
		buff[in]=item;
		printf("Producer inserted item %d into the buffer\n",item);
		in=(in+1)%BUFF_SIZE;
		sleep(1);
		sem_post(&mutex);
		shared_val++;
		sleep(1);
		sem_post(&full);
	}
	pthread_exit(NULL);
}
void* consumer(void* args) {
	while(true) {
		sem_wait(&full);
		sem_wait(&mutex);
		int item=buff[out];
		printf("Consumer removed item %d from the buffer\n",item);
		out=(out+1)%BUFF_SIZE;
		sleep(1);
		sem_post(&mutex);
		sleep(1);
		sem_post(&empty);
	}
	pthread_exit(NULL);
}
