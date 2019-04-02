#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LINE_LENGTH 120
#define PRINT_OUTPUT 0
int partition(int *array,int p,int r);
void quicksort(int *array,int p,int r);
int main(int argc, char *argv[])
{
	char line[LINE_LENGTH];
	int i, n, *arr;

	/* --- Readin dataset --- */
	printf("Reading file %s\n", argv[1]);

	FILE* fin = fopen(argv[1],"r");
	if(fin == NULL) goto end;

	/* --- Count line number --- */
	n = 0;
	while (fgets(line, LINE_LENGTH, fin)!= NULL) n++;

	arr = (int*) calloc(n, sizeof(int));

/* --- Start reading file --- */
	rewind(fin);
	n = 0;
	while (fgets(line,LINE_LENGTH,fin)!= NULL)
	{
		arr[n]=atoi(line);
		if(PRINT_OUTPUT)
			printf("%d->%d\n",(n+1),arr[n]);
		n++;
	}

	fclose(fin);
	printf("\n");
	/*	--- End reading file ---	*/

	clock_t start,end;

	start = clock();
	printf("quick sort \n");
	quicksort(arr,0,n-1);
	end = clock();
	printf("Execution time : %f\n",(double)(end-start)/CLOCKS_PER_SEC);

	/*	--- Print sorted elements --- */

	if(PRINT_OUTPUT)
	{
		printf("Sorted : \n");
		for(i=0;i<n;++i)
			printf("%d -> %d\n",(i+1),arr[i]);
	}
	free(arr);
end:
	printf("<ENTER> to exit...");
	//	getchar();
	return 0;
}
void quicksort(int *array,int p,int r)
{
	int q;
	if(p<r)
	{
		q=partition(array,p,r);
		quicksort(array,p,q-1);
		quicksort(array,q+1,r);
	}
}
int partition(int *array,int p,int r)
{
	int i=p-1;
	int pivot=array[r];
	int tmp;
	for(int j=p;j<r;++j)
	{
		if(array[j]<=pivot)
		{
			++i;
			tmp=array[i];
			array[i]=array[j];
			array[j]=tmp;
		}
	}
	tmp=array[++i];
	array[i]=array[r];
	array[r]=tmp;
	return i;
}
