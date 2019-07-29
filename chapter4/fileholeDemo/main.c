
#include"func_header.h"
#include<stdlib.h>
int main(int argc , char *argv[])
{
	if(argc!=3)
	{
		printf("ERROR!!!\n");
		exit(0);
	}

	int fdr,fdw;
	struct holepoint s1;
	fdr=open(argv[1],O_RDONLY);
	fdw=open(argv[2],O_WRONLY);
	count_beg(fdr,fdw,&s1);
	printf("Hole starts from  %d  and ends at %d\n",s1.beg,s1.end);
	return 0;
}
