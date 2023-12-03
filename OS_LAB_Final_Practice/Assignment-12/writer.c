// To simulate Reader-Writer Problem using multiple processes and Process Semaphores
// This is the Writer Program
#include<stdio.h>
#include<stdlib.h>
#include<sys/shm.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>
#include "rw_buffer.h"
#define MAX_ITERATIONS 5
int value=1;
void main() {
	int shmid=shmget((key_t)1234,sizeof(buffer),0666|IPC_CREAT);
	buffer* Buf=(buffer*)shmat(shmid,NULL,0);
	buff_init(Buf);
	int i=MAX_ITERATIONS;
	while(i--) {
		printf("The Writer is waiting to write\n");
		sem_wait(&Buf->write);
		value++;
		buff_write(Buf,value);
		printf("The value %d has been written by the Writer\n",value);
		sem_post(&Buf->write);
		sleep(2);
	}
	shmdt(Buf);
	shmctl(shmid,IPC_RMID,0);
}
