/*
 * C Program to a Perform Merge Sort using Recursion
 */
 
#include <stdio.h>
#include <stdlib.h>

#define BUF 12
 
void mergeSort(int [], int, int, int);
void partition(int [],int, int);
int get_size();

int size;
 
int main()
{
   int i, value;
   FILE *file;
 
   get_size();

   /*printf("Enter total number of elements:");
   *scanf("%d", &size);
   *
   *int list[size];
   *printf("Enter the elements:\n");
   *for(i = 0; i < size; i++)
   *{
   *     scanf("%d", &list[i]);
   *}
   */
   int list[size];

   if ((file = fopen ("LIST", "r")) == NULL)
      exit(1);

   printf("Size is %d\n", size);
   for(i = 0; i < size; i++)
    {
      fscanf(file, "%d", &value);
      //printf("%d\n", value);
      list[i] = value;
    }

//   while (!feof (file) && fscanf (file, "%d", &list[i}) && i++ < 100 )
 //   integers[i] = value;

   fclose(file);

   printf("Before merge sort:\n");
   for(i = 0;i < size; i++)
    {
       printf("%d   ",list[i]);
    }
   partition(list, 0, size - 1);
   printf("\nAfter merge sort:\n");
   for(i = 0;i < size; i++)
    {
       printf("%d   ",list[i]);
    }
 
   return 0;
}

/*
 * Get the size of the file being opened
 */
int get_size()
{
   int count=0;
   char line_buff[BUF];
   FILE *file;

   if ((file = fopen ("LIST", "r")) == NULL)
    exit (1);

   while (!feof (file) && fgets(line_buff, sizeof(line_buff), file))
     count++;

   printf("Count =%d\n", count);

   size=count;
   fclose (file);
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
