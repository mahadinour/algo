#include <stdio.h>
void input();
void merge(int left, int center, int right);
void merge_Sort(int left, int right);
int array[100];



void merge(int left, int center, int right)
{
    int n1 = center - left + 1;
    int n2 = right - center;
    int array1[n1];
    int array2[n2];
    int i, j, k;
    for (i = 0; i < n1; i++)
    {
        array1[i] = array[left + i];
    }
    for (j = 0; j < n2; j++)
    {
        array2[j] = array[center + j + 1];
    }
    i = 0;
    j = 0;

    for (k = left; k < right; k++)
    {
        if (array1[i] <= array2[j])
        {
            array[k] = array1[i];
            i++;
        }
        else
        {
            array[k] = array2[j];
            j++;
        }
    }
    
    while (i < n1)
    {
        array[k] = array1[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        array[k] = array2[j];
        j++;
        k++;
    }
}

void main()
{
    printf("Enter your array size=");
    int n;
    scanf("%d", &n);

    int i;
    printf("Enter your array elements =");
    for (i = 0; i < n; i++)
    {
        printf(" %d array =\n", i);
        scanf("%d", &array[i]);
    }
    printf(" your array elements =");
    for (i = 0; i < n; i++)
    {
        printf("%d  ", array[i]);
    }
    merge_Sort(0, n - 1);

    printf("After merge sort.....\n");
    for (i = 0; i < n; i++)
    {
        printf("%d    ", array[i]);
    }
}
