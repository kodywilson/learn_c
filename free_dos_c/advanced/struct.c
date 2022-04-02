#include <stdio.h>

int main() {
  struct {
    float x;
    float y;
  } coord;

  coord.x = 10.0;
  coord.y = 1.5;

  printf("x,y is %f,%f\n", coord.x, coord.y);

  return 0;
}
