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

// pass window to draw health bar and what entity (monster, etc.)
void health_bar(WINDOW *win, pc *entity) {
  int hp, max_y, max_x;

  getmaxyx(win, max_y, max_x);
  hp = ((float) entity->cur_hp / entity->max_hp * 10); // get amount of health
  if (hp < 1) hp = 1; // need at least one # if mob is still alive

  // we want to print a # for roughly every 10% of health
  // then make missing health turn red, other ones green
  mvwprintw(win, max_y - 4, max_x - 11, "  %s  ", entity->name); // bar label
  mvwaddstr(win, max_y - 3, max_x - 11, "__Health__");          // bar label
  for (int i = 0; i < hp; i++) {       //##########
    mvwaddch(win,  max_y - 2, max_x - 11 + i, '#');
  }
  wrefresh(win);
}

// handle player actions and battle choices, return choice
int player_turn(WINDOW *select, WINDOW *game_text, pc *player, pc *monster, char *combat_prompt) {
  int choice = 2, player_damage = 0;
  
  num_choices = actions(player->role);
  choice = choose(select, num_choices, combat_prompt);
  switch (choice_key[choice]) {
    case 0: mvwprintw(game_text, 2, 1, "You swing at %s", monster->name);
            wrefresh(game_text);
            napms(250);
            player_damage = attack(player, monster);
            if (player_damage > 0) {
              mvwprintw(game_text, 3, 1, "You hit %s for %d damage!", monster->name, player_damage);
            } else {
              mvwprintw(game_text, 3, 1, "The %s dodges your strike.", monster->name);
            }
            if (monster->cur_hp <= 0) {
              mvwprintw(game_text, 6, 1, "You defeated %s, %s!", monster->name, player->name);
              player->coin+=monster->coin;
              player->xp+=monster->xp;
            }
            break;
    case 2: mvwprintw(game_text, 3, 1, "You run as fast as you can away from %s!", monster->name);
            break;
    default: break;
  }
  health_bar(game_text, monster);
  napms(250);

  return choice;
}

// handle npc actions and battle choices, return choice
// this will only return attack at first, but eventually will support other options
int npc_turn(WINDOW *game_text, pc *player, pc *monster) {
  int choice, damage = 0;
  
  choice = dice(1, 6) * 0;
  switch (choice) {
    case 0: mvwprintw(game_text, 5, 1, "%s tries to hit you.", monster->name);
            wrefresh(game_text);
            napms(250);
            damage = attack(monster, player);
            if (damage > 0) {
              mvwprintw(game_text, 6, 1, "%s hit you for %d damage!", monster->name, damage);
            } else {
              mvwprintw(game_text, 6, 1, "You dodge %s's ferocious strike.", monster->name);
            }
            if (player->cur_hp <= 0) {
              mvwprintw(game_text, 7, 1, "%s killed you, %s...", monster->name, player->name);
            }
            break;
    case 2: mvwprintw(game_text, 6, 1, "%s runs away!", monster->name);
            break;
    default: break;
  }
  wrefresh(game_text);
  napms(250);

  return choice;
}

void combat(WINDOW *game_text, WINDOW *select, WINDOW *stats, pc *player, int environ) {
  int choice, monster_roll;
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
  health_bar(game_text, &monster);
  
  while(1) { // battle loop
    // clear previous choices
    reset_choices();
    // We have our foe, now we fight until either one succumbs or you flee
    // roll to see who goes first - bonus to dex, int, wis, and dodge (good for rogues)
    // formula is d20 + mods > x = player goes first
    if ((dice(1, 20) + player->dodge + player->intel) > 10) { // help rogues and wizards not die
      // you get to go first this round!
      choice = player_turn(select, game_text, player, &monster, combat_prompt);
      if (choice_key[choice] == 2) break; // get out, you fled
      if (monster.cur_hp < 1) break; // you won!
      // now monster goes
      npc_turn(game_text, player, &monster);
      wrefresh(stats);
      if (player->cur_hp < 1) break; // you died, so sad
    } else {
      // monster goes first
      npc_turn(game_text, player, &monster);
      wrefresh(stats);
      if (player->cur_hp <= 0) break; // you died. later, call game over function
      // then player goes
      choice = player_turn(select, game_text, player, &monster, combat_prompt);
      if (choice_key[choice] == 2) break; // get out, you fled
      if (monster.cur_hp < 1) break; // you won!
    }
    //if (choice == 1) break; // exit combat loop, you escaped!
    wclear(game_text);
    health_bar(game_text, &monster);
    wrefresh(stats);
  }
}