#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include"fileheader.h"
void writefile(void)
{
	int fd=open("a.txt",O_CREAT | O_RDWR);
	char buff[]="welcime to unix";
	if(fd<0)
		printf("Unable to open a file");
	else
	{
		printf("Open successfully");
		write(fd,buff,sizeof(buff));
	}
	close(fd);
	
}
