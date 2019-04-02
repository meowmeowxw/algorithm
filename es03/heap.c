#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LINE_LENGTH 120
#define PRINT_OUTPUT 0
#define HEAPSIZE 5 
int array[]={5,10,4,8,7};
void buildHeap();
void printHeap();
void heapify();
int main(int argc, char *argv[])
{
	clock_t start,end;
	start = clock();
	buildHeap();
	end = clock();
	printf("Execution time: %f\n",(double)(end-start)/CLOCKS_PER_SEC);
	printHeap();
	return 0;
}
void buildHeap()
{
	int i;
	for(i=((int)HEAPSIZE/2-1);i>=0;--i)
	{
		heapify(i);
	}
}
void heapify(int i)
{
	int l=2*i+1;
	int r=2*i+2;
	int largest;
	int tmp;
	if(l<HEAPSIZE && array[l]>array[i])
		largest=l;
	else
		largest=i;
	if(r<HEAPSIZE && array[r]>array[largest])
		largest=r;
	if(largest!=i)
	{
		tmp=array[i];
		array[i]=array[largest];
		array[largest]=tmp;
		heapify(largest);
	}
}
void printHeap()
{
	for(int i=0;i<HEAPSIZE;++i)
		printf("%d\n",array[i]);
}
