// To create a zombie process and verify using ps -f f
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<stdlib.h>
void main() {
	pid_t id=fork();
	if(id<0) {
		printf("The child process could not be created.\n");
		exit(0);
	}
	else if(id==0) {
		printf("This is the child process with PID: %d and PPID: %d\n",getpid(),getppid());
		sleep(5);
		printf("The child process is now killed.\nThe child process is now a Zombie Process.\n");
	}
	else {
		printf("This is the parent process with PID: %d and PPID: %d\n",getpid(),getppid());
		sleep(10);
		wait(NULL);
		printf("The child process is no longer a zombie process\n");
		sleep(5);
		printf("The parent process is killed.\n");
	}
}
