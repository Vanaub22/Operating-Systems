// To simulate reader-Writer Problem using multiple processes
// This is the Reader Program
#include<stdio.h>
#include<stdlib.h>
#include<sys/shm.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>
#include "rw_buffer.h"
#define MAX_ITERATIONS 5
void main() {
	int shmid=shmget((key_t)1234,sizeof(buffer),0666_IPC_CREAT);
	
}
