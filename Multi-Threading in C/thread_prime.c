// AIM: To take a number as input from the main thread and then pass it to another thread and check if it is prime
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdbool.h>
void* isPrime(void*);
void main() {
    int num;
    printf("Enter the number: ");
    scanf("%d",&num);
    pthread_t th;
    pthread_create(&th,NULL,isPrime,(void*)&num);
    bool* res;
    pthread_join(th,(void**)&res);
    if(*((bool*)res)) printf("The number passed by the main thread was a prime number.\n");
    else printf("The number passed by the main thread was not a prime number.\n");
} // end of main
void* isPrime(void* args) {
    int num=*((int*)args);
    bool* res=malloc(sizeof(bool));
    if(num==1) {
        *res=false;
        pthread_exit((void*)res);
    }
    int factors=0,i;
    for(i=1;i<=num;i++) if(num%i==0) factors++; 
    *res=factors==2;
    pthread_exit((void*)res);
} // end of fn.