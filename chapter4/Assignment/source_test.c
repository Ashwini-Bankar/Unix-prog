#include"fileheader.h"
#include<assert.h>

int main(int argc, char *argv[])
{
	int fdr,fdw,i,choice;

	if(argc<3)
	{
		printf("ERROR!!!!\n");
		exit(0);
	}

	fdr=open(argv[1],O_RDONLY);
	fdw=open(argv[2],O_WRONLY);

	if(fdr<0 | fdw<0)
	{
		printf("Unable to proceed\n");
		exit(0);
	}
	printf("************MENU*************\n");
	printf("1. No Hole\n");
	printf("2. Only hole\n");
	printf("3. One hole\n");
	printf("4. Two hole\n");
	printf("5. More than two hole\n");

	printf("Enter your choice\n");
	scanf("%d",&choice);

	struct holepoint s1;
	switch(choice)
	{
		case 1:
			s1=No_hole(fdr,fdw);
			assert(s1.count==0);
			printf("Hole starts from %d and ends at %d\n",s1.beg[s1.count], s1.end[s1.count]);
			break;

		case 2:
			s1=only_hole(fdr,fdw);
			assert(s1.count==1);
			for(i=0;i<s1.count;i++)
			{
				printf("Hole starts from %d and ends at %d\n",s1.beg[i],s1.end[i]);
			}
			break;

		case 3:
			s1=One_hole(fdr,fdw);
                       assert(s1.count==1);
		      // printf("%d",s1.count);
                        for(i=0;i<s1.count;i++)
                        {
                                printf("Hole starts from %d and ends at %d\n",s1.beg[i],s1.end[i]);
                        }
                        break;

		case 4:
			s1=Two_holes(fdr,fdw);
                        assert(s1.count==2);
			printf("%d\n",s1.count);
                        for(i=0;i<s1.count;i++)
                        {
                                printf("Hole starts from %d and ends at %d\n",s1.beg[i],s1.end[i]);
                        }
                        break;

		case 5:
			s1=more_holes(fdr,fdw);
                        assert(s1.count>2);
                        for(i=0;i<s1.count;i++)
                        {
                                printf("Hole starts from %d and ends at %d\n",s1.beg[i],s1.end[i]);
                        }
                        break;

		default:
			exit(0);
	}

	return 0;
}







	




