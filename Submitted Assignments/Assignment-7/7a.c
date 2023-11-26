#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<signal.h>
#include<sys/wait.h>

void custom_handler(int signum)
{
        printf("\nInterrupted.\n");
        printf("Signal number is : %d \n",signum);
        exit(0);
}

void main()
{
	signal(SIGINT,custom_handler);
	while(1)
	{
		printf("This process will run till it's interrupted.\n");
		sleep(1);
	}
}
