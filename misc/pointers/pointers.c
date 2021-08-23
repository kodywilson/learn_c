#include <stdio.h>

int j, k;
int a[] = { 1, 23, 17, 4, -5, 100 };
int *ptr;

int main(void)
{
  j = 1;
  k = 2;
  ptr = &k;
  printf("\n");
  printf("j has the value %d and is stored at %p\n", j, (void *) &j);
  printf("k has the value %d and is stored at %p\n", k, (void *) &k);
  printf("ptr has the value %p and is stored at %p\n", ptr, (void *) &ptr);
  printf("The value of the integer pointed to by ptr is %d\n", *ptr);

  ptr = a;
  for ( int i = 0; i < 6; i++)
  {
    printf("a[%d] = %d   ", i, a[i]);
    printf("ptr + %d = %d\n", i, *ptr++);
  }

  return 0;
}

