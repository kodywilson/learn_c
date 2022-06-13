#include <stdio.h>

int main() {

  char weapon[64];

  snprintf(weapon, 64, "Weapon: %s", "longsword");
  puts(weapon);
  snprintf(weapon, 64, "Weapon: %s", "dagger");
  puts(weapon);
  snprintf(weapon, 64, "Weapon: %s", "mace");
  puts(weapon);

  return 0;
}
