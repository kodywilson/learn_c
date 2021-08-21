#include <stdio.h>

int main(void)
{
  char c = 'Q', *char_pointer = &c;
  int count = 10, *int_pointer = &count, x = *int_pointer;

  x = *int_pointer;

  printf("count = %i, x = %i\n", count, x);
  printf("%c %c\n", c, *char_pointer);

  c = '/';
  printf("%c %c\n", c, *char_pointer);

  *char_pointer = '(';
  printf("%c %c\n", c, *char_pointer);

  return 0;
}

