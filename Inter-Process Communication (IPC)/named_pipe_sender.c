// AIM: To use named pipes for IPC
// This process will basically accept a string from the user and send it to another process wherein the string will be reversed
// The resultant string will be sent back from that process and displayed here.
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<sys/wait.h>
#include<sys/stat.h>
#define MYFIFO "./pipefile" // We must assign a name and path
void main() {
	unlink(MYFIFO);
	mkfifo(MYFIFO,0666);
	char input[20];
	printf("PROCESS-1: Enter the string to be sent to PROCESS-2: ");
	scanf("%[^\n]s",input);
	int fd=open(MYFIFO,O_RDWR); // Giving both read and write permissions
	write(fd,input,strlen(input)+1);
	sleep(5); // Allows for Context-Switching, otherwise it might read immediately
	char output[20];
	read(fd,output,sizeof(output)); // Reading the returned value from the other process
	printf("PROCESS-1: The received contents from PROCESS-2 are as follows: %s\n",output);
} // end of main
