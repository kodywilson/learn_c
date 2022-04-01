// 00000000 = 0
// 00000001 = 1
// 00000010 = 2
// 00000011 = 3
// 00000100 = 4

#include <stdio.h>

int main() {
  int a = 1;
  int b = 3;
  int c = 5;

  printf("a is %d\n", a);
  printf("b is %d\n", b);
  printf("c is %d\n", c);

  puts("binary goes like 8421");
  puts("binary of 1 is 00000001");
  puts("binary of 3 is 00000011");
  puts("binary of 5 is 00000101");

  printf("a&b is %d\n", a & b);
  printf("a|b is %d\n", a | b);
  printf("a&c is %d\n", a & c);
  printf("a|c is %d\n", a | c);

  return 0;
}
