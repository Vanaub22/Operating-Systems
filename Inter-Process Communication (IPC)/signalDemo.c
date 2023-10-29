/* AIM: A simple program to demonstrate the use of signals. The process keeps printing a message infinitely until it interrupted.
After that it will handle the signal and also display the signal number that it has received. */
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<signal.h>
#include<fcntl.h>
#include<stdbool.h>
void custom_handler(int);
void main() {
    signal(SIGINT,custom_handler);
    while(true) {
        printf("This is a demo message. Waiting for interrupt (Press Ctrl + C)...\n");
        sleep(1);
    } // end of while loop
} // end of main
void custom_handler(int signum) {
    printf("\nInterrupted.\nThe signal number caught is %d\n",signum);
    exit(0);
}