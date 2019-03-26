#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LINE_LENGTH 120
#define PRINT_OUTPUT 1
void mergeSort(int *array,int p,int r);
void merge (int *array,int p,int q,int r);
int main(int argc, char *argv[])
{
	char line[LINE_LENGTH];
	int i, n, *arr;

	/* --- Readin dataset --- */
	printf("Lettura del file %s\n", argv[1]);

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
	printf("merge sort \n");
	mergeSort(arr,0,n-1);
	end = clock();
	printf("Execution time : %f\n",(double)(end-start)/CLOCKS_PER_SEC);

	/*	--- Print sorted elements --- */

	if(PRINT_OUTPUT)
	{
		printf("Ordered : \n");
		for(i=0;i<n;++i)
			printf("%d -> %d\n",(i+1),arr[i]);
	}
	free(arr);
end:
	printf("<ENTER> to exit...");
	//	getchar();
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
		{
			barray[k]=array[i];
			++i;
		}
		else
		{
			barray[k]=array[j];
			++j;
		}
		++k;
	}
	while (i<=q)
	{
		barray[k]=array[i];
		++i;
		++k;
	}
	while (j<=r)
	{
		barray[k]=array[j];
		++j;
		++k;
	}
	for (k=p;k<=r;++k)
	{
		array[k]=barray[k-p];
	}
	free(barray);
}
