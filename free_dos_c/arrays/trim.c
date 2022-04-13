#include <stdio.h>

int is_whitespace(char ch) {
  return ((ch == ' ') || (ch == '\t') || (ch == '\n'));
}

char * ltrim_string(char *string) {
  char *ptr;
  // find the first non-whitespace character and return pointer to that location

  ptr = string;

  while ((ptr[0] != '\0') && (is_whitespace(ptr[0]))) ptr = ptr + 1; 

 return ptr; 
}

int main() {
  puts(ltrim_string("   Hi"));
  puts(ltrim_string("      there world"));

  return 0;
}
