#include <stdio.h>
#if defined(_WIN32)
#include "test.h"
#elif defined linux
#include "test_linux.h"
#endif

#if __STDC__ && __STDC_NO_THREADS__ != 1
#include <threads.h>
//
#elif POSIX_THREADS == 200809L
#include <pthread.h>
//
#else
#error Neither <threads.h> nor <pthread.h> is available
#endif

int main(void) {
  int a[ARRAY_SIZE];

  for (int i = 0; i < ARRAY_SIZE; i++)
    a[i] = i * 10;

  printf("The number is %d\n", numby());
  printf("Now, the number is %d\n", numby() * 3);

  printf("Let's print some numbers, here's 0 to 990\n");
  for (int j = 0; j < ARRAY_SIZE; j++)
    printf("%d ", a[j]);
  printf("\n");

  return 0;
}

