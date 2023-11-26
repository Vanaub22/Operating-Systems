// AIM: To use semaphores for thread synchronization
#include<stdio.h>
#include<fcntl.h>
#include<semaphore.h>
#include<pthread.h>
#include<unistd.h>
#include<sys/types.h>
void* inc();
void* dec();
sem_t s;
int shared=1; // shared modifiable resource
void main() {
    sem_init(&s,0,1);
    pthread_t th1,th2;
    pthread_create(&th1,NULL,inc,NULL);
    pthread_create(&th2,NULL,dec,NULL);
    pthread_join(th1,NULL);
    pthread_join(th2,NULL);
    printf("\nThe Final value of the Shared Resource after Increment and Decrement operations from two threads is: %d\n",shared);
} // end of main
void* inc() {
    int x;
    sem_wait(&s); // Wait - Critical Section begins here
    x=shared; // Thread accesses the shared resource
    printf("The Thread %ld reads the Shared Resource value as %d",pthread_self(),x);
    x++;
    printf("\nThe locally updated value is: %d",x);
    sleep(1); // Allows Pre-emption
    shared=x;
    printf("\nThe value of the Shared variable updated by thread %ld is %d.",pthread_self(),shared);
    sem_post(&s); // Signal - Critical Section ends here
} // end of fn.
void* dec() {
    int x;
    sem_wait(&s); // Wait - Critical Section begins here
    x=shared; // Thread accesses the shared resource
    printf("\nThe Thread %ld reads the Shared Resource value as %d",pthread_self(),x);
    x--;
    printf("\nThe locally updated value is: %d",x);
    sleep(1); // Allows Pre-emption
    shared=x;
    printf("\nThe value of the Shared variable updated by thread %ld is %d.",pthread_self(),shared);
    sem_post(&s); // Signal - Critical Section ends here
} // end of fn.
