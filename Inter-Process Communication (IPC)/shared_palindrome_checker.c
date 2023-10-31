// AIM: To perform IPC by passing a string and checking if it is a palindrome in the receiver process
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdbool.h>
bool isPalindrome(char*,int);
void main() {
    char *str;
    void* shared_memory;
    int shmid=shmget((key_t)1234,1024,0666);
    shared_memory=shmat(shmid,NULL,0);
    str=(char*)shared_memory;
    printf("The string received is: %s\n",str);
    if(isPalindrome(str,strlen(str))) printf("%s is a Palindrome.\n",str);
    else printf("%s is not a Palindrome.\n",str);
} // end of main
bool isPalindrome(char* str, int n) {
    int i;
    for(i=0;i<n/2;i++) if(str[i]!=str[n-i-1]) return false;
    return true;
} // end of fn.