#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include"dup_header.h"
int main(void)
{
	int fd,n;
	char buff[15];
	fd=open("new.txt",O_CREAT | O_RDWR);
	printf("fd=%d\n",fd);
	if(fd<0)
		printf("unable to open a file\n");

	if(dup2_copy(fd,2)<0)
		printf("dup2 : can't dup2 file descriptor found  %d \n",fd);

	if(write(fd,"hello",5)!=5)
		printf("cant write to fd\n");

	if(write(2,"dup2()",6)!=6)
		printf("can't write to new_fd 2\n");

	lseek(fd,0,SEEK_SET);
	if((n=read(fd,buff,15))<0)
		printf("unable to read from fd\n");
	printf("n=%d\n",n);

	//buff[n]='\0';
	printf("buf=%s\n",buff);

	if(close(fd)<0)
		printf("can't close fd %d\n",fd);

	if(close(2)<0)
		printf("can't close new_fd 2\n");

	return 0;
}


