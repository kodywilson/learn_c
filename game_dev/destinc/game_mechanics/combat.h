// Functions related to combat
// selecting foe, handling battle rounds, etc.

#define AC_BASE 10
#define COMBAT_PROBABILITY 5 // dial it down for less monsters

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

// calculate if a given attack hits, and if so, for how much
// mobs are super strong, so tweak as needed to make combat possible
int attack(mob *attacker, mob *target) {
  int ac, damage, roll;

  // note - mob stat blocks include dex bonus (if any) in armor category so I set all mobs to have 10 or less dex
  // later, add more attributes so I can tell player from monster and then conditional off that...
  if ( attacker->is_pc == 1 ) { // first we handle when attacker is pc
    if (strcmp(attacker->role, "Rogue") == 0) { // to hit roll
      roll = dice(1, 20) + attacker->to_hit + ((attacker->dex - 10) / 2); // use dex to hit for rogue
      damage = dice(attacker->dice_num, attacker->dice_dam) + attacker->dmg + ((attacker->dex - 10) / 2); // dex for damage for rogue
    } else {
      roll = dice(1, 20) + attacker->to_hit + ((attacker->str - 10) / 2); // str to hit for everyone else
      damage = dice(attacker->dice_num, attacker->dice_dam) + attacker->dmg + ((attacker->str - 10) / 2); // str for damage for non rogues
    }
    ac = AC_BASE + target->armor;     // Base AC + armor for monsters // later may add mods
  } else { // monster is attacker, use different formulas
    roll = dice(1, 20) + attacker->to_hit;  // monster roll = d20 + to hit
    if (strcmp(attacker->role, "Rogue") == 0 || strcmp(attacker->role, "Wizard") == 0) {
      ac = AC_BASE + target->dodge + target->armor + ((target->dex - 10) / 2);  // Base AC + dodge + armor + dex bonus
    } else { // non rogue/wizard
      ac = AC_BASE + target->dodge + target->armor;     // Base AC + dodge + armor
    }
    damage = dice(attacker->dice_num, attacker->dice_dam) + attacker->dmg; // number of dice, type of dice, +dmg
  }
  
  if (roll >= ac ) { // may need to drop the damage bonus and only use for to hit
    target->cur_hp-=damage;
  } else {
    damage = 0;
  }

  return damage; // later, find a way to reflect damage absorption. For now, less than 1 means they missed
}

