// Functions related to combat
// selecting foe, handling battle rounds, etc.


void combat(WINDOW *game_text, WINDOW *select, WINDOW *stats, pc *player, int environ) {
  int choice, monster_roll, num_choices;  // store result of dice roll
  pc monster;        // create struct for monster
  char combat_prompt[96];
  int  choice_key[6];

  snprintf(combat_prompt, 95, "What will you do now, %s?", player->name);

  // roll for foe - by environ (different mobs live in different places)
  switch(environ) {
    case 0: monster_roll = dice(1, 4); break;// 4 choices, so roll 4 sided die
    default: monster_roll = dice(1, 4); break;
  }

  build_character(mobs[monster_roll].name, mobs[monster_roll], &monster);
  // DEBUG
  mvwprintw(game_text, 3, 1, "You rolled %d: %s", monster_roll, monster.desc);
  wrefresh(game_text);
  getch();
  while(1) { // battle loop
    // clear previous choices
    num_choices = 0;
    for (int i = 0; i < 6; i++) {
      memset(choices[i], 0, MAX_CHOICE_LEN);
      choice_key[i] = 99;           // "null" array
    }
    // We have our foe, now we fight until either one succumbs or you flee
    // roll to see who goes first - bonus to dex, int, wis, and dodge (good for rogues)
    // formula is d20 + mods > x = player goes first
    // for now, just a simple 50 50 chance with minor bonus
    if ((dice(1, 20) + player->dodge) > 10) {
      // you get to go first this round!
      if (strcmp(player-role, "Cleric")) {
        // set up options for Clerics
        choices[num_choices] = "Attack"; choice_key[num_choices] = 0; num_choices++; // set first option as attack
        choices[1] = "Heal and Attack"; choice_key[num_choices] = 7; num_choices++; // set second option as heal and attack
        choices[2] = "Flee"; choice_key[num_choices] = 1; num_choices++; // set third option as attempt to flee
      }
      choice = choose_test(select, choices, num_choices, combat_prompt);
    } else {
      // monster goes first this round!

    }
  }
}