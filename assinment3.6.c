#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main(void)
{
	char buff[200];
	int fd=open("a.txt",O_RDWR | O_APPEND);
	int p=lseek(fd,10,SEEK_CUR);
	printf("p=%d\n",p);
	read(fd,buff,sizeof(buff));
	printf("buff=%s\n",buff);
	lseek(fd,0,SEEK_SET);
	
	char new_buff[]="new data entered here";
	write(fd,new_buff,sizeof(new_buff));
	printf("Now file contain:");
	lseek(fd,0,SEEK_SET);
	read(fd,buff,sizeof(buff));
	printf("%s\n",buff);
	close(fd);
	return 0;
}

/*
 * if we open a file read-write with append flag, we can read anywhere from the file using lseek.
 * but using lseek we are unable to overrite existing data of file because we use append flag and by default append flag set file offset as end of file. we can change the offset using lseek and read data from file but we can not overrite a data.
 */

