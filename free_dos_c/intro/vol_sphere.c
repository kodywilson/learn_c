#include <stdio.h>

#define PI 3.1415926535

int main() {
  float radius, volume;

  printf("Please enter the radius of the sphere: \n");
  scanf("%f", &radius);

  volume = 4 / 3 * PI * radius * radius * radius;

  printf("The volume of a sphere with radius %f is %f\n", radius, volume);

  return 0;
}
