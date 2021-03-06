#include <stdio.h>
#include <stdlib.h>

int main() {
  int *numlist;
  int numlist_len;
  int i;

  puts("Enter a number from 1 - 9:");
  scanf("%d", &numlist_len);

  // allocate memory
  numlist = (int *) malloc(numlist_len * sizeof(int));

  if (numlist == NULL) {
    puts("something went wrong during malloc");
    return 1;
  }

  for ( i = 0; i < numlist_len; i++) {
    numlist[i] = i + 100;
    printf("numlist[%d] is now %d\n", i, numlist[i]);
  }

  // release memory
  free(numlist);

  return 0;
}
