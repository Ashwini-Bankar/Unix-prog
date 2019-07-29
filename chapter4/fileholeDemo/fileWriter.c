#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
//#define MAX 100
int main(void)
{
	char arr[100];
	int fd=open("holedemo.txt",O_CREAT | O_RDWR);
	if(fd<0)
	{
		printf("unable to open a file!!");
		exit(0);
	}
	printf("Enter the data which you want to write in a file\n");
	scanf("%[^\n]s",arr);
	int l=strlen(arr);	
	lseek(fd,10,SEEK_CUR);
	write(fd,arr,l);
	close(fd);
	return 0;
}


