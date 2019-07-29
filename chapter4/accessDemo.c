#include<stdio.h>
#include<unistd.h>
#include <fcntl.h>
int main(int argc, char *argv[])
{
	if (argc != 2)
		printf("usage: a.out <pathname>");
	if (access(argv[1], R_OK) < 0)
		printf("access error for %s\n", argv[1]);
	else
		printf("read access OK\n");
	if (open(argv[1], O_RDONLY) < 0)
		printf("open error for %s\n", argv[1]);
	else
		printf("open for reading OK\n");
return 0;
}
