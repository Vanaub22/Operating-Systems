// AIM: To create a child process and print the PID & PPID from both the parent and child processes
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
void main(){
    int pid=fork();
    sleep(10);
    if(pid==0) printf("\nThis is from the child process. PID: %d PPID: %d\n",getpid(),getppid());
    else printf("\nThis is from the parent process. PID: %d PPID: %d\n",getpid(),getppid());
} // end of main
