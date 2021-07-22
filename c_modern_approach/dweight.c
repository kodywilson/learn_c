#include <stdio.h>

int main(void)
{
  int height = 8, length = 12, width = 10, weight;
  weight = (height * length * width + 165) / 166;
  printf("Dimensions: %dx%dx%d\n", length, width, height);
  printf("Volume (cubic inches): %d\n", length * width * height);
  printf("Dimensional weight (pounds): %d\n", weight);
  return 0;
}

