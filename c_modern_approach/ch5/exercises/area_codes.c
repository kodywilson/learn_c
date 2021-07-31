#include <stdio.h>

int main(void)
{
  // variables
  int code;

  // get area code
  printf("Enter area code: ");
  scanf("%d", &code);

  // print largest city in that area code
  printf("Largest city in the %d area code is: ", code);
  switch (code)
  {
    case 229: printf("Albany");   break;
    case 404: printf("Atlanta");  break;
    case 470: printf("Atlanta");  break;
    case 478: printf("Macon");    break;
    case 678: printf("Atlanta");  break;
    case 706: printf("Columbus"); break;
    case 762: printf("Columbus"); break;
    case 770: printf("Atlanta");  break;
    case 912: printf("Savannah"); break;
  }
  printf("\n");

  return 0;
}

