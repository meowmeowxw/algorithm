#include <stdio.h>
#include <stdlib.h>
int main(int argc,char **argv)
{
	int a,b;
	if(argc!=3)
	{
		fprintf(stderr,"miss paramaters\n");
		return 1;
	}
	a=atoi(argv[1]);
	b=atoi(argv[2]);
	printf("first : %d\nsecond : %d\n",a,b);
	return 0;
}
