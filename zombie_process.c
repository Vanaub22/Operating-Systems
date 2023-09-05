// AIM: To create a Zombie process and verify the output of your program with the 'ps' command
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
void main(){
    int pid=fork();
    if(pid==0){
        printf("\nChild Process has been created.");
        printf("\nChild Process Has Started with PID: %d and PPID: %d\n",getpid(),getppid());
        sleep(5);
        printf("\nChild Process killed.\n");

    } // end of if block
    else{
        printf("\nThis is the parent process.\n");
        printf("\nParent Process Has Started with PID: %d and PPID: %d\n",getpid(),getppid());
        printf("\nParent Process will be sleeping now while Child Process gets killed.\n");
        sleep(10);
        wait(NULL);
        printf("\nChild is no longer a Zombie Process\n");
        sleep(5);
        printf("\nParent Process killed...\n");
    } // end of else block
}//end of main