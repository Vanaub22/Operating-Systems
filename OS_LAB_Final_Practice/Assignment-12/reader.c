// To simulate Reader-Writer Problem using multiple processes and Process Semaphores
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
	int shmid=shmget((key_t)1234,sizeof(buffer),0666|IPC_CREAT);
	buffer* Buf=(buffer*)shmat(shmid,NULL,0);
	int i=MAX_ITERATIONS;
	while(i--) {
		sem_wait(&Buf->mutex);
		Buf->reader_cnt++;
		if(Buf->reader_cnt==1) sem_wait(&Buf->write);
		sem_post(&Buf->mutex);
		int x=buff_read(Buf);
		printf("Reader reads value: %d\n",x);
		sleep(2);
		sem_wait(&Buf->mutex);
		Buf->reader_cnt--;
		if(Buf->reader_cnt==0) sem_post(&Buf->write);
		sem_post(&Buf->mutex);
		sleep(2);		
	}
	shmdt(Buf);
}
