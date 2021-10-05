#include <stdio.h>
#include <stdbool.h>

int main(void) {

  bool booly = true;
  bool wooly = !(true);
  int a[10] = {1,2,3,4,5,6,7,8,9,10};

  if (booly)
    puts("It's true!");

  if (!wooly)
    puts("It's false!");

  if (!(!(!wooly)) && booly)
    puts("Whatdya know, that's true!");

  printf("The value of booly is %d. :)\n", booly);

  for (int i = 0; i < 10; i++)
    printf("%d ", i[a]);
  printf("\n");

  return 0;
}

