// To perform IPC using unnamed pipes
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<string.h>
void main() {
	int pfd[2];
	pipe(pfd);
	char mssg[20];
	pid_t id=fork();
	if(id<0) {
		printf("The child process could not be created.\n");
		exit(0);
	}
	else if(id==0) {
		printf("This is the child process running with PID: %d and PPID: %d\n",getpid(),getppid());
		printf("Enter the message to be passed: ");
		scanf("%[^\n]s",mssg);
		write(pfd[1],mssg,strlen(mssg)+1);
	}
	else {
		printf("This is the parent process running with PID: %d and PPID: %d\n",getpid(),getppid());
		wait(NULL);
		int len=read(pfd[0],mssg,20);
		printf("The message received from the child process is as follows:\n");
		usleep(100);
		write(1,mssg,len);
		printf("\n");
	}
}
