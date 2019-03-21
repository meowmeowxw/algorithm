#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

/* heap sort */
void heapifyRecursive(int *arr, int length, int i);
void heapifyIterative(int *arr, int length, int i);
void heapSort(int *arr, int length);

/* merge sort */
void mergeSort(int *array,int length);
void merge(int *array,int *arrLeft,int *arrRight,int length);

/* bubble sort */
void bubbleSort(int *array,int length);

/* select sort */
void selectSort(int *array,int length);

/* utilities */
void swap(int *a, int *b);
void print(int array[], int length);
