/* AIM: The parent process will send a signal to the child process every 5 seconds.
The child process will handle the signal and check if the input no. is a leap year. */
#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<sys/types.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdbool.h>
void custom_handler(int year) {
    if
}