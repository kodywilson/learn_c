#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main(void) {

  bool booly = true;
  bool wooly = !(true);
  int a[10] = {1,2,3,4,5,6,7,8,9,10};

  struct sigrecord {
    int signum;
    char signame[20];
    char sigdesc[100];
  } sigline, *sigline_p;

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

  // structs
  sigline.signum = 5;
  strcpy(sigline.signame, "SIGINT");

  printf("Signature number is %d\n", sigline.signum);
  printf("Signature name is %s\n", sigline.signame);

  sigline_p = &sigline;
  strcpy(sigline_p->sigdesc, "Interrupt from keyboard");

  puts(sigline_p->sigdesc);

  // update structure member
  sigline_p->signum = 7;
  printf("Signature number is now %d\n", sigline_p->signum);

  return 0;
}

