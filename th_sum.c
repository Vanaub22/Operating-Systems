// Write a ‘C’ program in LINUX to create a thread that determines the summation of N natural numbers using POSIX thread library.
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<pthread.h>
void* find_sum(void*);

void main(){
	pthread_t thread;
	int n,*sum;
	printf("Enter the value of n:");
	scanf("%d",&n);
	pthread_create(&thread,NULL,find_sum,&n);
	pthread_join(thread,(void **)&sum);
	printf("The sum = %d\n",*sum);
} // end of main

void* find_sum(void* arg){
	int i,*sum,n=*((int*)arg);
	sum=(int*)malloc(sizeof(int));
	for(*sum=0,i=1;i<=n;i++) *sum+=i;
	printf("sum=%d\n",*sum);
	pthread_exit((void *)sum);
} // end of func.

