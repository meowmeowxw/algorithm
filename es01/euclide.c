#include <stdio.h>
int mcd(int x,int y);
int main()
{
	int a,b,c,d;
	a=15;
	b=10;
	c=3;
	d=6;
	printf("mcd(%d,%d) : %d\n",a,b,mcd(a,b));
	printf("mcd(%d,%d) : %d\n",a,c,mcd(a,c));
	printf("mcd(%d,%d) : %d\n",a,d,mcd(a,d));
	printf("mcd(%d,%d) : %d\n",d,c,mcd(d,c));
	printf("mcd(%d,%d) : %d\n",d,b,mcd(d,b));
	return 0;
}
int mcd(int x,int y)
{
	if(y==0)
		return x;
	else 
		mcd(y,x%y);
}
