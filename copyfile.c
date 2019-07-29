#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include"header.h"

void copy()
{
	int fd,fd1;
	char buff[50];
	fd=open("a.txt",O_RDONLY);
	fd1=open("b.txt",O_RDWR);
	if(fd<0 && fd1<0)
		printf("Unbale to copy file");
	else
	{
		read(fd,buff,sizeof(buff));
		write(fd1,buff,sizeof(buff));
	}
	close(fd);
	close(fd1);
}
