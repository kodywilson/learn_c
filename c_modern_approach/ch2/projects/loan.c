#include <stdio.h>

float calc(float amt, float interest, float payment)
{
  return (amt - payment) + (amt * interest);
}

int main(void)
{
  float amount, interest, payment;
  // Enter loan parameters
  printf("Enter amount of loan: ");
  scanf("%f", &amount);
  printf("Enter interest rate: ");
  scanf("%f", &interest);
  printf("Enter monthly payment: ");
  scanf("%f", &payment);
  // Make loan calculations
  interest = interest / 100.0 / 12.0;
  amount = calc(amount, interest, payment);
  printf("Balance remaining after first payment: $%.2f\n", amount);
  amount = calc(amount, interest, payment);
  printf("Balance remaining after second payment: $%.2f\n", amount);
  amount = calc(amount, interest, payment);
  printf("Balance remaining after third payment: $%.2f\n", amount);
  return 0;
}

