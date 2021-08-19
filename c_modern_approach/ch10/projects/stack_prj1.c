// simple stack in c
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100

// external variables
char contents[STACK_SIZE];
int top = 0;

void make_empty(void)
{
  top = 0;
}

bool is_empty(void)
{
  return top == 0;
}

bool is_full(void)
{
  return top == STACK_SIZE;
}

void push(char a)
{
  if (is_full())
    exit(1);
    //stack_overflow();
  else
    contents[top++] = a;
}

char pop(void)
{
  if (is_empty())
    exit(1);
    //stack_underflow();
  else
    return contents[--top];
}

int main(void)
{
  bool match;
  char chr;
  printf("Enter parentheses and/or braces: ");
  do
  {
    chr = getchar();
    if (chr == '(' || chr == '{')
      push(chr);
    else if (chr == '}' && contents[top - 1] == '{') {
      match = true;
      pop();
    }
    else if (chr == ')' && contents[top - 1] == '(') {
      match = true;
      pop();
    }
    else if (chr != '\n')
      match = false;
  }
  while (chr != '\n');

  if (is_empty() && match == true)
    printf("Parentheses/braces are nested properly\n");
  else
    printf("Not nested properly\n");

  return 0;
}

