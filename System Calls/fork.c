// AIM: To create a child process using the fork system call
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
void main() {
	pid_t q=fork();
	if(q<0) printf("Error! Child Process not created.\n");
	else if(q==0) printf("This is the Child Process.\nThe Child Process has PID: %d and PPID: %d\n",getpid(),getppid());
	else printf("This is the Parent Process.\nThe Parent Process has PID: %d and PPID: %d\n",getpid(),getppid());
} // end of main
