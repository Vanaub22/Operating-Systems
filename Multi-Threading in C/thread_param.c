// AIM: Passing a array of user-input size to a thread and returning sum of its elements
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
#include<sys/types.h>
typedef struct {
    int* arr;
    int size;
} passArr; // end of structure definition
void* th_func(void*);
void main() {
    int n,i;
    void* sum;
    passArr* array=(passArr*)malloc(sizeof(passArr));
    pthread_t th;
    printf("Enter the number of elements in the array: ");
    scanf("%d",&array->size);
    array->arr=(int*)malloc(n*sizeof(int));
    printf("Enter the elements in the array separated by spaces: ");
    for(i=0;i<array->size;i++) scanf("%d",&array->arr[i]);
    pthread_create(&th,NULL,th_func,(void*)array);
    pthread_join(th,&sum);
    printf("\nThe sum of the array elements is: %d\n",*(int*)sum);
} // end of main
void* th_func(void* args) {
    passArr* array=(passArr*)args;
    int i,*sum=(int*)malloc(sizeof(int));
    *sum=0;
    printf("The elements in the array are as follows: ");
    for(i=0;i<array->size;i++) printf("%d ",array->arr[i]);
    for(int i=0;i<array->size;i++) *sum+=array->arr[i];
    pthread_exit((void*)sum);
} // end of function