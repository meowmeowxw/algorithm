#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LINE_LENGTH 120

int main(int argc, char *argv[])
{
	char *buf,*separator = ",",line[LINE_LENGTH];
	int n, *arr;
	printf("Reading file %s\n",argv[1]);

	FILE *fin ;
	fin = fopen(argv[1],"r");
	if (fin == NULL)
		goto end;
	n=0;

	while (fgets(line,LINE_LENGTH,fin)!=NULL)
		n++;
	arr = (int *) calloc (n,sizeof(int));
	rewind (fin);
	n = 0;
	while (fgets(line,LINE_LENGTH,fin)!=NULL)
	{
		buf = strtok (line, separator);
		arr[n] = atoi(strtok(NULL,separator));
		printf("%s->%d\n",buf,arr[n]);
		++n;
	}
	fclose(fin);
	free(arr);

end:printf("<ENTER> to exit...");
	getchar();
	return 0;
}
