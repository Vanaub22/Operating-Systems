// To perform IPC using shared memory
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<string.h>
#include<sys/shm.h>
#include<sys/ipc.h>
void main() {
    void* shared_memory;
    char buff[100];
    int shmid;
    shmid=shmget((key_t)1234,1024,0666);
    shared_memory=shmat(shmid,NULL,0);
    printf("Data Received: %s\n",(char*)shared_memory);
} // end of main