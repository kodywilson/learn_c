#include <stdio.h>
#if defined(_WIN32)
#include "test.h"
#elif defined linux
#include "test_linux.h"
#endif

int main(void) {
  printf("The number is %d\n", numby());
  printf("Now, the number is %d\n", numby() * 3);

  return 0;
}

