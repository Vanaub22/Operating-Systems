// AIM: To create a Zombie Process and verify using ps -f f
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
void main() {
	pid_t q=fork();
    if(q<0) printf("ERROR. Child Process could not be created.\n");
    else if(q==0) {
		printf("\nThis is the Child Process with PID: %d and PPID: %d\n",getpid(),getppid());
        printf("\nChild Process Killed. The Child is now a Zombie Process...\n");
	} // end of else-if block
	else {
		printf("\nThis is the Parent Process with PID: %d and PPID: %d\n",getpid(),getppid());
		sleep(10);
        printf("\nParent Process Terminated.\n");
	} // end of if-else
}