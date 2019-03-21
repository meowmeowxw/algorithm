#include "sort_algorithm.h"
void heapSort(int *array, int length)
{
    for (int i = length / 2 - 1; i >= 0; i--)
        heapifyIterative(array, length, i);
    print(array, length);
    for (int i = length - 1; i >= 0; i--)
    {
        /*  once that the highest value is at the top of the structure,
            I can swap it to the end of the array and reuse the heapifyIterative
            to heapify the array and put the highest number at the end. */
        swap(&array[0], &array[i]);
        heapifyIterative(array, i, 0);
        print(array, length);
    }
}
void heapifyRecursive(int *arr, int length, int i)
{
    int max = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < length && arr[left] > arr[max])
    {
        max = left;
    }
    if (right < length && arr[right] > arr[max])
    {
        max = right;
    }
    if (max != i)
    {
        swap(&arr[i], &arr[max]);
        heapifyRecursive(arr, length, max);
    }
}
void heapifyIterative(int *arr, int length, int i)
{
    /* set initial conditions */
    bool condition = true;
    bool swapped = false;
    int max = i;

    while (condition)
    {
        i = max;
        swapped = false;
        /* the left of the heap is calculated with this formula */
        int left = 2 * max + 1;
        /* the right with this one */
        int right = 2 * max + 2;
        /*  left is not at the top and the array in that position is greater 
            than the arr[max] (the highest heap), then I swap */
        if (left < length && arr[left] > arr[max])
        {
            max = left;
            swapped = true;
        }
        if (right < length && arr[right] > arr[max])
        {
            max = right;
            swapped = true;
        }
        if (swapped)
        {
            swap(&arr[i], &arr[max]);
            //we use & to pass the memory address because the pointer *a need to point to some address
            // in swap
        }
        else
        {
            condition = false;
            break;
        }
        //repeat the cycle until there is a swap
    }
}
void mergeSort(int *array,int length)
{
	/* the mid is the point where the array will be divided */
	int mid;int i=0;
	int *arrLeft;
	int *arrRight;
	mid=length/2;
	/* if the length==1 then return because the array cannot be divided more */
	if(length==1)
		return ;
	else
	{
		/* dynamically alloc the space for the sub array */
		arrLeft=(int*)malloc(sizeof(int)*mid);
		arrRight=(int*)malloc(sizeof(int)*(length-mid));	
		/* I fill the sub array */
        for(i=0;i<mid;i++)
            arrLeft[i]=array[i];
        print(arrLeft,mid);
        
        for(i=0;i<length;i++)
            arrRight[i]=array[i+mid];

        print(arrRight,length-mid);
		mergeSort(arrLeft,mid);
		mergeSort(arrRight,length-mid);
		/*  merge works on the *array which is called by mergeSort,
			however *array must be reinitialized every time because it must be 
			divided between arrLeft and arrRight with his last value which comes
			from `merge`. After that with i refill the sub arrays and when the mergeSort
			of arrRight end, merge restart the whole process */
		merge(array,arrLeft,arrRight,length);
	}
	/* when is all done I'll free the space of the array */
	free(arrLeft);
	free(arrRight);
}
void merge(int *array,int *arrLeft,int *arrRight,int length)
{
	/* `i` is needed for arrLeft, `j` for arrRight and `k` for array */
	int i=0,j=0,k=0;
	/* mL is for midLeft and mR for midRight */
	int mL,mR;
	mL=length/2;
    mR=length-mL;
	/* while i and k are respectively lower then their mid, then I merge the sub array */
	while(i<mL && j<mR)
	{
		/*  if the arrLeft[i] is lower then arrRight[j] then i put the value
			in array because in array[k] because it means that there cannot be
			lower value different from arrLeft[i]. the same with arrRight.
			then i increment i or j and k. this means that some values are not put
			on array.	*/
		if(arrLeft[i]<arrRight[j])
		{
			array[k]=arrLeft[i];
			i++;
		}else
		{
			array[k]=arrRight[j];
			j++;
		}
		k++;
	}
	/* in this while I finish to merge the values from arrLeft/arrRight to array */
	while(i<mL)
	{
		array[k]=arrLeft[i];
		i++;
		k++;
	}
	while(j<mR)
	{
		array[k]=arrRight[j];
		j++;
		k++;
	}
}

void bubbleSort(int *array,int length)
{
    int tmp;
    bool condition=false;
    do
    {   condition=false;
        for(int i=0;i<length-1;i++)
        {
            if(array[i]>array[i+1])
            {
                tmp=array[i];
                array[i]=array[i+1];
                array[i+1]=tmp;
                condition=true;
            }
        }
        print(array,length);
    }while(condition);
}
void selectSort(int *array,int length)
{
    int max = 0;
    int position;
    int lengthTmp=length;
    do
    {
        for (int i = 0; i < lengthTmp; i++)
        {
            if (array[i] > max)
            {
                max = array[i];
                position=i;
            }
        }
        swap(&array[lengthTmp - 1], &array[position]);
        lengthTmp--;
        max = 0;
        position=0;
        print(array,length);
    } while (lengthTmp > 1);
}
void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void print(int array[], int length)
{
    for (int i = 0; i < length; i++)
        printf("%d ", array[i]);

    printf("\n");
}
