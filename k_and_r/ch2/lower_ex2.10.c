#include <stdio.h>

void lower(char s[]);

int main(void)
{
  char s[] = "Hey there YOU know this is CRAZY";
  char s2[] = "THIS IS ONLY A TEST";
  lower(s);
  printf("%s\n", s);
  lower(s2);
  printf("%s\n", s2);

  return 0;
}

void lower(char s[])
{
  char c;
  int i = 0;

  while ((c = s[i]) != '\0') {
    s[i] = (c > 64 && c < 91) ? c + 32 : c;
    i++;
  }
}

