#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#define LINE_LENGTH 120
#define PRINT_OUTPUT 1

///ESERCIZIO 3

void buildHeap();
void printHeap();
void heapify(int);

int *heap;
int heapSize;

int main (int argc, char* argv[])
{
    char line[LINE_LENGTH];
    int i;

    printf("Lettura del file %s\n",argv[1]);
    FILE* fin = fopen(argv[1],"r");
    if( fin == NULL ) goto end;

    heapSize = 0;
    while( fgets(line, LINE_LENGTH, fin) != NULL ) heapSize++;

    heap = (int*) calloc(heapSize, sizeof(int));
	
	int height = ((int)log2(heapSize))+1;
	printf("%d\n",height);
    rewind(fin);
    i = 0;
    while( fgets(line,LINE_LENGTH,fin) != NULL )
    {
        heap[i] = atoi(line);
        if(PRINT_OUTPUT) printf("%d -> %d\n",(i+1),heap[i]);
        i++;
    }

    fclose(fin);
    printf("\n");

    clock_t start, end;
    start = clock();

    ////////// COSTRUZIIONE //////////
    printf("Costruzione dello heap...\n");
    buildHeap();

    end = clock();

    if(PRINT_OUTPUT)
    {
        printf("Struttura a heap:\n");
        printHeap(height);
    }

    free(heap);

    printf("Tempo di esecuzione: %f sec\n",(double)(end-start)/CLOCKS_PER_SEC);

end:
    printf("<ENTER> to exit...");
    getchar();
    return 0;
}

void printHeap(int height)
{
	int line=1;
	int count=0;
	int max=16;
	int step = ((int)pow(2,height-line)) -1; 
	
	for(int j=0;j<step;++j)
	{
		printf("\t");
	}
	for(int i=0;i<heapSize;++i)
	{
		if(((int)log2(i+1)) > line-1)
		{
			++line;
			step = ((int)pow(2,height-line))-1;
		    printf("\n\n");	
			for(int j=0;j<step;++j)
				printf("\t");
		}
		printf("%d",heap[i]);
		for(int j=0;j<(2*step)+2;++j)
			printf("\t");
	}
	puts("");

}

void buildHeap()
{
    int i;
    for(i = ((int)heapSize/2)-1;i>=0;i--)
    {
        heapify(i);
    }
}

void heapify(int i)
{
    int l=2*i+1;
    int r=2*i+2;
    int largest;

    if(l<heapSize && heap[l]>heap[i])
    {
        largest = l;
    }
    else
    {
        largest = i;
    }

    if(r<heapSize && heap[r]>heap[largest])
    {
        largest = r;
    }

    if(largest != i)
    {
        int temp = heap[i];
        heap[i] = heap[largest];
        heap[largest] = temp;
        heapify(largest);
    }
}
