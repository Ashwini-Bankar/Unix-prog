#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#define MAX 20
struct holepoint
{
	int beg[MAX];
	int end[MAX];
	int count;
};

struct holepoint No_hole(int fdr,int fdw);
struct holepoint only_hole(int fdr,int fdw);
struct holepoint One_hole(int fdr,int fdw);
struct holepoint Two_holes(int fdr,int fdw);
struct holepoint more_holes(int fdr,int fdw);
