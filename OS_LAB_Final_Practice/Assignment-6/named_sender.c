// To perform IPC using named pipes (Sender Process)
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<string.h>
#include<sys/stat.h>
#define MYFIFO "/tmp/pipefile"
void main() {
	unlink(MYFIFO);
	mkfifo(MYFIFO,0666);
	char str1[20],str2[20];
	printf("Enter the first string: ");
	scanf("%[^\n]s",str1);
	printf("Enter the second string: ");
	scanf(" %[^\n]s",str2);
	int fd=open(MYFIFO,O_RDWR);
	write(fd,str1,strlen(str1)+1);
	usleep(100);
	write(fd,str2,strlen(str2)+1);
	usleep(100);
	char output[20];
	read(fd,output,20);
	printf("The results of evaluation are as follows: %s\n",output);
	close(fd);
}
