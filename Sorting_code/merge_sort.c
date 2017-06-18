/*
 * C Program to a Perform Merge Sort using Recursion
 */
 
#include <stdio.h>
#include <stdlib.h>

#define BUF 12
 
void mergeSort(int [], int, int, int);
void partition(int [],int, int);
void get_size();

int size;
 
int main()
{
    int i;
 
    printf("Enter total number of elements:");
    scanf("%d", &size);

    int list[size];
    printf("Enter the elements:\n");
    for(i = 0; i < size; i++)
    {
         scanf("%d", &list[i]);
    }
    partition(list, 0, size - 1);
    printf("After merge sort:\n");
    for(i = 0;i < size; i++)
    {
         printf("%d   ",list[i]);
    }
 
   return 0;
}

void get_size()
{
   int count=0;
   char line_buff[BUF];
   FILE *file = fopen("LIST", "r");

   while(NULL!=fgets(line_buff, sizeof(line_buff), file)){
     count++;
   }
   size=count;
}
 
void partition(int list[],int low,int high)
{
    int mid;
 
    if(low < high)
    {
        mid = (low + high) / 2;
        partition(list, low, mid);
        partition(list, mid + 1, high);
        mergeSort(list, low, mid, high);
    }
}
 
void mergeSort(int list[],int low,int mid,int high)
{
    int i, mi, k, lo, temp[high+1];
 
    lo = low;
    i = low;
    mi = mid + 1;
    while ((lo <= mid) && (mi <= high))
    {
        if (list[lo] <= list[mi])
        {
            temp[i] = list[lo];
            lo++;
        }
        else
        {
            temp[i] = list[mi];
            mi++;
        }
        i++;
    }
    if (lo > mid)
    {
        for (k = mi; k <= high; k++)
        {
            temp[i] = list[k];
            i++;
        }
    }
    else
    {
        for (k = lo; k <= mid; k++)
        {
             temp[i] = list[k];
             i++;
        }
    }
 
    for (k = low; k <= high; k++)
    {
        list[k] = temp[k];
    }
}
