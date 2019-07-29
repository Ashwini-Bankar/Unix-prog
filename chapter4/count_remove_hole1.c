#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main(void)
{
	int fd=open("filehole.txt",O_RDONLY);
	int fd1=open("file.txt",O_CREAT | O_RDWR | O_APPEND);
	char buf;
	int p,n;

	if(fd<0)
	{
		printf("unable to open a file\n");
	}
	else
	{
		while(n=read(fd,&buf,1)>0)
		{
			if(buf!='\0')
				write(fd1,&buf,1);
			else
			{
				p=lseek(fd,0,SEEK_CUR);
				printf("Hole starts from %d	",p);
				while(n=read(fd,&buf,1)>0)
				{
					if(buf=='\0')
						p++;
					else
						break;
				}
				printf("hole ends at %d\n",p);
				lseek(fd,p,SEEK_SET);
			}
		}
	}
	close(fd1);
	close(fd);
	return 0;
}
