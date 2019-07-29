#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

//void count_beg(int fdr,int fdw,struct holepoint *s1);

struct holepoint
{
	int beg;
	int end;
};
void count_beg(int fdr,int fdw,struct holepoint *s1);
