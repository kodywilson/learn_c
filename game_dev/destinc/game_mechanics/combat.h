// Functions related to combat
// selecting foe, handling battle rounds, etc.

#define AC_BASE 10
#define COMBAT_PROBABILITY 15 // dial it down for less monsters

int actions(char *role) {
  int num_choices = 0;

  if (strcmp(role, "Cleric") == 0) {
        // set up options for Clerics
        strncpy(choices[num_choices], "Attack", MAX_CHOICE_LEN); choice_key[num_choices] = 0; num_choices++;          // set first option as attack
        strncpy(choices[num_choices], "Heal and Attack", MAX_CHOICE_LEN); choice_key[num_choices] = 7; num_choices++; // set second option as heal and attack
        strncpy(choices[num_choices], "Flee", MAX_CHOICE_LEN); choice_key[num_choices] = 2; num_choices++;            // set third option as attempt to flee
      }
      // need to create key for actions, ie. 0 = attack, 2 = flee, 7 = cast spell, etc.
      if (strcmp(role, "Knight") == 0) {
        // set up options for Knights
        strncpy(choices[num_choices], "Attack", MAX_CHOICE_LEN); choice_key[num_choices] = 0; num_choices++;           // set first option as attack
        //strncpy(choices[num_choices], "Heal and Attack", MAX_CHOICE_LEN); choice_key[num_choices] = 7; num_choices++; // set second option as heal and attack
        strncpy(choices[num_choices], "Flee", MAX_CHOICE_LEN); choice_key[num_choices] = 2; num_choices++;             // set third option as attempt to flee
      }
      if (strcmp(role, "Rogue") == 0) {
        // set up options for Rogues
        strncpy(choices[num_choices], "Attack", MAX_CHOICE_LEN); choice_key[num_choices] = 0; num_choices++;           // set first option as attack
        //strncpy(choices[num_choices], "Heal and Attack", MAX_CHOICE_LEN); choice_key[num_choices] = 7; num_choices++; // set second option as heal and attack
        strncpy(choices[num_choices], "Flee", MAX_CHOICE_LEN); choice_key[num_choices] = 2; num_choices++;            // set third option as attempt to flee
      }
      if (strcmp(role, "Wizard") == 0) {
        // set up options for Wizards
        strncpy(choices[num_choices], "Attack", MAX_CHOICE_LEN); choice_key[num_choices] = 0; num_choices++;          // set first option as attack
        //strncpy(choices[num_choices], "Heal and Attack", MAX_CHOICE_LEN); choice_key[num_choices] = 7; num_choices++; // set second option as heal and attack
        strncpy(choices[num_choices], "Flee", MAX_CHOICE_LEN); choice_key[num_choices] = 2; num_choices++;            // set third option as attempt to flee
      }

  return num_choices;
}

int attack(pc *attacker, pc *target) {
  int ac, damage, roll;

  ac = AC_BASE + target->dodge + target->armor;                      // Base AC + bonuses
  roll = dice(1, 20) + attacker->dmg + ((attacker->str - 10) / 2);   // d20 + bonuses

  if (roll >= ac ) { // may need to drop the damage bonus and only use for to hit
    damage = dice(1, 3) + attacker->dmg + ((attacker->str - 10) / 2);
    target->cur_hp-=damage;
  } else {
    damage = 0;
  }

  return damage; // later, find a way to reflect damage absorption. For now, less than 1 means they missed
}

// handle player actions and battle choices, return choice
int player_turn(WINDOW *select, WINDOW *game_text, pc *player, pc *monster, char *combat_prompt) {
  int choice = 2, player_damage = 0;
  
  num_choices = actions(player->role);
  choice = choose(select, num_choices, combat_prompt);
  switch (choice_key[choice]) {
    case 0: mvwprintw(game_text, 3, 1, "You swing at %s", monster->name);
            wrefresh(game_text);
            napms(250);
            player_damage = attack(player, monster);
            if (player_damage > 0) {
              mvwprintw(game_text, 4, 1, "You hit %s for %d damage!", monster->name, player_damage);
            } else {
              mvwprintw(game_text, 4, 1, "The %s dodges your strike.", monster->name);
            }
            wrefresh(game_text);
            napms(250);
            break;
    case 2: mvwprintw(game_text, 4, 1, "You run as fast as you can away from %s!", monster->name);
            wrefresh(game_text);
            napms(250);
            break;
    default: break;
  }

  return choice;
}

void combat(WINDOW *game_text, WINDOW *select, WINDOW *stats, pc *player, int environ) {
  int choice, flee, monster_roll, player_damage, mob_damage;  // store result of dice roll
  pc monster;        // create struct for monster
  char combat_prompt[96];

  snprintf(combat_prompt, 95, "What will you do now, %s?", player->name);

  // roll for foe - by environ (different mobs live in different places)
  // 0 is dungeon, etc.
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
  wclear(game_text);
  wrefresh(game_text);
  
  while(1) { // battle loop
    // clear previous choices
    flee = mob_damage = player_damage = num_choices = 0;
    reset_choices();
    // We have our foe, now we fight until either one succumbs or you flee
    // roll to see who goes first - bonus to dex, int, wis, and dodge (good for rogues)
    // formula is d20 + mods > x = player goes first
    // for now, just start with player and takes turns, add check for who goes first later
    if ((dice(1, 20) + player->dodge + player->intel) > 10) { // help rogues and wizards not die
      // you get to go first this round!
      choice = player_turn(select, game_text, player, &monster, combat_prompt);
      if (choice == 2) break; // get out, you fled
    } //else {
      // monster attacks now
      // create function, monster attack - for now just a simple roll
      // two checks to see if monster hits the player. First dodge chance and then against armor
      if (dice(1, 20) > player->dodge) { // ok, they didn't dodge, now check armor
        if (dice(1, 20) > AC_BASE + player->armor) {
          // formula = 1d2 + mob damage bonus + strength bonus (1 for every 2 points over 10 str)
          mob_damage = dice(1, 2) + monster.dmg + ((monster.str - 10) % 2);
          player->cur_hp-=mob_damage;
          mvwprintw(game_text, 5, 1, "%s hits you for %d!", monster.name, mob_damage);
        }
      } else {
        mvwprintw(game_text, 5, 1, "%s attacks you %s, but misses!", monster.name, player->name);
      }
      wrefresh(game_text);
      napms(250);
    if (flee == 1) break; // exit combat loop, you escaped!
    if (monster.cur_hp <= 0) {
      mvwprintw(game_text, 6, 1, "You defeated %s, %s!", monster.name, player->name);
      player->coin+=monster.coin;
      player->xp+=monster.xp;
      wrefresh(game_text);
      napms(500);
      break;
    }
    if (player->cur_hp <= 0) {
      mvwprintw(game_text, 6, 1, "%s killed you, %s...", monster.name, player->name);
      wrefresh(game_text);
      napms(500);
      break;
    }
    wclear(game_text);
    wrefresh(stats);
  }
}