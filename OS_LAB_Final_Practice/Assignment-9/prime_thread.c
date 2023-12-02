// Main Thread will accept an integer, a sub-thread will compute if it is PRIME or NOT PRIME and return the result to Main Thread
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<fcntl.h>
#include<sys/types.h>
#include<stdbool.h>
bool isPrime(int);
void* checkPrime(void*);
void main() {
	pthread_t th;
	int num;
	printf("This is the Main Thread...\n");
	printf("Enter a number: ");
	scanf("%d",&num);
	pthread_create(&th,NULL,checkPrime,(void*)&num);
	char *res;
	pthread_join(th,(void**)&res);
	printf("Sub-Thread execution ended\nControl returned back to Main Thread\n");
	printf("%d is %s",num,res);
	printf("Main Thread execution ends\n");
}
void* checkPrime(void* args) {
	printf("Control is inside the sub-thread now...\n");
	int x=*((int*)args);
	if(isPrime(x)) return "PRIME\n";
	else return "NOT PRIME\n";
}
bool isPrime(int x) {
	if(x==0 || x==1) return false;
	int factors=1;
	for(int i=1;i<=x/2;i++) if(x%i==0) factors++;
	return factors==2;
}
