// Simulating the Dining Philsophers problem using mutliple threads and semaphores
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<semaphore.h>
#include<sys/types.h>
#include<pthread.h>
#define CNT 5
sem_t chopsticks[CNT];
void* philosopher_func(void*);
void main() {
	int i,n[CNT];
	pthread_t philosophers[CNT];
	for(i=0;i<CNT;i++) sem_init(&chopsticks[i],0,1);
	for(i=0;i<CNT;i++) {
		n[i]=i;
		pthread_create(&philosophers[i],NULL,philosopher_func,(void*)&n[i]);
	}
	for(i=0;i<CNT;i++) pthread_join(philosophers[i],NULL);
}
void* philosopher_func(void* args) {
	int ph_no=*(int*)args;
	printf("The philosopher %d wants to eat and needs chopsticks %d and %d\n",ph_no,ph_no,(ph_no+1)%CNT);
	printf("Philosoper %d tries to pick up Left chopstick %d...\n",ph_no,ph_no);
	sem_wait(&chopsticks[ph_no]);
	printf("Philosopher %d has successfuly picked up Left Chopstick %d\n",ph_no,ph_no);
	printf("Philosoper %d tries to pick up Right chopstick %d...\n",ph_no,ph_no+1);
	sem_wait(&chopsticks[(ph_no+1)%CNT]);
	printf("Philosopher %d has successfuly picked up Right Chopstick %d\n",ph_no,ph_no+1);
	printf("Philosopher %d starts eating\n",ph_no);
	sleep(4);
	printf("Philosoper %d has finished eating\n",ph_no);
	sem_post(&chopsticks[(ph_no+1)%CNT]);
	printf("Philosoper %d has put down his Right Chopstick %d\n",ph_no,(ph_no+1)%CNT);
	sem_post(&chopsticks[ph_no]);
	printf("Philosoper %d has put down his Left Chopstick %d\n",ph_no,ph_no);
}
