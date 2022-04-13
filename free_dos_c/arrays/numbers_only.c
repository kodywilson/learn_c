#include <stdio.h>

int is_charstring(char *bigstring, char c) {
  int i = 0;

  while (bigstring[i] != '\0') {
    if (bigstring[i] == c) return 1;
    i++;
  }

  return 0;
}

int is_number(char *string) {

  int i = 0;
  char nums[] = "1234567890";

  while (string[i] != '\0') {
    if (!is_charstring(nums, string[i])) return 0;
    i++;
  }

  return 1;
}

int main() {
  // test if string contains only numbers
  if (is_number("123456789")) puts("String 123456789 contains only numbers");
  if (!is_number("1234567d89")) puts("String 1234567d89 does not contain only numbers");
  // this next one should not show up when you run the program
  if (!is_number("123456789")) puts("String 1234567d89 does not contain only numbers");

  return 0;
}
