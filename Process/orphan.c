// AIM: To create an Orphan process and verify using ps command
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
void main() {
	pid_t q=fork();
	if(q<0) printf("ERROR. Child Process could not be created.\n");
	else if(q==0) {
		printf("\nThis is the Child Process with PID: %d and PPID: %d\n",getpid(),getppid());
		printf("\nThe Child Process will be sleeping now as the Parent Process is killed...\n");
		sleep(10);
	} // end of else-if block
	else {
		printf("\nThis is the Parent Process with PID: %d and PPID: %d\n",getpid(),getppid());
		sleep(5);
		printf("\nParent Process killed...\n");
	} // end of if-else
} // end of main
