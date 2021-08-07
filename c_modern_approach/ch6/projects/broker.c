#include <stdio.h>

int main(void)
{
  // Variables
  float commission, trade_val;

  printf("Welcome to broker-matic! Enter 0 when done.\n");

  for(;;)
  {
    // Get amount of trade
    printf("Enter value of trade: ");
    scanf("%f", &trade_val);

    if (trade_val == 0)
      break;

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

    // Display commission
    printf("Commission: %.2f\n", commission);
  }

  return 0;
}

