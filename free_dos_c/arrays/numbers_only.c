#include <stdio.h>

int is_number(char *string) {
  for (int i = 0; string[i] != '\0'; i++) {
    printf("%c ", string[i]);
    if ((((int) string[i] < 0) || ((int) string[i] > 9)) && (string[i+1] == '\0')) return 1;
  }

  return 0;
}

int main() {
  // test if string contains only numbers
  if (is_number("123456789")) puts("String 123456789 contains only numbers");
  if (is_number("1234567d89") > 0) puts("String 1234567d89 does not contain only numbers");

  return 0;
}
