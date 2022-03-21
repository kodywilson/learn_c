#include <stdio.h>

void uppercase(char *string) {
  int i = 0;
  while (string[i] != '\0') {
    if (string[i] >= 97) string[i] = string[i] - 32;
    i++;
  }
}

int main() {
  char stringy[] = "Test experiment ! []9878974r7<F5><F4>xczv";

  uppercase(stringy);

  puts(stringy);

  return 0;
}
