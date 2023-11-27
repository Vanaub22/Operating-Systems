// To create a child process and verify
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<fcntl.h>
void main() {
	pid_t id=fork();
	if(id<0) {
		printf("The child process could not be created.\n");
		exit(0);
	}
	else if(id==0) { // Child Process
		printf("This is the child process with PID: %d and PPID: %d\n",getpid(),getppid());
		sleep(5);
	}
	else {
		printf("This is the parent process with PID: %d and PPID: %d\n",getpid(),getppid());
		sleep(5);
	}
} // end of main
