#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main()
{
	int fd=open("dup.txt",O_CREAT | O_WRONLY);
	
	char buff[]="working on dup()";
	printf("fd=%d\n",fd);
	if(fd<0)
		printf("Error\n");
	else
	{
		write(fd,buff,sizeof(buff));
		printf("current offset=%ld\n",lseek(fd,0,SEEK_CUR));
	}
	int copy_fd=dup(fd);
	printf("copy_fd=%d\n",copy_fd);
	write(copy_fd,"\ndup() implementation\n",22);
	printf("dup() offset=%ld\n",lseek(copy_fd,0,SEEK_CUR));
	return 0;
}

