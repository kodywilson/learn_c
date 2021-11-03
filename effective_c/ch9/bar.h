// used in foo.c
#ifndef BAR_H
#define BAR_H
int func(void) {
  return 1;
}
char letter(void) { return 'A'; }
#endif // BAR_H
#define BAR_sq(y) ((y) * (y))
#define BAR_triple(x) ((x) * 3)
