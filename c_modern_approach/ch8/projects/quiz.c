#include <stdio.h>

#define S 5 // number of students and quizzes

int main(void)
{
  int high, low, quiz, student, total, grades[S][S];

  for (student = 0; student < S; student++)
  {
    printf("Enter grades for student #%d: ", student + 1);
    for (quiz = 0; quiz < S; quiz++)
      scanf("%d", &grades[student][quiz]);
  }

  printf("\nStudent Total Average\n");
  for (student = 0; student < S; student++)
  {
    printf("%4d      ", student + 1);
    total = 0;
    for (quiz = 0; quiz < S; quiz++)
      total += grades[student][quiz];
    printf("%3d    %3d\n", total, total / S);
  }

  // calculate quiz stats
  printf("\n Quiz  Average  High  Low\n");
  for (quiz = 0; quiz < S; quiz++)
  {
    printf("%d    ", quiz + 1);
    total = 0;
    high = 0;
    low = 100;
    for (student = 0; student < S; student++)
    {
      total += grades[student][quiz];
      if (grades[student][quiz] > high)
        high = grades[student][quiz];
      if (grades[student][quiz] < low)
        low = grades[student][quiz];
    }
    printf("%3d    %3d    %3d\n", total / S, high, low);
  }

  return 0;
}

