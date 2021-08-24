#include <stdio.h>
#include <string.h>

int main(void)
{
  printf("When you come to a fork in the road, take it. "
         "--Yogi Berra\n");
  
  printf("%8s\n", "Yak");
  printf("%-8s%s\n", "Yak", "Yak");

  puts("This is only a test");

  char msg1[64], msg2[64] = "The secret is in the secret.";

  strcpy(msg1, msg2);

  puts(msg1);

  return 0;
}

