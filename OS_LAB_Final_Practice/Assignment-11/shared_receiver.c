// Using Shared Memory for IPC.
// Will be sending a string to the receiver. Receiver will evaluate if it is a Palindrome and return 1 or 0 to sender.
// This is the Receiver Program
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
bool isPalindrome(char* str) {
	int i,n=strlen(str);
	for(i=0;i<n/2;i++) if(str[i]!=str[n-i-1]) return false;
	return true;
}
void main() {
	char str[20];
	int shmid=shmget((key_t)1234,1024,0666);
	void *shared_memory=shmat(shmid,NULL,0);
	strcpy(str,(char*)shared_memory);
	printf("The string that has been received from the sender process is: %s\n",str);
	if(isPalindrome(str)) strcpy((char*)shared_memory,"PALINDROME");
	else strcpy((char*)shared_memory,"NOT PALINDROME");
	printf("The string that is being sent back to the sender process is: %s\n",(char*)shared_memory);
}
