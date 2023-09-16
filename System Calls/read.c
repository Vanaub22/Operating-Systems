// Learning about the read system call
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
void main(){
    // reading from stdin
    char buf[30];
    int n=read(0,buf,10); // returns the no. of characters successfully read
    // writing to stdout
    write(1,buf,n);
}//end of main
