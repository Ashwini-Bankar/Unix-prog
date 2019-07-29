#include"fileheader.h"
//**************** ONLY DATA********************

struct holepoint No_hole(int fdr, int fdw)
{
	struct holepoint s;
	int n,c=0;
	char buf;
	int i=0;

	while(n=read(fdr,&buf,1)>0)
	{
		if(buf=='\0')
		{
			c++;
			break;
		}
		else
		{
			write(fdr,&buf,1);
		}
	}
	if(c>0)
		printf("file contain hole");
	else
	{
		printf("File contain only data\n");
		s.beg[i]=0;
		s.end[i]=0;
	
	}
	s.count=i;
	return s;
}

//************************ONLY HOLE*************************
struct holepoint only_hole(int fdr,int fdw)
{
	struct holepoint s;
	char buf;
	int n,c=0,p,i=0;
	
	while(n=read(fdr,&buf,1)>0)
	{
		if(buf=='\0')
		{
			c++;
		}
		else
		{
			break;
		}
	}
	p=lseek(fdr,0,SEEK_END);
	if(c==p-1)
	{
		printf("File contain only holes\n");
		s.beg[i]=1;
		s.end[i]=c;
		i++;

	}
	else
	{
		printf("Invalid file input because file contain data\n");
	}
	s.count=i;

	return s;

}

//***************************ONE HOLE *******************************
struct holepoint One_hole(int fdr, int fdw)
{
	struct holepoint s;
	char buf;
        int i=0,c,n,fd,p;
	int x=lseek(fdr,0,SEEK_CUR);
	while(n=read(fdr,&buf,1)>0)
	{
		while(buf!='\0')
		{
			write(fdw,&buf,1);
			read(fdr,&buf,1);
                        
                }
                if(buf=='\0')
                { 

                        p=lseek(fdr,0,SEEK_CUR);
			if(p==1)
				printf("Hole present at the begining of the file\n");
			s.beg[i]=p;
			while(buf=='\0')
			{
				read(fdr,&buf,1);
                                p++;
                        }
                        s.end[i]=p;
			i++;
                        //break;
                }
	}
		c=lseek(fd,0,SEEK_END);
		
		if(p==c-1)
			printf("Hole present at the end of a file\n");
		else
			printf("hole preasent in between data\n");
   
	s.count=i;
	return s;

}
	
//**************************************TWO HOLES************************************


struct holepoint Two_holes(int fdr,int fdw)
{
	char buf;
        int c=0,p,n,i=0;
	struct holepoint s;

        read(fdr,&buf,1);

        if(buf=='\0')
        {
                printf("Hole present at begining of the file\n");
                c=lseek(fdr,0,SEEK_CUR);
                s.beg[i]=c;
		while(buf=='\0')
                {
                        read(fdr,&buf,1);
                        c++;
		}
		s.end[i]=c;
		i++;
                

                while(n=read(fdr,&buf,1)>0)
                {
                        if(buf=='\0')
                        {
                                c=lseek(fdr,0,SEEK_CUR);
				s.beg[i]=c;
                                while(buf=='\0')
                                {
                                        read(fdr,&buf,1);
                                        c++;
                                }
				s.end[i]=c;
				i++;
                                p=lseek(fdr,0,SEEK_END);
				
				
				/*if(p==c)
                                {
                                        printf("second hole present at the end of the file\n");
                                        break;
                                }
                                else
                                {
                                        printf("Second Hole present in between the data of file\n");
                                }*/
                        }
  		}
	}
        else
        {
                while(n=read(fdr,&buf,1)>0)
                {
                        if(buf=='\0')
                        {
                                c=lseek(fdr,0,SEEK_CUR);
				s.beg[i]=c;
                                //printf("Hole starts from %d ",c);
                                while(buf=='\0')
                                {
                                        c++;
                                        read(fdr,&buf,1);
                                }
				s.end[i]=c;
				i++;
                                //printf(" and ends at %d\n ",c);
                        }
			else
			{
				write(fdw,&buf,1);
			}
                }
                p=lseek(fdr,0,SEEK_END);
                /*if(c==p)
                {
                        printf("second hole present at the end of file\n");
                }
                else
                {
                        printf("second hole present between the data of file\n");
                }*/
        }
	s.count=i;
        close(fdr);
	close(fdw);
	return s;
}



//*************************************MORE THAN TWO HOLES*************************************


struct holepoint more_holes(int fdr,int fdw)
{
	int f=0,c,n,i=0;
        char buf;
	struct holepoint s;

        if(fdr<0)
        {
                printf("Unable to open a file\n");
                exit(0);
        }

        while(n=read(fdr,&buf,1)>0)
        {
                if(buf=='\0')
                {
                        f++;
                        c=lseek(fdr,0,SEEK_CUR);
                        s.beg[i]=c;
			//printf("Hole starts at %d ",c);
                        while(buf=='\0')
                        {
                                read(fdr,&buf,1);
                                c++;
                        }
			s.end[i]=c;
			i++;
                        //printf(" and ends at %d\n",c);
                }
		else
		{
			write(fdw,&buf,1);
		}
        }
                             
	printf("File contain %d holes\n",f);

        //close(fdr);
	//close(fdw);
	s.count=i;
        return s;
}



