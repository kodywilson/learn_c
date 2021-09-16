#include <stdio.h>

void lower(char s[]);
void upper(char s[]);

int main(void)
{
  char s[] = "Hey there YOU know this is CRAZY";
  char s2[] = "THIS IS ONLY A TEST";
  lower(s);
  printf("%s\n", s);
  lower(s2);
  printf("%s\n", s2);

  upper(s);
  printf("%s\n", s);

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

void upper(char s[])
{
  char c;
  int i = 0;

  while ((c = s[i]) != '\0') {
    s[i] = (c > 96 && c < 123) ? c - 32 : c;
    i++;
  }
}

