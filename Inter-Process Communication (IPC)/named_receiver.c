// AIM: To use Named pipes using mkfifo fn.
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>
#include<fcntl.h>
void main() {
    int res,n;
    res=open("pipe1",O_WRONLY);
    write(res,"Message",7);
    printf("Sender Process having PID %d has sent the data\n",getpid());
} // end of main
