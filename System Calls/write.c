// Learning about the Write System Call
#include<unistd.h>
#include<stdio.h>
void main(){
    int n=write(1,"Hello",5); // file descriptor 1 for stdout, 0 for stdin and 2 for stderr
    printf("\nThe value returned by the write system call is %d\n",n); // returns how much it has written
} // end of main