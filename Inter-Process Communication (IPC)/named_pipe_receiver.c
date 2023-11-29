// AIM: To use named pipes for IPC
// This process will basically accept a string from the user and send it to another process wherein the string will be reversed
// The resultant string will be sent back from that process and displayed here.
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<sys/wait.h>
#define MYFIFO "/tmp/pipefile" // We must assign a name and path
void main() {
	char str[20];
	int fd=open(MYFIFO,O_RDWR);
	read(fd,str,sizeof(str)); // Reading the value from the sender
	printf("\nPROCESS-2: The received contents from PROCESS-1 are as follows: %s\n",str);
	int n=strlen(str);
	for(int i=0;i<n/2;i++) {
		char tmp=str[i];
		str[i]=str[n-i-1];
		str[n-i-1]=tmp;
	}
	printf("PROCESS-2: Reversal Completed locally. The reversed string is %s.\n",str);
	write(fd,str,strlen(str)+1);
} // end of main
