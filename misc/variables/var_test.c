#include <stdio.h>

int main() {

  char weapon[64];
  int stat1 = 14, stat2 = 8, stat3 = 6;
  float cr = .25;

  snprintf(weapon, 64, "Weapon: %s", "longsword");
  puts(weapon);
  snprintf(weapon, 64, "Weapon: %s", "dagger");
  puts(weapon);
  snprintf(weapon, 64, "Weapon: %s", "mace");
  puts(weapon);

  printf("mod1: %d  mod2: %d  mod3: %d\n  float1: %.02f", (stat1 - 10) / 2, (stat2 - 10) / 2, (stat3 - 10) / 2, cr);

  return 0;
}
