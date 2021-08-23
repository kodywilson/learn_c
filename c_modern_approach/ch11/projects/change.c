#include <stdio.h>

// prototypes
void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *ones);

int main(void)
{
  int amount, twenties, tens, fives, ones;
  printf("Enter an amount: ");
  scanf("%d", &amount);
  pay_amount(amount, &twenties, &tens, &fives, &ones);
  printf("$20 bills: %d\n", twenties);
  printf("$10 bills: %d\n", tens);
  printf(" $5 bills: %d\n", fives);
  printf(" $1 bills: %d\n", ones);

  return 0;
}

void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *ones)
{
  *twenties = dollars / 20;
  *tens = dollars % 20 / 10;
  *fives = dollars % 20 % 10 / 5;
  *ones = dollars % 20 % 10 % 5 / 1;
}

