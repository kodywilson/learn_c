#include <stdio.h>
#include <time.h>

int main() {
  time_t rawtime = time(NULL);

  if (rawtime == -1) {
    puts("The time() function failed");
    return 1;
  }

  struct tm *ptm = localtime(&rawtime);

  if (ptm == NULL) {
    puts("The localtime() function failed");
    return 1;
  }

  printf("The time is: %02d:%02d:%02d\n", ptm->tm_hour,
  ptm->tm_min, ptm->tm_sec);

  return 0;
}
