#include <stdio.h>

// constants
#define VOL_RATIO (4.0f / 3.0f)
#define PI 3.14159

int main(void)
{
  float radius = 10.0f;
  printf("Enter radius of sphere: "); 
  scanf("%f", &radius); 
  printf("Volume of sphere is %.2f\n", VOL_RATIO * PI * radius * radius * radius);
  return 0;
}

