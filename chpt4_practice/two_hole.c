#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
	if(argc<2)
	{
		printf("ERROR!!!\n");
		exit(0);
	}

	int fd=open(argv[1],O_RDONLY);

	char buf;
	int c=0,p,n;
	
	read(fd,&buf,1);

	if(buf=='\0')
	{
		printf("Hole present at begining of the file\n");
		c=lseek(fd,0,SEEK_CUR);
		printf("Hole starts from %d ",c);
		while(buf=='\0')
		{
			read(fd,&buf,1);
			c++;
		}
		printf(" Hole ends at %d \n",c);

		//printf("Second hole present at the end of a file\n");
		
		while(n=read(fd,&buf,1)>0)
		{
			if(buf=='\0')
			{
				c=lseek(fd,0,SEEK_CUR);
				printf("Hole starts from %d ",c);
				while(buf=='\0')
				{
					read(fd,&buf,1);
					c++;
				}
				printf("and ends at %d\n ",c);
				p=lseek(fd,0,SEEK_END);
				if(p==c)
				{
					printf("second hole present at the end of the file\n");
					break;
				}
				else
				{
					printf("Second Hole present in between the data of file\n");
				}
			}
		}
	}
	else
	{
		while(n=read(fd,&buf,1)>0)
		{
			if(buf=='\0')
			{
				c=lseek(fd,0,SEEK_CUR);
				printf("Hole starts from %d ",c);
				while(buf=='\0')
				{
					c++;
					read(fd,&buf,1);
				}
				printf(" and ends at %d\n ",c);
			}
		}
		p=lseek(fd,0,SEEK_END);
		if(c==p)
		{
			printf("second hole present at the end of file\n");
		}
		else
		{
			printf("second hole present between the data of file\n");
		}
	}

	close(fd);
	return 0;
}



