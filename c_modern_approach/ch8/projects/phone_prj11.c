// Find phone phone from text version
#include <stdio.h>

int main()
{
  char chr;
  char phone[15];
  int sequence = 0;

  printf("Enter a phone number: ");
  do
  {
    chr = getchar();
    if (chr == 'A' || chr == 'B' || chr == 'C')
      phone[sequence] = '2';
    else if (chr == 'D' || chr == 'E' || chr == 'F')
      phone[sequence] = '3';
    else if (chr == 'G' || chr == 'H' || chr == 'I')
      phone[sequence] = '4';
    else if (chr == 'J' || chr == 'K' || chr == 'L')
      phone[sequence] = '5';
    else if (chr == 'M' || chr == 'N' || chr == 'O')
      phone[sequence] = '6';
    else if (chr == 'P' || chr == 'R' || chr == 'S')
      phone[sequence] = '7';
    else if (chr == 'T' || chr == 'U' || chr == 'V')
      phone[sequence] = '8';
    else if (chr == 'W' || chr == 'X' || chr == 'Y')
      phone[sequence] = '9';
    else
      phone[sequence] = chr;
    sequence++;
  }
  while (chr != '\n');

  // print out conversion
  printf("In numeric form: ");
  for (int i = 0; i < 15; i++)
  {
    if (phone[i] == '\n')
      break;
    printf("%c", phone[i]);
  }
  printf("\n");

  return 0;
}

