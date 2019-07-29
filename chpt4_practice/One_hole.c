#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#define MAX 500
#include<stdlib.h>
int main(int argc, char *argv[])
{
	if(argc<2)
	{
		exit(0);
	}
	char buf, data[MAX];
	int i=0,c,n,fd,p;
	//lseek(fd,10,SEEK_CUR);
	fd=open(argv[1],O_RDONLY);
	printf("%s\n",argv[1]);
	read(fd,&buf,1);
	printf("buf=%c\n",buf);
	c=1;

	if(buf=='\0')
	{
		while(n=read(fd,&buf,1)>0)
		{
			if(buf=='\0')
			{
				c++;
				printf("buf=%c   %d\n",buf,c);
			}
			else
			{
				break;
				
				printf("buf=%c   %d\n",buf,c);
			}
		}
		printf("hole present at begining of the file....\n starts from 1 and ends at %d\n",c);
	}
	else 
	{
		while(n=read(fd,&buf,1)>0)
		{
			while(buf!='\0')
			{
				read(fd,&buf,1);
				p=lseek(fd,0,SEEK_CUR);
				
			}
			if(buf=='\0')
			{
				printf("Hole starts from %d ",p);
				while(buf=='\0')
				{
					read(fd,&buf,1);
					p++;
				}
				printf(" and ends at %d\n ",p);
				break;
			}
		}
	}


			







	close(fd);
	return 0;
}
