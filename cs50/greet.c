#include <cs50.h>
#include <stdio.h>

int main(void)
{
  // Greet user
  string answer = get_string("What is your name? ");
  printf("Hello, %s\n", answer);
}

