#include <stdio.h>

int main(void)
{
  int yes = 1, no = 0;
  printf("AND (no&&no): %d\n", no && no);
  printf("AND (yes&&no): %d\n", yes && no);
  printf("AND (yes&&yes): %d\n", yes && yes);
  printf("OR (no||no): %d\n", no || no);
  printf("OR (yes||no): %d\n", yes || no);
  printf("OR (yes||yes): %d\n", yes || yes);
  printf("NOT (yes !yes): %d %d\n", yes, !yes);
  printf("NOT (no !no): %d %d\n", no, !no);
  // Ternary operator
  ( 9 % 2 == 0 ) ? puts("Even Number") : puts("Odd Number");
  return 0;
}

