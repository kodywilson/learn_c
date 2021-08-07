// Checkbook balancing program

#include <stdio.h>

int main(void)
{
  int choice;
  float amount = .00f, balance = .00f;

  printf("*** ACME checkbook balancing program ***\n");
  printf("Commands: 0=clear, 1=credit, 2=debit, 3=balance, 4=exit\n");

  for (;;)
  {
    printf("Enter command: ");
    scanf("%d", &choice);
    switch (choice)
    {
      case 0:
        balance = .00f;
        printf("Balance cleared.\n");
        break;
      case 1:
        printf("Enter amount of credit: \n");
        scanf("%f", &amount);
        balance += amount;
        break;
      case 2:
        printf("Enter amount of debit: \n");
        scanf("%f", &amount);
        balance -= amount;
        break;
      case 3:
        printf("Current balance: $%.2f\n", balance);
        break;
      case 4:
        printf("Have a good one!\n");
        return 0;
      default:
        printf("Commands: 0=clear, 1=credit, 2=debit, 3=balance, 4=exit\n");
        break;
    }
  }

  return 0;
}

