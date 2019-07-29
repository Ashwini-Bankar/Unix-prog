#include"func_header.h"
#include<stdlib.h>
void count_beg(int fdr,int fdw,struct holepoint *s1)
{
	
	char buf;
	int n,c=0,p;
	if(fdr<0 || fdw<0)
	{
		printf("unable to proceed!!!!!");
		exit(0);
	}
	else
	{
		while(n=read(fdr,&buf,1)>0)
		{
			if(buf!='\0')
			{
				c++;
			}
			

			if(c>0)
			{
				break;
			}
			else
			{
				p=lseek(fdr,0,SEEK_CUR);
				
				s1->beg=p;
				while(n=read(fdr,&buf,1)>0)
				{
					if(buf=='\0')
						p++;
					else
						break;
				}
				s1->end=p;

			}
		}
	}

	lseek(fdr,p,SEEK_SET);
	while(n=read(fdr,&buf,sizeof(buf))>0)
	{
		write(fdw,&buf,sizeof(buf));
	}
	close(fdr);
	close(fdw);
}




void count_in_between(int fdr,int fdw,struct holepoint *s1)
{



