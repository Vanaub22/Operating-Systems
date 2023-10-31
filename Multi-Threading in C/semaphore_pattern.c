// AIM: To make two threads synchronize and print a pattern.
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<pthread.h>
#include<semaphore.h>
#include<fcntl.h>
sem_t mutex; // Binary semaphore for imposing locks
void* print_ab(void* args) {
    sem_wait(&mutex);
    printf("ab");
    sem_post(&mutex);
    pthread_exit(NULL);
}
void* print_ba(void* args) {
    sem_post(&mutex);
    printf("ba");
    sem_wait(&mutex);
    pthread_exit(NULL);
}
void main() {
    pthread_t th1,th2;
    sem_init(&mutex,0,1); // Unlocked initially
    for(int i=0;i<3;i++){
    pthread_create(&th1,NULL,print_ba,NULL);
    pthread_create(&th2,NULL,print_ab,NULL);
    pthread_join(th1,NULL);
    pthread_join(th2,NULL);}
    sem_destroy(&mutex);
}
