// AIM: Implement IPC between a parent and a child process where parent will print a message received from the child.
// The child will take the message as user input. Use un-nnamed pipe for IPC.
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<string.h>
#define MAX_SIZE 50
void main(){
    int* pfd=(int*)malloc(2*sizeof(int)),n,len=0;
    pipe(pfd);
    int pid=fork();
    char buffer[MAX_SIZE],input[MAX_SIZE];
    if(pid==0){
		printf("I am child. I am here to take to user input.\n");
		printf("Enter input: ");
		scanf("%[^\n]s",input);
		len=strlen(input);
		printf("Passing message to parent\n");
		write(pfd[1],input,len+1);
	} // end of if block
	else
	{
		wait(NULL);
		printf("I am parent. I received data from child. Data received is as follows:\n");
		n=read(pfd[0],buffer,MAX_SIZE);
		write(1,buffer,n);
		printf("\n");
	} // end of if-else
    free(pfd);
} // end of main