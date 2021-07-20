#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])
{
  // take arguments
  if (argc >= 2)
  {
    printf("Hello, %s\n", argv[1]);
  }
  else
  {
    printf("Hello, World\n");
  }
}

