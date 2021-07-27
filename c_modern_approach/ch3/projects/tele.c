#include <stdio.h>

int main()
{
  int grp1, grp2, grp3;
  printf("Enter a phone number [(xxx) xxx-xxxx]: ");
  scanf("(%d) %d-%d", &grp1, &grp2, &grp3);
  printf("You entered %d.%d.%d\n", grp1, grp2, grp3);
  return 0;
}

