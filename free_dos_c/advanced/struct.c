#include <stdio.h>

typedef struct {
  float x;
  float y;
} coord_t;

int main() {
  coord_t coord;

  coord.x = 10.0;
  coord.y = 1.5;

  printf("x,y is %f,%f\n", coord.x, coord.y);

  return 0;
}
