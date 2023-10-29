// AIM: To use Named pipes using mkfifo fn.
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>
#include<fcntl.h>
void main() {
    int res=mkfifo("./'Named Pipes'/pipe1",0777); // Permissions must be mentioned
    printf("Named Pipe Created.\n");
} // end of main
