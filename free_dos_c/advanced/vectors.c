#include <stdio.h>

typedef struct {
  float x;
  float y;
} vector_t;

vector_t add_vector(vector_t a, vector_t b) {
  vector_t result;

  result.x = a.x + b.x;
  result.y = a.y + b.y;

  return result;
}

int main() {
  vector_t a, b, result;

  a.x = 2.0;
  a.y = 2.0;

  b.x = 1.0;
  b.y = 3.0;

  result = add_vector(a, b);

  printf("%0.2f, %0.2f plus %0.2f, %0.2f is %0.2f.%0.2f\n", a.x, a.y, b.x, b.y, result.x, result.y);

  return 0;
}
