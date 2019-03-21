#include "random.h"
void randomSorted(int *array, int length, int range)
{
    srand((unsigned int)time(0));
    for (int i = 0; i < length; i++)
    {
        array[i] = rand() % range;
    }
}
void randomNearlySorted(int *array, int length, int range, int grade)
{
    srand((unsigned int)time(0));
    int step = range / length;
    int count = 1;
    int tmp;
    array[0] = step;
    for (int i = 1; i < length; i++)
    {
        if (count == 0)
        {
            array[i] = array[i - 1] + step * 2;
            count++;
        }
        else
        {
            array[i] = array[i - 1] + step;
            count++;
            if (count == grade)
            {
                tmp = array[i - 1];
                array[i - 1] = array[i];
                array[i] = tmp;
                count = 0;
            }
        }
    }
}
void randomReversed(int *array, int length, int range)
{
    int step = range / length; 
    for (int i = 0; i <length; i++)
    {
        array[i] = range - step;
        range-=step;
    }
}
void randomUnique(int *array, int length, int range, int grade)
{
    srand((unsigned int)time(0));
    int *unique;
    unique=(int*)malloc(sizeof(int)*grade);

    for (int i = 0; i < grade; i++)
    {
        unique[i] = rand() % (range + 1);
    }
    for (int i = 0; i < length; i++)
    {
        array[i] = unique[rand() % grade];
    }
    free(unique);
}

