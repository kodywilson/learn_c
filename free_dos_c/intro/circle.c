#include <stdio.h>

#define PI 3.141592

int main() {
  float radius, perim, area;

  puts("Enter the radius: ");
  scanf("%f", &radius);

  perim = 2 * PI * radius;
  area = PI * radius * radius;

  printf("Perimeter of circle (r=%f) is %f\n", radius, perim);
  printf("Area of a circle (r=%f) is %f\n", radius, area);

  return 0;
}
