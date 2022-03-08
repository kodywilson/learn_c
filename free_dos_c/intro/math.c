#include <stdio.h>

int main() {
  int top;
  int bottom;
  int result;
  int remain;

  top = 25;
  bottom = 5;

  result = top / bottom;
  remain = top % bottom;//top - result * bottom;

  printf("%d / %d = %d rem %d\n", top, bottom, result, remain);

  return 0;
}
