// To perform IPC using named pipes (Receiver Process)
#include<sys/stat.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<string.h>
#define MYFIFO "/tmp/pipefile"
#include<stdbool.h>
bool equalStrings(char* str1, int l1, char* str2, int l2) {
	if(l1!=l2) return false;
	for(int i=0;i<l1;i++) if(str1[i]!=str2[i]) return false;
	return true;
}
void main() {
	int fd=open(MYFIFO,O_RDWR);
	char str1[20],str2[20];
	int l1=read(fd,str1,20),l2=read(fd,str2,20);
	if(equalStrings(str1,l1,str2,l2)) write(fd,"SAME",5);
	else write(fd,"NOT SAME",9);
	close(fd);
}
