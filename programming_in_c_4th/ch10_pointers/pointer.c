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

  int i1, i2;
  int *p1, *p2;

  i1 = 5;
  p1 = &i1;
  i2 = *p1 / 2 + 10;
  p2 = p1;

  printf("i1 = %i, i2 = %i, *p1 = %i, *p2 = %i\n", i1, i2, *p1, *p2);

  struct date
  {
    int month;
    int day;
    int year;
  };

  struct date today, *datePtr;

  datePtr = &today;

  datePtr->month = 9;
  datePtr->day = 25;
  datePtr->year = 2015;

  printf("Today's date is %i/%i/%.2i.\n", datePtr->month, datePtr->day, datePtr->year % 100);

  return 0;
}

