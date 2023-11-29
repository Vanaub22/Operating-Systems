// To send a signal from parent to child every 5 seconds and then accept a year from user and check if it a leap year or not
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<stdbool.h>
bool control=true;
void custom_handler(int signum) {

	printf("A signal has been sent. Signal number: %d\n",signum);
	control=false;
}
bool isLeap(int year) {
	return year%100==0?year%400==0:year%4==0;
}
void main() {
	signal(SIGUSR1,custom_handler);
	pid_t id=fork();
	if(id<0) {
		printf("The child process could not be created\n");
		exit(0);
	}
	else if(id==0) {
		printf("This is the child process running with PID: %d and PPID: %d\n",getpid(),getppid());
		while(true) {
			printf("The child process is waiting for a signal...\n");
			pause();
			if(!control) {
				printf("Enter a year: ");
				int year;
				scanf("%d",&year);
				fflush(stdin);
				printf("\n");
				if(isLeap(year)) printf("%d is a Leap year\n",year);
				else printf("%d is not a Leap year\n",year);
				control=true;
			}
		}

	}
	else {
		printf("This is the parent process running with PID: %d and PPID: %d\n",getpid(),getppid());
		while(control) {
			printf("The parent process will be sending the signal every 5 seconds from now...\n");
			sleep(5);
			kill(id,SIGUSR1);
		}
	}
}
