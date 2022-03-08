#include <stdio.h>

int main() {
  float radius = 16.0, perim, area;

  perim = 2 * 3.141 * radius;
  area = 3.141 * radius * radius;

  printf("Perimeter of circle (r=%f) is %f\n", radius, perim);
  printf("Area of a circle (r=%f) is %f\n", radius, area);

  return 0;
}
