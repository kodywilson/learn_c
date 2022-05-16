// Functions related to combat
// selecting foe, handling battle rounds, etc.

#define COMBAT_PROBABILITY 15 // dial it down for less monsters

void combat(WINDOW *game_text, WINDOW *select, WINDOW *stats, pc *player, int environ) {
  int choice, flee, monster_roll, num_choices;  // store result of dice roll
  pc monster;        // create struct for monster
  char combat_prompt[96];
  int  choice_key[MAX_CHOICES];

  snprintf(combat_prompt, 95, "What will you do now, %s?", player->name);

  // roll for foe - by environ (different mobs live in different places)
  switch(environ) {
    case 0: monster_roll = dice(1, 4) - 1; break;   // 4 choices, so roll 4 sided die
    default: monster_roll = dice(1, 4) - 1; break;  // dice never return 0 so subtract one for proper array indexing
  }

  build_character(mobs[monster_roll].name, mobs[monster_roll], &monster); // generate foe

  wclear(select);
  wrefresh(select);
  mvwprintw(game_text, 1, 1, "%s", monster.desc);
  mvwaddstr(game_text, 3, 1, "Press any key to begin combat!");
  wrefresh(game_text);
  getch();
  
  while(1) { // battle loop
    flee = 0;
    // clear previous choices
    num_choices = 0;
    for (int i = 0; i < MAX_CHOICES; i++) {
      memset(choices[i], 0, MAX_CHOICE_LEN);
      choice_key[i] = 99;           // "null" array
    }
    // We have our foe, now we fight until either one succumbs or you flee
    // roll to see who goes first - bonus to dex, int, wis, and dodge (good for rogues)
    // formula is d20 + mods > x = player goes first
    // for now, just a simple 50 50 chance with minor bonus
    if ((dice(1, 20) + player->dodge) > COMBAT_PROBABILITY) {
      // you get to go first this round!
      // this should be a function, player attack
      if (strcmp(player->role, "Cleric")) {
        // set up options for Clerics
        strncpy(choices[num_choices], "Attack", MAX_CHOICE_LEN); choice_key[num_choices] = 0; num_choices++;          // set first option as attack
        strncpy(choices[num_choices], "Heal and Attack", MAX_CHOICE_LEN); choice_key[num_choices] = 7; num_choices++; // set second option as heal and attack
        strncpy(choices[num_choices], "Flee", MAX_CHOICE_LEN); choice_key[num_choices] = 2; num_choices++;            // set third option as attempt to flee
      }
      // need to create key for actions, ie. 0 = attack, 2 = flee, 7 = cast spell, etc.
      if (strcmp(player->role, "Knight")) {
        // set up options for Knights
        strncpy(choices[num_choices], "Attack", MAX_CHOICE_LEN); choice_key[num_choices] = 0; num_choices++;           // set first option as attack
        //strncpy(choices[num_choices], "Heal and Attack", MAX_CHOICE_LEN); choice_key[num_choices] = 7; num_choices++; // set second option as heal and attack
        strncpy(choices[num_choices], "Flee", MAX_CHOICE_LEN); choice_key[num_choices] = 2;                            // set third option as attempt to flee
      }
      if (strcmp(player->role, "Rogue")) {
        // set up options for Rogues
        strncpy(choices[num_choices], "Attack", MAX_CHOICE_LEN); choice_key[num_choices] = 0; num_choices++;           // set first option as attack
        //strncpy(choices[num_choices], "Heal and Attack", MAX_CHOICE_LEN); choice_key[num_choices] = 7; num_choices++; // set second option as heal and attack
        strncpy(choices[num_choices], "Flee", MAX_CHOICE_LEN); choice_key[num_choices] = 2; num_choices++;            // set third option as attempt to flee
      }
      if (strcmp(player->role, "Wizard")) {
        // set up options for Wizards
        strncpy(choices[num_choices], "Attack", MAX_CHOICE_LEN); choice_key[num_choices] = 0; num_choices++;          // set first option as attack
        //strncpy(choices[num_choices], "Heal and Attack", MAX_CHOICE_LEN); choice_key[num_choices] = 7; num_choices++; // set second option as heal and attack
        strncpy(choices[num_choices], "Flee", MAX_CHOICE_LEN); choice_key[num_choices] = 2; num_choices++;            // set third option as attempt to flee
      }
      choice = choose_test(select, choices, num_choices, combat_prompt);
      switch (choice_key[choice]) {
        case 0: mvwprintw(game_text, 3, 1, "You swing at %s", monster.name);
                wrefresh(game_text);
                napms(250);
                monster.cur_hp-=4;
                break;
        case 2: mvwprintw(game_text, 3, 1, "You run as fast as you can away from %s!", monster.name);
                wrefresh(game_text);
                napms(250);
                flee = 1;
                break;
        default: break;
      }
    } else {
      // monster goes first this round!
      // create function, monster attack - for now just have monster wiff each time
      mvwprintw(game_text, 3, 1, "%s attacks you %s, but misses!", monster.name, player->name);
      wrefresh(game_text);
      napms(250);
    }
    if (flee == 1) break; // exit combat loop, you escaped!
    if (monster.cur_hp <= 0) {
      mvwprintw(game_text, 5, 1, "You defeated %s, %s!", monster.name, player->name);
      player->coin+=monster.coin;
      player->xp+=monster.xp;
      wrefresh(game_text);
      napms(500);
      break;
    }
    wclear(game_text);
  }
}