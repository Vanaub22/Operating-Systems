// AIM: To perform IPC by passing a string and checking if it is a palindrome in the receiver process
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<sys/shm.h>
#include<fcntl.h>
void main() {
    void* shared_memory;
    char buff[20];
    int shmid=shmget((key_t)1234,1024,0666|IPC_CREAT);
    shared_memory=shmat(shmid,NULL,0);
    printf("Enter the string to be passed: ");
    scanf("%[^\n]s",buff);
    strcpy(shared_memory,buff);
    printf("Data stored in shared memory: %s\n",(char*)shared_memory);
} // end of main