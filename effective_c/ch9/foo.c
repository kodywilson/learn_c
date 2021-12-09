#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bar.h"
#include "bar.h" // normally duplicate inclusion is not so obvious
#define FOO (19 + 39)
#define ALF 26

int main(void) {
  int i = FOO;
  int j = BAR_sq(10);
  int k = BAR_sq(7 + 7);
  int a[ALF];
  char kay = 'K';
  char ay = 65;
  char zee = 'Z';
  char tiny_zee = zee + 32;
  char tiny_ay = ay + 32;

  char c;

  srand(time(NULL));
  int r = rand() % ALF;
  int s = (rand() % ALF) + 65; // another way to create a capital letter

  printf("i = %d  and  j = %d  and  k = %d\n", i, j, k);
  printf("The value of func is %d\n", func());
  printf("k * 3 = %d\n", BAR_triple(k));

  for (int m = 1; m < ALF + 1; m++)
    a[m - 1] = m + 64;

  //printf("The first letter of the alphabet is %c\n", letter());
  printf("The first letter of the alphabet is %c\n", (char) a[0]);

  c = i + '0';
  printf("We saw above that i is %d. That would be %c on the alphabet\n", i, c);
  printf("You can add %d to %c to get %c\n", 3, c, (char) c + 3);
  printf("We can subtract too. %c - %d gives %c\n", c, 5, (char) c - 5);
  
  for (int n = 0; n < ALF; n++)
    printf("%d ", a[n] * a[n]);
  printf("\n");

  for (int o = ALF - 1; o >= 0; o--)
    printf("%d ", a[o] * a[o]);
  printf("\n");

  printf("The letter of the day is %c\n", kay);
  printf("%d in ascii is the letter %c\n", ay, ay);
  printf("%d in ascii is the letter %c\n", tiny_ay, tiny_ay);
  printf("%d in ascii is the letter %c\n", zee, zee);
  printf("%d in ascii is the letter %c\n", tiny_zee, tiny_zee);
  printf("\n");
  printf("Ok, now I am going to summon a random letter. It is %c this time!\n", a[r]);
  r = rand() % ALF;
  printf("Ok, now I am going to summon a random letter. It is %c this time!\n", a[r]);
  r = rand() % ALF;
  printf("Ok, now I am going to summon a random letter. It is %c this time!\n", a[r]);

  printf("Let's see what our letter function returns: %c\n", letter2());

  printf("Another random letter, %c, this one created with rand() %% 26 + 65\n", s);

  return 1;
}

