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
  printf("The number is %d\n", numby());
  printf("Now, the number is %d\n", numby() * 3);

  return 0;
}

