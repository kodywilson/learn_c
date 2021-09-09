#include <stdio.h>
#include <ctype.h>

// prototypes
void squeeze(char s[], int c); // ch2 exe2.4
int any(char s1[], char s2[]);

int main(void)
{
  int i;
  char s1[] = "This is turkey time", s2[] = "te";
  char s3[] = "Another test";

  for (i = 0; s2[i] != '\0'; i++)
    squeeze(s1, s2[i]);

  printf("%s\n", s1);

  printf("Position of first matching character: %d\n", any(s3, s2));

  return 0;
}

void squeeze(char s[], int c)
{
  int i, j;

  for (i = j = 0; s[i] != '\0'; i++)
    if (toupper(s[i]) != toupper(c))
      s[j++] = s[i];
  s[j] = '\0';
}

int any(char s1[], char s2[])
{
  for (int i = 0; s1[i] != '\0'; i++)
    for (int j = 0; s2[j] != '\0'; j++)
      if (toupper(s1[i]) == toupper(s2[j]))
        return i + 1;
  return -1;
}

