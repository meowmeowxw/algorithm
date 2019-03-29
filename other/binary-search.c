#include <stdio.h>

int binsearch(int *v,int start,int end,int value);
int main()
{
	int v[]={-2,2,3,5,6,7,8,9,10};
	int a;int b;int c;int d;int fake;
	a=binsearch(v,0,9,-2);
	b=binsearch(v,0,9,4);
	c=binsearch(v,0,9,7);
	d=binsearch(v,0,9,8);
	fake=binsearch(v,0,9,123);

	printf("a is : %d\n",a);
	printf("b is : %d\n",b);
	printf("c is : %d\n",c);
	printf("d is : %d\n",d);
	printf("fake is : %d\n",fake);
}
int binsearch(int *v,int start,int end,int value)
{
	if(start<=end)
	{
		int mid=start+((end-start)/2);
		if(value==v[mid])
			return mid;
		if(value>v[mid])
			return binsearch(v,mid+1,end,value);
		if(value<v[mid])
			return binsearch(v,start,mid-1,value);
	}
	return -1;
}
