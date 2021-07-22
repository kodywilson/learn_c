#include <stdio.h>

#define INCHES_PER_POUND 166

int main(void)
{
  int height = 8, length = 12, width = 10, weight;
  printf("Enter box dimensions, length, width, height (ie. 8 12 10):\n");
  scanf("%d %d %d", &length, &width, &height);
  weight = (height * length * width + INCHES_PER_POUND - 1) / INCHES_PER_POUND;
  printf("Dimensions: %dx%dx%d\n", length, width, height);
  printf("Volume (cubic inches): %d\n", length * width * height);
  printf("Dimensional weight (pounds): %d\n", weight);
  return 0;
}

