/* AIM: To demonstrate the use of signals.
The parent process will stop executing when it receives an alarm from the child process. */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<signal.h>
#include<time.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdbool.h>
bool alarmRaise=false;
int sig_id;
void custom_handler(int);
void main() {
    signal(SIGALRM,custom_handler);
    pid_t pid=fork();
    if(pid==-1) {
        printf("\nCould not create child process.");
        exit(0);
    }
    else if(pid==0) {
        printf("\nThis is the child process running with PID: %d and PPID: %d.",getpid(),getppid());
        sleep(5);
        kill(getppid(),SIGALRM);
        printf("\nThe child process has sent an alarm to the parent process to initiate termination.");
    }
    else {
        printf("\nThe parent process is running with PID: %d and PPID: %d",getpid(),getppid());
        while(!alarmRaise) {
            printf("\nThe parent process is waiting...");
            sleep(1);
        }
        printf("\nThe parent received an alarm from child with PID: %d",pid);
        printf("\nThe signal number caught is %d",sig_id);   
    }
} // end of main
void custom_handler(int signum) {
    printf("\nThis is an alarm messagen from the custom handler.");
    sig_id=signum;
    alarmRaise=true;
}