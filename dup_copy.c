#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<errno.h>
#include"dup_header.h"
int dup2_copy(int old_fd , int new_fd)
{
	int fd[5]={0},i;
	if(new_fd>5 || new_fd<0)
	{
		return -1;
	}
	if(lseek(old_fd,0,SEEK_CUR)<0)
		printf("old_fd %d not exist\n",old_fd);

	if(old_fd==new_fd)
		return new_fd;
	close(new_fd);

	for(i=0;i<5;i++)
	{
		if((fd[i]=dup(old_fd))<0)
		{
			printf("dup %s \n",strerror(errno));

			while(--i>0)
			close(fd[i]);
			return -1;
		}

		if(fd[i]==new_fd)
			break;
	}

	if(i>=5)
		return -1;

	while(--i>=0)
		close(fd[i]);
	return new_fd;
}

