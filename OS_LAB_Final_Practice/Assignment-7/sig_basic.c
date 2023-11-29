// To send an alarm from child process to make the parent process stop
#include<unistd.h>
#include<signal.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<stdio.h>
#include<stdlib.h>
void custom_handler(int signum) {
	printf("The child process has sent a signal to the parent process: %d\n",signum);
}
void main() {
	signal(SIGALRM,custom_handler);
	pid_t id=fork();
	if(id<0) {
		printf("The child process could not be created\n");
		exit(0);
	}
	else if(id==0) {
		printf("This is the child process running with PID: %d and PPID: %d\n",getpid(),getppid());
		printf("The child process will now be sending an alarm to parent in 5 seconds\n");
		sleep(5);
		kill(getppid(),SIGALRM);
	}
	else {
		printf("\nThis is the parent process running with PID: %d and PPID: %d\n",getpid(),getppid());
		wait(NULL);
		//pause();
		printf("The parent process is terminated.\n");
	}
}

