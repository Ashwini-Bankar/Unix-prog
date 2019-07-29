#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>


int main(int argc, char *argv[])
{
	if(argc <2)
	{
		printf("ERROR!!!!\n");
	}

	int fd=open(argv[1],O_RDONLY);
	int f=0,c,n;
	char buf;

	if(fd<0)
	{
		printf("Unable to open a file\n");
		exit(0);
	}

	while(n=read(fd,&buf,1)>0)
	{
		if(buf=='\0')
		{
			f++;
			c=lseek(fd,0,SEEK_CUR);
			printf("Hole starts at %d ",c);
			while(buf=='\0')
			{
				read(fd,&buf,1);
				c++;
			}
			printf(" and ends at %d\n",c);
		}
	}
	printf("File contain % d holes\n",f);

	close(fd);
	return 0;
}

