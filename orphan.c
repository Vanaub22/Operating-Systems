// AIM: To create an orphaned child process by killing the parent process first
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
void main(){
    int pid=fork();
    if(pid==0){
        printf("\nChild Process has been created.");
        printf("\nChild Process Has Started with PID: %d and PPID: %d\n",getpid(),getppid());
        printf("\nChild will be sleeping now while Parent gets killed...\n");
        sleep(10);
        printf("\nThe child process is now an Orphan process.\n");
    } // end of if block
    else{
        printf("\nThis is the parent process.\n");
        printf("\nParent Process Has Started with PID: %d and PPID: %d\n",getpid(),getppid());
        sleep(5);
        printf("\nParent Process killed...\n");
    } // end of else block
} // end of main