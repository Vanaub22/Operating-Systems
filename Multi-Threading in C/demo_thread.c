// AIM: To create a Thread and execute
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
#include<sys/types.h>
void* th_func(void*);
void main() {
    pthread_t th;
    pthread_create(&th,NULL,th_func,NULL);
    pthread_join(th,NULL); // ensures that the thread joins the main thread before further execution
    printf("\nThread Execution Ends Here...\n");
    int i;
    printf("\nMain Thread Execution Starts...\n");
    for(i=20;i<25;i++) { 
        printf("%d ",i);
        sleep(1);
    }
    printf("\n");
    printf("\nMain Thread Ends\n");
} // end of main
void* th_func(void* args) {
    int i;
    printf("\nControl is inside the thread now...\n");
    for(i=0;i<5;i++) {
        printf("%d ",i);
        sleep(1);
    }
    printf("\n");
} // end of fucntion
