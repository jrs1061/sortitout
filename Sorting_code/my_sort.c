#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF 128 /* can change the buffer size as well */
#define TOT 10 /* change to accomodate other sizes, change ONCE here */

int main() {

   int num, *num_array, count=0;
   char line_buff[BUF], *p;
   FILE *file = fopen("LIST", "r");

   while(NULL!=fgets(line_buff, sizeof(line_buff), file)){
     count++;
     num = atoi(line_buff);
     printf("%d\n",num);
   }

   printf("\ncount = %d\n", count);
   fclose(file);

   return 0;
}
