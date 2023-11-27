// To create an Orphan process and verify using ps -f f
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
void main() {
	pid_t id=fork();
	if(id<0) {
		printf("The child process could not be created.\n");
		exit(0);
	}
	else if(id==0) {
		printf("This is the child process with PID: %d and PPID %d\n",getpid(),getppid());
		printf("The child process will now sleep while the parent process gets killed...\n");
		sleep(10);
		printf("The child process will now be killed");
	}
	else {
		printf("This is the parent process with PID: %d and PPID: %d\n",getpid(),getppid());
		printf("The parent process is now running...\n");
		sleep(5);
		printf("The parent process is killed...The child process is now an orphan process\n");
	}
} // end of main
