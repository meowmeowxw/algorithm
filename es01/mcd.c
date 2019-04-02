#include <stdio.h>

int main(int argc,char *argv[])
{
	int a,b,tmp;
	if(argc!=3)
	{
		fprintf(stderr,"usage:es1 a b\n");
		return 1;
	}
	a=atoi(argv[1]);
	b=atoi(argv[2]);
	while(b!=0)
	{
		tmp=b;
		b=a%b;
		a=tmp;
	}
	printf("MCD : %d\n",abs(a));
	return 0;
}
