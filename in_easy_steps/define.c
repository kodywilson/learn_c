#include <stdio.h>
#define LINE "____________________________"
#define TITLE "C Programming in Easy Steps"
#define AUTHOR "Mike McGrath"
#ifdef _WIN32
#define SYSTEM "Windows"
#endif
#ifdef linux
#define SYSTEM "Linux"
#endif

int main(void)
{
  printf("\n\t%s\n\t%s\n", LINE, TITLE);
  printf("\tby %s\n\t%s\n", AUTHOR, LINE);
  printf("\nOperating System: %s\n", SYSTEM);
  return 0;
}

