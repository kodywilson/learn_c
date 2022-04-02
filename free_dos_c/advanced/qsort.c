#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 5

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int main () {
   int n;
   //int values[] = { 88, 56, 100, 2, 25 };
   int values[ARRAY_SIZE];

  // store random numbers
  srand(13374);

  for (int i = 0; i < ARRAY_SIZE; i++) values[i] = (int) random() % 100;

   printf("Before sorting the list is: \n");
   for( n = 0 ; n < 5; n++ ) {
      printf("%d ", values[n]);
   }

   qsort(values, 5, sizeof(int), cmpfunc);

   printf("\nAfter sorting the list is: \n");
   for( n = 0 ; n < 5; n++ ) {   
      printf("%d ", values[n]);
   }
   printf("\n");
  
   return(0);
}
