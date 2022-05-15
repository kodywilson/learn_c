// Functions related to combat
// selecting foe, handling battle rounds, etc.


void combat(WINDOW *game_text, WINDOW *select, WINDOW *stats, pc *player, int environ) {
  int monster_roll;
  pc monster;  // create struct for monster

  // roll for foe - type first (so we can vary based on environment)
  switch(environ) {
    case 0: monster_roll = dice(1, 4); break;// 4 choices, so roll 4 sided die
    default: monster_roll = dice(1, 4); break;
  }

  build_character(mobs[monster_roll].name, mobs[monster_roll], &monster);
  // DEBUG
  mvwprintw(game_text, 3, 1, "You rolled %d: %s", monster_roll, monster.desc);
  wrefresh(game_text);
  getch();
}