#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LINE_LENGTH 120
#define PRINT_OUTPUT 0 

void insertion(int *array,int n);
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
	printf("insertion sort \n");
	insertion(arr,n);
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
void insertion(int *array,int n)
{
	int i=0,j=0;
	int key=0;
	for(j=1;j<n;++j)
	{
		key=array[j];
		i=j-1;
		while (i>=0 && array[i] > key)
		{
			array[i+1]=array[i];
			--i;
		}
		array[i+1]=key;
	}	
}
