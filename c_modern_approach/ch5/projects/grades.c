#include <stdio.h>

int main(void)
{
  int grade;

  printf("Enter numerical grade: ");
  scanf("%d", &grade);

  printf("Letter grade: ");
  if (grade < 0 || grade > 100)
  {
    printf("ERROR: Enter a valid grade between 0 and 100\n");
    return 1;
  }
  else if (grade < 60)
  {
    printf("F");
  }
  switch (grade / 10)
  {
    case 10:
    case 9: printf("A"); break;
    case 8: printf("B"); break;        
    case 7: printf("C"); break;
    case 6: printf("D"); break;
  }
  printf("\n");

  return 0;

}

