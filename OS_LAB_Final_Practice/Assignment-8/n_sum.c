// To determine the sum of N user-input natural numbers using threads
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<pthread.h>
#include<sys/wait.h>

void* findSum(void*);

typedef struct {
	int *arr,n;
} array;

void main() {
	int i;
	printf("Enter the value of N: ");
	array *inp=(array*)malloc(sizeof(array));
	scanf("%d",&inp->n);
	printf("Enter the N = %d Natural numbers separated by spaces: ",inp->n);
	inp->arr=(int*)malloc(inp->n*sizeof(int));
	for(i=0;i<inp->n;i++) scanf("%d",&inp->arr[i]);
	printf("The user-input natural numbers are as follows: ");
	for(i=0;i<inp->n;i++) printf("%d ",inp->arr[i]);
	pthread_t th;
	printf("\nThread execution starts here...\n");
	pthread_create(&th,NULL,findSum,inp);
	int *sum;
	pthread_join(th,(void**)&sum);
	printf("Thread execution ends here...\n");
	printf("The required sum = %d\n",*sum);
	free(inp->arr);
	free(inp);
	free(sum);
}

void* findSum(void* args) {
	array* inp=(array*)args;
	int *sum=(int*)malloc(sizeof(int)),i;
	*sum=0;
	printf("The control is now inside the thread...\n");
	printf("The passed array is: ");
	for(i=0;i<inp->n;i++) {
		printf("%d ",inp->arr[i]);
		*sum+=inp->arr[i];
	}
	printf("\nInside Thread, calculated sum = %d\n",*sum);
	pthread_exit((void*)sum);
}
