// AIM: To implement Dining Philopher Problem for 5 Philosophers using Multi-Threading and Semaphores
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<pthread.h>
#include<semaphore.h>
#define CNT 5
void* philosopher_func(void*);
sem_t chopsticks[CNT];
void main() {
    int n[CNT],i;
    pthread_t philosophers[CNT];
    // Initialization
    for(i=0;i<CNT;i++) sem_init(&chopsticks[i],0,1);
    for(i=0;i<CNT;i++) {
        n[i]=i;
        pthread_create(&philosophers[i],NULL,philosopher_func,(void*)&n[i]);
    }
    for(i=0;i<CNT;i++) pthread_join(philosophers[i],NULL);
    printf("\n");
} // end of main
void* philosopher_func(void* ph) {
    int ph_no=*(int*)ph;
    printf("\nPhilosopher %d wants to eat, therfore he would need chopsticks %d and %d.",ph_no,ph_no,(ph_no+1)%CNT);
    printf("\nPhilospher %d tries to pick up Left chopstick, i.e chopstick %d...",ph_no,ph_no);
    sem_wait(&chopsticks[ph_no]);
    printf("\nPhilospher %d successfully picks up Left chopstick, i.e chopstick %d",ph_no,ph_no);
    printf("\nPhilospher %d tries to pick up Right chopstick, i.e chopstick %d...",ph_no,(ph_no+1)%CNT);
    sem_wait(&chopsticks[(ph_no+1)%CNT]);
    printf("\nPhilospher %d successfully picks up Right chopstick, i.e chopstick %d",ph_no,(ph_no+1)%CNT);
    printf("\nPhilosopher %d is eating...",ph_no);
    sleep(2); // Time for eating
    printf("\nPhilosopher %d has finished eating.",ph_no);
    sem_post(&chopsticks[(ph_no+1)%CNT]);
    printf("\nPhilospher %d puts down the Right chopstick, i.e chopstick %d",ph_no,(ph_no+1)%CNT);
    sem_post(&chopsticks[ph_no]);
    printf("\nPhilospher %d puts down the Left chopstick, i.e chopstick %d",ph_no,ph_no);
} // end of fn.