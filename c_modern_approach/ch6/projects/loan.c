#include <stdio.h>

float calc(float amt, float interest, float payment)
{
  return (amt - payment) + (amt * interest);
}

int main(void)
{
  int number;
  float amount, interest, payment;
  // Enter loan parameters
  printf("Enter amount of loan: ");
  scanf("%f", &amount);
  printf("Enter interest rate: ");
  scanf("%f", &interest);
  printf("Enter monthly payment: ");
  scanf("%f", &payment);
  printf("Enter number of payments: ");
  scanf("%d", &number);
  // Make loan calculations
  interest = interest / 100.0 / 12.0;
  for (int i = 1; i <= number; i++)
  {
    amount = calc(amount, interest, payment);
    printf("Balance remaining after payment %d: $%.2f\n", i, amount);
  }
  return 0;
}

