// used in foo.c
#ifndef BAR_H
#define BAR_H
int func(void) {
  int i = 3 + 3;
  return i;
}
char letter(void) { return 'A'; }
char letter2(void) { // terrible name, lol
  return 'X';
}

#endif // BAR_H
#define BAR_sq(y) ((y) * (y))
#define BAR_triple(x) ((x) * 3)
