// To create a child process and verify
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<fcntl.h>
void main() {
	pid_t id=fork();
	sleep(5); // This is the window to run ps -f f and check
	if(id<0) {
		printf("The child process could not be created.\n");
		exit(0);
	}
	else if(id==0) printf("This is the child process with PID: %d and PPID: %d\n",getpid(),getppid());
	else printf("This is the parent process with PID: %d and PPID: %d\n",getpid(),getppid());
} // end of main
