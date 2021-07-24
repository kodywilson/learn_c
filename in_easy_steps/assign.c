#include <stdio.h>

int main(void)
{
  int a, b;
  printf("Assigned:\n");
  printf("\tVariable a = %d\n", a = 8);
  printf("\tVariable b = %d\n", b = 4);
  printf("Added & assigned:\n");
  printf("Variable a+=b (8+=4) a = %d\n", a += b);
  printf("Subtracted & assigned:\n");
  printf("Variable a-=b (12-=4) a = %d\n", a -= b); 
  printf("Multiplied & assigned:\n");
  printf("Variable a*=b (8*=4) a = %d\n", a *= b); 
  printf("Divided & assigned:\n");
  printf("Variable a/=b (32/=4) a = %d\n", a /= b); 
  printf("Modulated & assigned:\n");
  printf("Variable a%%=b (8%%=4) a = %d\n", a %= b); 
  return 0;
}

