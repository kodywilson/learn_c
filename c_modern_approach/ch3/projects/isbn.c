#include <stdio.h>

int main()
{
  int grp1, grp2, grp3, grp4, grp5;
  // Get ISBN from user
  printf("Enter ISBN: ");
  scanf("%d-%d-%d-%d-%d", &grp1, &grp2, &grp3, &grp4, &grp5);
  printf("GS1 prefix: %d\n", grp1);
  printf("Group identifier: %d\n", grp2);
  printf("Publisher code: %d\n", grp3);
  printf("Item number: %d\n", grp4);
  printf("Check digit: %d\n", grp5);
  return 0;
}

