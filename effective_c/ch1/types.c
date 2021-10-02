#include <stdio.h>
#include <stdbool.h>

int main(void) {

  bool booly = true;
  bool wooly = !(true);

  if (booly)
    puts("It's true!");

  if(!wooly)
    puts("It's false!");

  return 0;
}

