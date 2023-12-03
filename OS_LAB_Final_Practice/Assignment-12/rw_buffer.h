// Buffer data structure file to used exclusively for the simulation of the Reader-Writer Problem using multiple processes
#include<stdio.h>
#include<sys/shm.h>
#include<sys/ipc.h>
#include<semaphore.h>

typedef struct {
	sem_t mutex,write;
	unsigned reader_cnt;
	int data;
} buffer;

void buff_init(buffer* Buf) {
	sem_init(&Buf->mutex,1,1);
	sem_init(&Buf->write,1,1);
	Buf->reader_cnt=0;
}

int buff_read(buffer* Buf) {
	return Buf->data;
}

void buff_write(buffer* Buf, int val) {
	Buf->data=val;
}

void buff_destroy(buffer* Buf) {
	sem_destroy(&Buf->mutex);
	sem_destroy(&Buf->write);
}
