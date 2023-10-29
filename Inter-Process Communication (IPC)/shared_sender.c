// AIM: To perform IPC using Shared memory
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/shm.h>
#include<string.h>
void main() {
    void* shared_memory;
    char buff[20];
    int shmid;
    shmid=shmget((key_t)1234,1024,0666|IPC_CREAT);
    printf("Key of shared memory is: %d\n",shmid);
    shared_memory=shmat(shmid,NULL,0); // Attaching the shared memory to the currently running process
    printf("Process attached at %p\n",shared_memory);
    printf("\nEnter the data to be written in the shared memory: ");
    // read(0,buff,20);
    scanf("%[^\n]s",buff);
    strcpy(shared_memory,buff);
    printf("\nData written: %s\n",(char*)shared_memory);
} // end of main