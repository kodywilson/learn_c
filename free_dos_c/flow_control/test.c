#include <stdio.h>

int main() {
  int i = 1;
  int a = 2;

  if (i == 1) puts("i is equal to one");
  if ((i == 1) && (a == 2)) puts("i is equal to 1 and a is equal to 2");
  if (i == a) puts("i is equal to a");
  else if (a == 2) puts("a = 2"); 
  else puts("i is not equal to a");

  switch (i) {
    case 1:
      puts("i is equal to one (case)"); break;
    case 2:
      puts("i is equal to two (case)"); break;
    case 3:
      puts("i is equal to three (case)"); break;
    default:
      puts("i is some other number");
  }

  return 0;
}
