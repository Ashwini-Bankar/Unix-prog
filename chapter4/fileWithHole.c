#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main(void)
{
	int fd=open("filehole.txt",O_CREAT | O_RDWR |O_APPEND);
	char buff[]="Welcome to hole file	";
	char buff1[]="Now creating a hole in file\n";

	if(fd<0)
	{
		printf("Error while opening a file\n");
	}
	else
	{
		lseek(fd,10,SEEK_SET);
		write(fd,buff,sizeof(buff));
		lseek(fd,30,SEEK_CUR);
		write(fd,buff1,sizeof(buff1));
	}
	close(fd);
	return 0;
}
