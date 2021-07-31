#include <stdio.h>

int main()
{
  // variables
  int item_number, day, month, year;
  float item_price;

  // Get product information
  printf("Enter item number: ");
  scanf("%d", &item_number);
  printf("Enter unit price: ");
  scanf("%f", &item_price);
  printf("Enter purchase date (mm/dd/yyyy): ");
  scanf("%d/%d/%d", &month, &day, &year);

  // Format and display product information
  printf("\nItem\tUnit\t\tPurchase\n\tPrice\t\tDate\n");
  printf("%-6d\t$%7.2f\t%d/%d/%d\n", item_number, item_price, month, day, year);
  return 0;
}

