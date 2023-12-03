// Using Shared Memory for IPC.
// Will be sending a string to the receiver. Receiver will evaluate if it is a Palindrome and return 1 or 0 to sender.
// This is the Sender program
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<sys/shm.h>
#include<sys/ipc.h>
#include<stdbool.h>
#include<string.h>
void main() {
	char str[20];
	int choice,shmid;
	void* shared_memory;
	printf("OPTIONS:\n1. Send input to receiver process.\n2. Receive output from Receiver Process.\nEnter your choice: ");
	scanf("%d",&choice);
	switch(choice) {
		case 1:
			shmid=shmget((key_t)1234,1024,0666|IPC_CREAT);
			shared_memory=shmat(shmid,NULL,0);
			printf("Enter a string: ");
			scanf(" %[^\n]s",str);
			strcpy(shared_memory,str);
			printf("The string that is being sent to the reciever process is: %s\n",(char*)shared_memory);
			break;
		case 2:
			shmid=shmget((key_t)1234,1024,0666);
			shared_memory=shmat(shmid,NULL,0);
			printf("The result of evaluation returned from the Reciver Process is: %s\n",(char*)shared_memory);
			break;
		default:
			printf("INVALID CHOICE.\n");
	}
}
