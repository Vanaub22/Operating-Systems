// AIM: To perform Inter-Process Communication using Pipes
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<string.h>
void main() {
	int fd[2]; // fd[0] is the Reading End and fd[1] is the Writing End
	pipe(fd);
	int q=fork();
	if(q==0) {
		sleep(4);
		char buf[30];
		printf("The child received data from the parent...\nThe data received is: ");
		fflush(stdout);
		int n=read(fd[0],buf,5); // read from the Reading End
		write(1,buf,5); // write to stdout (1)
	} // end of if block
	else {
		char mssg[30];
		printf("\nEnter the message that you want to pass: ");
		scanf("%[^\n]s",mssg);
		write(fd[1],mssg,strlen(mssg)); // write to the Writing End
		wait(NULL);
	} // end of if-else
} // end of main
