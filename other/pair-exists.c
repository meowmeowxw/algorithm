 /*	Describe a Θ(nlgn)-time algorithm that, given a set S of n integers and
  *	another integer x, determines whether or not there exists two elements of
  *	S whose sum is exactly x.	*/

/*	we can use the merge-sort which takes (nlogn) time to sort, and then a 
 *	binary search to check if a pair exists	(nlogn) */

#include <stdio.h>
#include <stdlib.h>
void mergeSort(int *array,int p,int r);
void merge (int *array,int p,int q,int r);
int binsearch(int *v,int start,int end,int value);
int exist(int *array,int start,int end,int value);

int main(int argc,char *argv[])
{
	int v[]={3,4,5,7,2,4,9,2,3,1,24};
	int e=exist(v,0,11,atoi(argv[1]));
	printf("e is %d\n",e);
	return 0;
}
void mergeSort(int *array,int p,int r)
{	
	int q=(p+r)/2;
	if(p<r)
	{
		mergeSort(array,p,q);
		mergeSort(array,q+1,r);
		merge(array,p,q,r);
	}
}
void merge(int *array,int p,int q,int r)
{
	int i=p;
	int j=q+1;
	int k=0;
	int *barray;

	barray=(int *)malloc(sizeof(int)*(r-p+1));
	while ((i<=q) && (j<=r))
	{
		if(array[i]<array[j])
			barray[k++]=array[i++];
		else 
			barray[k++]=array[j++];
	}
	while (i<=q)
		barray[k++]=array[i++];	

	while (j<=r)
		barray[k++]=array[j++];

	for (k=p;k<=r;++k)
		array[k]=barray[k-p];
	free(barray);
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
int exist(int *array,int start,int end,int value)
{
	mergeSort(array,start,end);
	int i=0;
	for(i=0;i<end;++i)
	{
		if(binsearch(array,start,end,value-array[i])!=-1)
				return 1;
	}
	return 0;
}
