#include <stdio.h>

int main(void)
{
  // Variables
  int shares;
  float commission, rival_commission, share_price, trade_val;

  // Get amount of trade
  printf("Enter number of shares: ");
  scanf("%d", &shares);
  printf("Enter price per share: ");
  scanf("%f", &share_price);
  trade_val = shares * share_price;

  // Calculate commision
  if (trade_val < 2500.00f)
  {
    commission = 30.00f + .017f * trade_val;
  }
  else if (trade_val < 6250.00f)
  {
    commission = 56.00f + .0066f * trade_val;
  }
  else if (trade_val < 20000.00f)
  {
    commission = 76.00f + .0034f * trade_val;
  }
  else if (trade_val < 50000.00f)
  {
    commission = 100.00f + .0022f * trade_val;
  }
  else if (trade_val < 500000.00f)
  {
    commission = 155.00f + .0011f * trade_val;
  }
  else 
  {
    commission = 255.00f + .0009f * trade_val;
  }

  // Calculate rival broker's commission
  if (shares < 2000)
  {
    rival_commission = 33.00 + .03 * shares;
  }
  else
  {
    rival_commission = 33.00 + .02 * shares;
  }

  // Display commission
  printf("Commission: $%.2f\n", commission);
  printf("Rival broker: $%.2f\n", rival_commission);

  return 0;
}