// pass window to draw health bar and what entity (monster, etc.)
void health_bar(WINDOW *win, mob *entity) {
  int hp, max_y, max_x;

  getmaxyx(win, max_y, max_x);
  hp = ((float) entity->cur_hp / entity->max_hp * 10); // get amount of health
  if (entity->cur_hp > 0 && hp < 1) hp = 1; // need at least one # if mob is still alive

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
int player_turn(WINDOW *select, WINDOW *game_text, mob *player, mob *monster, char *combat_prompt) {
  int choice = 2, player_damage = 0;

  wclear(game_text);  // clear the window and take the turn
  mvwprintw(game_text, 0, 0, "%s's turn...", player->name);
  health_bar(game_text, monster);
  
  num_choices = actions(player->role);
  choice = choose(select, num_choices, combat_prompt);
  switch (choice_key[choice]) {
    case 0: mvwprintw(game_text, 2, 0, "You swing at %s", monster->name);
            wrefresh(game_text);
            napms(250);
            player_damage = attack(player, monster);
            if (player_damage > 0) {
              mvwprintw(game_text, 4, 0, "You hit %s for %d damage!", monster->name, player_damage);
              health_bar(game_text, monster);
            } else {
              mvwprintw(game_text, 4, 0, "The %s dodges your strike.", monster->name);
            }
            if (monster->cur_hp <= 0) {
              mvwprintw(game_text, 6, 0, "You defeated %s, %s!", monster->name, player->name);
              player->coin+=monster->coin;
              player->xp+=monster->xp;
            }
            wrefresh(game_text);
            wclear(select);         // stop after turn is complete so player can see results of their turn
            mvwaddstr(select, 0, 0, "Press any key to continue...");
            wrefresh(select);
            getch();
            break;
    case 2: mvwprintw(game_text, 2, 0, "You run as fast as you can away from %s!", monster->name);
            break;
    default: break;
  }

  return choice;
}

// handle npc actions and battle choices, return choice
// this will only return attack at first, but eventually will support other options
int npc_turn(WINDOW *select, WINDOW *game_text, WINDOW *stats, mob *player, mob *monster) {
  int choice, damage = 0;

  wclear(game_text);  // clear the window and take the turn
  mvwprintw(game_text, 0, 0, "%s's turn...", monster->name);
  health_bar(game_text, monster);
  
  choice = dice(1, 6) * 0;
  switch (choice) {
    case 0: mvwprintw(game_text, 2, 0, "%s tries to hit you.", monster->name);
            wrefresh(game_text);
            napms(250);
            damage = attack(monster, player);
            if (damage > 0) {
              mvwprintw(game_text, 4, 0, "%s hit you for %d damage!", monster->name, damage);
              refresh_stats(stats, player); // update stats window
            } else {
              mvwprintw(game_text, 4, 0, "You dodge %s's ferocious strike.", monster->name);
            }
            if (player->cur_hp <= 0) {
              mvwprintw(game_text, 6, 0, "%s killed you, %s...", monster->name, player->name);
            }
            wrefresh(game_text);
            wclear(select);         // stop after turn is complete so player can see results of monster's turn
            mvwaddstr(select, 0, 0, "Press any key to continue...");
            wrefresh(select);
            getch();
            break;
    case 2: mvwprintw(game_text, 2, 0, "%s runs away!", monster->name);
            break;
    default: break;
  }

  return choice;
}

void combat(WINDOW *game_text, WINDOW *select, WINDOW *stats, mob *player, int environ) {
  int choice, init_mob, init_player, monster_roll;
  mob monster;        // create struct for monster
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
  mvwprintw(game_text, 0, 0, "%s", monster.desc);
  mvwaddstr(select, 0, 0, "Press any key to begin combat!");
  wrefresh(game_text);
  wrefresh(select);
  getch();
  wclear(game_text);
  health_bar(game_text, &monster);

  init_mob = ((monster.dex - 10) / 2) + monster.dodge;
  init_player = ((player->dex - 10) / 2) + player->dodge; // tweak this later, wizard buffs, etc.
  
  while(1) { // battle loop
    // clear previous choices
    reset_choices();
    // We have our foe, now we fight until either one succumbs or you flee
    // roll to see who goes first - bonus to dex, int, wis, and dodge (good for rogues)
    // formula is d20 + mods > x = player goes first
    if ((dice(1, 20) + init_player) >= (dice(1, 20) + init_mob)) { // determine turn order
      // you get to go first this round!
      choice = player_turn(select, game_text, player, &monster, combat_prompt);
      if (choice_key[choice] == 2) break; // get out, you fled
      if (monster.cur_hp < 1) break; // you won!
      // now monster goes
      npc_turn(select, game_text, stats, player, &monster);
      refresh_stats(stats, player); // update stats window
      if (player->cur_hp < 1) break; // you died, so sad
    } else {
      // monster goes first
      npc_turn(select, game_text, stats, player, &monster);
      refresh_stats(stats, player); // update stats window
      if (player->cur_hp <= 0) break; // you died. later, call game over function
      // then player goes
      choice = player_turn(select, game_text, player, &monster, combat_prompt);
      if (choice_key[choice] == 2) break; // get out, you fled
      if (monster.cur_hp < 1) break; // you won!
    }
    //if (choice == 1) break; // exit combat loop, you escaped!
    //health_bar(game_text, &monster);
    //wrefresh(stats);
    wclear(game_text);
  }
  wclear(game_text);
}