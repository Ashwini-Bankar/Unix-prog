#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
int main(void)
{
	int fd=open("file.txt",O_CREAT | O_RDWR);
	char buff[100];
	printf("Enter string which you want to write in a file\n");
	scanf("%[^\n]s",buff);
	int l=strlen(buff);
	if(fd<0)
	{
		printf("Error!!!!\n");
	}
	else
	{
		lseek(fd,10,SEEK_CUR);
		write(fd,buff,l);

		lseek(fd,10,SEEK_CUR);
		write(fd,buff,l);
	}
	close(fd);
	return 0;
}
	
