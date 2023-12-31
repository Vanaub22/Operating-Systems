#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<signal.h>
#include<fcntl.h>

int alarm_raised=0;
int sig=0;

void raised_alarm_handler(int signum)
{
	alarm_raised=1;
	sig=signum;
}

void main()
{
	signal(SIGALRM,raised_alarm_handler);
	int pid=fork();
	if(pid==-1)
	{
		perror("fork");
		exit(1);
	}
	if(pid==0)
	{
		printf("Child process running with PID : %d and PPID : %d...\n",getpid(),getppid());
		sleep(5);
		kill(getppid(),SIGALRM);
		printf("Child process sent alarm to parent\n");
	}
	else
	{
		printf("Parent process with PID : %d is waiting..\n",getpid());
		while(alarm_raised==0)
		{
			printf("Hello this is parent process..\n");
			sleep(1);
		}
		printf("Parent received alarm from child with PID : %d\n",pid);
		printf("The signal number is : %d\n",sig);
	}
}
