// To demonstrate the usage of signals
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<signal.h>
#include<stdbool.h>
void custom_handler(int signum) {
	printf("\nThe process has been interrupted. Signal number caught: %d\n",signum);
	exit(0); // Will exit the current process
}
void main() {
	signal(SIGINT,custom_handler);
	while(true) {
		printf("This process will keep running till it is interrupted manually...\n");
		sleep(1);
	}
}
