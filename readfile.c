#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include"header.h"
void readFile()
{
	int fd=open("a.txt",O_RDONLY);
	char buff[50];
	if(fd<0)
		printf("Unable to open a file\n");
	else
	{
		printf("open sucessfully\n");
		read(fd,buff,sizeof(buff));
		printf("Now file contain %s\n",buff);
	}
	close(fd);
}
