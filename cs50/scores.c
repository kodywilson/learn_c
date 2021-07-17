#include <cs50.h>
#include <stdio.h>

float average(int length, int array[])
{
  int sum = 0;
  for (int i = 0; i < length; i++)
  {
    sum = sum + array[i];
  }
  return sum / (float) length;
}

int main(void)
{
  int number_scores = get_int("How many scores do you need to average?");
  int scores[number_scores];
  for ( int i = 0; i < number_scores; i++)
  {
    scores[i] = get_int("Score #%i: ", i + 1);
  }
  printf("The average score is: %f\n", average(number_scores, scores));
}
