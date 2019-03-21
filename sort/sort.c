#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sort_algorithm.h"
#include "random.h"

int main(void)
{
    /* declare of variable to use in the switch */
    int randomOptions;
    int sortOptions;
    /* the grade is used to define how random the array is sorted */
    int grade;
    int length;
    int *array;
    printf("insert size\n");
    scanf("%d", &length);
    /* alloc dynamically the array */
    array = (int *)malloc(length * sizeof(int));
    printf("select the option:\n");
    printf("1. random array                 3.reversed array\n");
    printf("2. random nearly sorted array   4.unique array\n");
    scanf("%d", &randomOptions);

    /*based on the option, initialize an array*/
    switch (randomOptions)
    {
    case 1:
        randomSorted(array, length, 100);
        break;
    case 2:
        printf("insert the grade of the algorithm\n");
        scanf("%d", &grade);
        randomNearlySorted(array, length, 100, grade);
        break;
    case 3:
        randomReversed(array, length, 100);
        break;
    case 4:
        printf("insert the grade of the algorithm\n");
        scanf("%d", &grade);
        randomUnique(array, length, 100, grade);
        break;
    default:
        randomSorted(array, length, 100);
        break;
    }

    printf("sort available :\n");
    printf("1. bubble sort      3.heap sort\n");
    printf("2. select sort      4.merge sort\n");
    scanf("%d", &sortOptions);
    
    printf("do you wanna print the values?\n1.Yes\t2.No");
    int printer=1;
    scanf("%d",&printer);
    //int array[]={38,41,30,79,76,98,46,69};

    /* based on the option chose, sort the array with an algorithm */
    switch (sortOptions)
    {
    case 1:
        bubbleSort(array, length);
        break;
    case 2:
        selectSort(array, length);
        break;
    case 3:
        heapSort(array, length);
        break;
    case 4:
        print(array,length);
        mergeSort(array,length);
        break;
    default:
        mergeSort(array,length);
        break;
    }
    printf("\narrayy sorted is\n");
    print(array, length);
    /* free the array */
    free(array);
    return 0;
}
