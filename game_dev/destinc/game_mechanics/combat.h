// Functions related to combat
// selecting foe, handling battle rounds, etc.

#define AC_BASE 10
#define COMBAT_PROBABILITY 5 // dial it down for less monsters

// build list of combat actions for the player
int actions(pc *player) {
  int num_choices = 0;
  char weapon[64];

  // first option is to attack with whatever weapon (if any) is held in the main hand
  if (strcmp(player->worn_items[1].name, "- empty -") != 0) {
      snprintf(weapon, 64, "Attack with %s", player->worn_items[1].name);
      strncpy(choices[num_choices], weapon, MAX_CHOICE_LEN); choice_key[num_choices] = 0; num_choices++;
  } else {
    strncpy(choices[num_choices], "Attack with fists", MAX_CHOICE_LEN); choice_key[num_choices] = 0; num_choices++;
  }
  if (strcmp(player->role, "Cleric") == 0) {
        // set up options for Clerics
        strncpy(choices[num_choices], "Heal and Attack", MAX_CHOICE_LEN); choice_key[num_choices] = 200; num_choices++; // set second option as heal and attack
        strncpy(choices[num_choices], "Flee", MAX_CHOICE_LEN); choice_key[num_choices] = 2; num_choices++;            // set third option as attempt to flee
      }
      // need to create key for actions, ie. 0 = attack, 2 = flee, 7 = cast spell, etc.
      if (strcmp(player->role, "Paladin") == 0) {
        // set up options for Paladins
        if (player->cur_mana >= 4) {  // set second option as smite if player has enough mana
          strncpy(choices[num_choices], "Smite Foe", MAX_CHOICE_LEN);
          choice_key[num_choices] = 50;
          num_choices++;
        }
        strncpy(choices[num_choices], "Flee", MAX_CHOICE_LEN); choice_key[num_choices] = 2; num_choices++;             // set third option as attempt to flee
      }
      if (strcmp(player->role, "Rogue") == 0) {
        // set up options for Rogues
        if (player->cur_mana >= 3) {  // set second option as triple attack if player has enough mana
          strncpy(choices[num_choices], "Cunning Strike", MAX_CHOICE_LEN);
          choice_key[num_choices] = 55;
          num_choices++;
        }
        strncpy(choices[num_choices], "Flee", MAX_CHOICE_LEN); choice_key[num_choices] = 2; num_choices++;            // set third option as attempt to flee
      }
      if (strcmp(player->role, "Wizard") == 0) {
        // set up options for Wizards
        if (player->cur_mana >= 4) {  // set second option as magic missile if player has enough mana
          strncpy(choices[num_choices], "Magic missle [3d4+3]", MAX_CHOICE_LEN);
          choice_key[num_choices] = 100;
          num_choices++;
        }
        strncpy(choices[num_choices], "Fire bolt [1d10]", MAX_CHOICE_LEN); choice_key[num_choices] = 101; num_choices++;  // set third option as fire bolt
        strncpy(choices[num_choices], "Flee", MAX_CHOICE_LEN); choice_key[num_choices] = 2; num_choices++;            // set fourth option as attempt to flee
      }

  return num_choices;
}

// calculate if a given attack hits, and if so, for how much
// monsters are strong, so tweak as needed to make combat possible
int monster_attack(mob *attacker, pc *target) {
  int ac, damage, roll;

  // note - mob stat blocks include dex bonus (if any) in armor category
  roll = dice(1, 20) + attacker->to_hit;  // monster roll = d20 + to hit
  if ((target->worn_items[0].type == 0) || (target->worn_items[0].type == 6)) {                 // light or no armor
    ac = AC_BASE + target->dodge + target->worn_items[0].armor_val + ((target->dex - 10) / 2);  // Base AC + dodge + armor + dex bonus
  }
  if (target->worn_items[0].type == 1) {                                                        // medium armor - max +2 dex bonus
    ac = (AC_BASE + target->dodge + target->worn_items[0].armor_val) + ((((target->dex - 10) / 2) > 2) ? 2 : ((target->dex - 10) / 2));  // Base AC + dodge + armor + dex bonus
  }
  if (target->worn_items[0].type == 2) {                             // heavy armor
    ac = AC_BASE + target->dodge + target->worn_items[0].armor_val;  // Base AC + dodge + armor
  }
  // check for shield
  if (strcmp(target->worn_items[2].name, "- empty -") != 0) {
    ac+=target->worn_items[2].armor_val;  // add shield AC
  }
  damage = dice(attacker->dice_num, attacker->dice_dam) + attacker->dmg; // number of dice, type of dice, +dmg
  // now handle buffs which may modify these numbers a bit
  if (target->buffs[2] == 1) {               // check for player buff
    if ((strcmp(target->role, "Rogue") == 0) || (strcmp(target->role, "Wizard") == 0)) {        // Rogue and Wizard class buff
      ac+=2;                                                               // + AC - maybe these scale later?
      damage-=dice(1, 2) + 1;                                              // small damage reduction
    }
    if ((strcmp(target->role, "Cleric") == 0) || (strcmp(target->role, "Paladin") == 0)) {       // Cleric and Paladin buff for praying
      ac+=1;                                                               // + AC - maybe these scale later?
      damage-=dice(1, 2);                                                  // tiny damage reduction
    }
  }
  
  if (roll >= ac ) { // check if attacker rolled greater than or equal to target AC
    target->cur_hp-=damage;
  } else {
    damage = 0;
  }

  return damage; // later, find a way to reflect damage absorption. For now, less than 1 means they missed
}

int player_attack(pc *attacker, mob *target) {
  int ac, damage, roll;

  // check for finesse weapon and higher dex than str
  if ((attacker->worn_items[1].finesse == 1) && (attacker->dex >= attacker->str)) {
    roll = dice(1, 20) + attacker->to_hit + ((attacker->dex - 10) / 2);                                 // use dex to hit for finesse
    damage = dice(attacker->worn_items[1].dice_num, attacker->worn_items[1].dmg_dice) + ((attacker->dex - 10) / 2); // dex for damage for finesse
  } else { // now go off strength and make sure they are holding a weapon!
    roll = dice(1, 20) + attacker->to_hit + ((attacker->str - 10) / 2);                                 // str to hit unless finesse
    if (strcmp(attacker->worn_items[1].name, "- empty -") == 0) {
      damage = dice(1, 2) + ((attacker->str - 10) / 2);                                                 // bare hands!
    } else {
      damage = dice(attacker->worn_items[1].dice_num, attacker->worn_items[1].dmg_dice) + ((attacker->str - 10) / 2); // str for damage unless finesse
    }
  }
  if (attacker->buffs[2] == 1) {                          // check for player buff
    if ((strcmp(attacker->role, "Cleric") == 0) || (strcmp(attacker->role, "Paladin") == 0)) {          // Cleric and Paladin buff for praying
      roll+=1;                                                               // tiny boost to roll
      damage+=dice(1, 2);                                                    // minor damage boost
    }
    if (strcmp(attacker->role, "Rogue") == 0) {          // Rogues get a decent boost to combat
      roll+=2;                                                               // boost to roll - tweak if too much!
      damage+=dice(1, 4);                                                    // damage boost - tweak if too much!
    }
  }
  // note - mob stat blocks include dex bonus (if any) included in armor attribute
  ac = AC_BASE + target->armor;     // Base AC + armor for monsters
  
  if (roll >= ac ) { // check if attacker rolled greater than or equal to target AC
    target->cur_hp-=damage;
  } else {
    damage = 0;
  }

  return damage; // later, find a way to reflect damage absorption. For now, less than 1 means they missed
}

// pass window to draw health bar and what entity (monster, etc.)
void health_bar(WINDOW *win, int cur_hp, int max_hp, int is_pc, char name[32]) {
  int hp, max_y, max_x, y, x;

  getmaxyx(win, max_y, max_x);
  // where the bar goes depends on the entity
  if (is_pc == 1) {
    y = max_y - 6; 
    x = max_x - 11;
  } else {
    y = max_y - 3;
    x = max_x - 11;
  }
  hp = ((float) cur_hp / max_hp * 10); // get amount of health
  if (cur_hp > 0 && hp < 1) hp = 1; // need at least one # if mob is still alive

  // we want to print a # for roughly every 10% of health
  // then make missing health turn red, other ones green
  wattron(win, COLOR_PAIR(5) | A_BOLD);
  mvwaddstr(win, max_y - 7, x, "__Health__");          // bar label
  wattroff(win, COLOR_PAIR(5) | A_BOLD);
  
  // now print health markers in either green or red depending on health
  if (hp > 5) {
    wattron(win, COLOR_PAIR(7) | A_BOLD);
    for (int i = 0; i < hp; i++) mvwaddch(win,  y + 1, x + i, '#');
    wattroff(win, COLOR_PAIR(7) | A_BOLD);
  } else {
    wattron(win, COLOR_PAIR(1) | A_BOLD);
    for (int i = 0; i < hp; i++) mvwaddch(win,  y + 1, x + i, '#');
    wattroff(win, COLOR_PAIR(1) | A_BOLD);
  }
  wattron(win, COLOR_PAIR(6) | A_BOLD);
  mvwprintw(win, y + 2, x, "  %s  ", name);        // bar label
  wattroff(win, COLOR_PAIR(6) | A_BOLD);
  wrefresh(win);
}

// handle player actions and battle choices, return choice
int player_turn(WINDOW *select, WINDOW *game_text, WINDOW *stats, pc *player, mob *monster, char *combat_prompt) {
  int choice = 2, heal_amt = 0, player_damage = 0;

  wclear(game_text);  // clear the window and take the turn
  mvwprintw(game_text, 0, 0, "%s's turn...", player->name);
  health_bar(game_text, player->cur_hp, player->max_hp, 1, player->name);
  health_bar(game_text, monster->cur_hp, monster->max_hp, 1, monster->name);
  
  num_choices = actions(player);
  choice = choose(select, num_choices, combat_prompt);
  switch (choice_key[choice]) {
    case 0: mvwprintw(game_text, 2, 0, "You swing at %s", monster->name);
            wrefresh(game_text);
            napms(250);
            player_damage = player_attack(player, monster);
            if (player_damage > 0) { // move this into attack function?
              wattron(game_text, COLOR_PAIR(7) | A_BOLD);
              mvwprintw(game_text, 4, 0, "You hit %s for %d damage!", monster->name, player_damage);
              wattroff(game_text, COLOR_PAIR(7) | A_BOLD);
            } else {
              wattron(game_text, COLOR_PAIR(1) | A_BOLD);
              mvwprintw(game_text, 4, 0, "The %s dodges your strike.", monster->name);
              wattroff(game_text, COLOR_PAIR(1) | A_BOLD);
            }
            break;
    case 2: mvwprintw(game_text, 2, 0, "You run as fast as you can away from %s!", monster->name);
            break;
    case 50:  player_damage = dice(4, 4) + 4;  // later this will scale with higher levels
              wattron(game_text, COLOR_PAIR(7) | A_BOLD);
              mvwprintw(game_text, 2, 0, "Calling upon the Divine, you smite %s with righteous fury! Doing %d damage.", monster->name, player_damage);
              wattroff(game_text, COLOR_PAIR(7) | A_BOLD);
              monster->cur_hp-=player_damage;
              player->cur_mana-=4;
              break;
    case 55:  player_damage = dice(4, 4) + 5;  // later this will scale with higher levels
              wattron(game_text, COLOR_PAIR(7) | A_BOLD);
              mvwprintw(game_text, 2, 0, "You leap around the %s and strike! You did %d damage.", monster->name, player_damage);
              wattroff(game_text, COLOR_PAIR(7) | A_BOLD);
              monster->cur_hp-=player_damage;
              player->cur_mana-=3;
              break;
    case 100: player_damage = dice(3, 4) + 3;  // later this will scale with higher levels (spell slots)
              wattron(game_text, COLOR_PAIR(7) | A_BOLD);
              mvwprintw(game_text, 2, 0, "3 shimmering darts appear and fly toward %s! You did %d damage.", monster->name, player_damage);
              wattroff(game_text, COLOR_PAIR(7) | A_BOLD);
              monster->cur_hp-=player_damage;
              player->cur_mana-=4;
              break;
    case 101: mvwprintw(game_text, 2, 0, "You hurl a mote of fire at %s!", monster->name);
              napms(250);
              // this is a cantrip. It costs no mana, but it can miss...
              if ((dice(1, 20) + player->to_hit + ((player->intel - 10) / 2)) >= (AC_BASE + monster->armor)) {
                player_damage = dice(1, 10);  // later this will scale with higher levels
                wattron(game_text, COLOR_PAIR(7) | A_BOLD);
                mvwprintw(game_text, 2, 0, "Direct hit! Your firebolt strikes %s for %d damage.", monster->name, player_damage);
                wattroff(game_text, COLOR_PAIR(7) | A_BOLD);
                monster->cur_hp-=player_damage;
              } else {  // you missed!
                wattron(game_text, COLOR_PAIR(1) | A_BOLD);
                mvwprintw(game_text, 2, 0, "You concentrate hard, but at the last second, the %s dodges the bolt!", monster->name);
                wattroff(game_text, COLOR_PAIR(1) | A_BOLD);
              }
              break;
    case 200: heal_amt = (dice(1, 8)) + (calc_mod(player->wis)) + 2; // +2 from Life Domain. Later, also use higher level slots.
              //heal_amt = (dice(1, 8) * player->lvl) + ((player->wis - 10) / 2);
              wattron(game_text, COLOR_PAIR(7) | A_BOLD);
              mvwprintw(game_text, 2, 0, "Praying intently, you add %d health points as you prepare to strike.", heal_amt);
              wattroff(game_text, COLOR_PAIR(7) | A_BOLD);
              player->cur_hp+=heal_amt;
              player->cur_mana-=4;
              mvwprintw(game_text, 3, 0, "You swing at %s", monster->name);
              wrefresh(game_text);
              napms(250);
              player_damage = player_attack(player, monster);
              if (player_damage > 0) { // move this into attack function?
                wattron(game_text, COLOR_PAIR(7) | A_BOLD);
                mvwprintw(game_text, 4, 0, "You hit %s for %d damage!", monster->name, player_damage);
                wattroff(game_text, COLOR_PAIR(7) | A_BOLD);
              } else {
                wattron(game_text, COLOR_PAIR(1) | A_BOLD);
                mvwprintw(game_text, 4, 0, "The %s dodges your strike.", monster->name);
                wattroff(game_text, COLOR_PAIR(1) | A_BOLD);
              }
            break;
    default: break;
  }
  if (monster->cur_hp <= 0) {
    wattron(game_text, COLOR_PAIR(7) | A_BOLD);
    mvwprintw(game_text, 6, 0, "You defeated %s, %s!", monster->name, player->name);
    wattroff(game_text, COLOR_PAIR(7) | A_BOLD);
    player->coin+=monster->coin;
    player->xp+=monster->xp;
  }
  refresh_stats(stats, player); // update stats window
  health_bar(game_text, player->cur_hp, player->max_hp, 1, player->name);
  health_bar(game_text, monster->cur_hp, monster->max_hp, 1, monster->name);
  wrefresh(game_text);
  wclear(select);         // stop after turn is complete so player can see results of their turn
  mvwaddstr(select, 0, 0, "Press any key to continue...");
  wrefresh(select);
  getch();

  return choice;
}

// handle npc actions and battle choices, return choice
// this will only return attack at first, but eventually will support other options
int npc_turn(WINDOW *select, WINDOW *game_text, WINDOW *stats, pc *player, mob *monster) {
  int choice, damage = 0;

  wclear(game_text);  // clear the window and take the turn
  mvwprintw(game_text, 0, 0, "%s's turn...", monster->name);
  health_bar(game_text, player->cur_hp, player->max_hp, 1, player->name);
  health_bar(game_text, monster->cur_hp, monster->max_hp, 1, monster->name);
  
  choice = dice(1, 6) * 0;
  switch (choice) {
    case 0: mvwprintw(game_text, 2, 0, "%s tries to hit you.", monster->name);
            wrefresh(game_text);
            napms(250);
            damage = monster_attack(monster, player);
            if (damage > 0) {
              wattron(game_text, COLOR_PAIR(1) | A_BOLD);
              mvwprintw(game_text, 4, 0, "%s hit you for %d damage!", monster->name, damage);
              wattroff(game_text, COLOR_PAIR(1) | A_BOLD);
              refresh_stats(stats, player); // update stats window
              health_bar(game_text, player->cur_hp, player->max_hp, 1, player->name);
            } else {
              wattron(game_text, COLOR_PAIR(7) | A_BOLD);
              mvwprintw(game_text, 4, 0, "You dodge %s's ferocious strike.", monster->name);
              wattroff(game_text, COLOR_PAIR(7) | A_BOLD);
            }
            if (player->cur_hp <= 0) {
              wattron(game_text, COLOR_PAIR(1) | A_BOLD);
              mvwprintw(game_text, 6, 0, "%s killed you, %s...", monster->name, player->name);
              wattroff(game_text, COLOR_PAIR(1) | A_BOLD);
            }
            break;
    case 2: mvwprintw(game_text, 2, 0, "%s runs away!", monster->name);
            break;
    default: break;
  }
  wrefresh(game_text);
  wclear(select);         // stop after turn is complete so player can see results of monster's turn
  mvwaddstr(select, 0, 0, "Press any key to continue...");
  wrefresh(select);
  getch();

  return choice;
}

int combat(WINDOW *game_text, WINDOW *select, WINDOW *stats, pc *player, int environ) {
  int choice, init_mob, init_player, monster_roll, result = 2; // result 2: you fled  1: you won  13: you died
  mob monster;        // create struct for monster
  char combat_prompt[96];

  snprintf(combat_prompt, 95, "What will you do now, %s?", player->name);

  // roll for foe - by environ (different mobs live in different places)
  // 0 is dungeon, etc.
  switch(environ) { // ok, I am cheating a bit here and leveraging the environ variable to differentiate between regular and boss mobs
    case 0: monster_roll = dice(1, MOBS) - 1; monster = mobs[monster_roll]; break; // generate regular monster 
    case 1: monster_roll = dice(1, BOSS) - 1; monster = bosses[monster_roll]; break; // generate boss monster 
    default: monster_roll = dice(1, MOBS) - 1; break;  // dice never return 0 so subtract one for proper array indexing
  }
  // switch(environ) { // ok, I am cheating a bit here and leveraging the environ variable to differentiate between regular and boss mobs
  //   case 0: monster_roll = dice(1, MOBS) - 1; build_character(mobs[monster_roll].name, mobs[monster_roll], &monster); break;// generate foe break;   // 4 choices, so roll 4 sided die       |  Need to fix later to support both
  //   case 1: monster_roll = dice(1, BOSS) - 1; build_character(bosses[monster_roll].name, bosses[monster_roll], &monster); break;// generate foe break; 
  //   default: monster_roll = dice(1, MOBS) - 1; break;  // dice never return 0 so subtract one for proper array indexing
  // }

  wclear(select);
  wrefresh(select);
  mvwprintw(game_text, 4, 0, "%s", monster.desc);
  mvwaddstr(select, 0, 0, "Press any key to begin combat!");
  wrefresh(game_text);
  wrefresh(select);
  getch();
  wclear(game_text);
  health_bar(game_text, player->cur_hp, player->max_hp, 1, player->name);
  health_bar(game_text, monster->cur_hp, monster->max_hp, 1, monster->name);

  init_mob = ((monster.dex - 10) / 2) + monster.dodge;
  init_player = ((player->dex - 10) / 2) + player->dodge; // tweak this later, wizard buffs, etc.
  if (player->buffs[2] == 1) init_player+=4;              // bonus for having class buff active - wizard is super squishy soloing
                                                          // need to come up with better way to buff them
  while(1) { // battle loop
    // clear previous choices
    reset_choices();
    // We have our foe, now we fight until either one succumbs or you flee
    // roll to see who goes first - bonus to dex, int, wis, and dodge (good for rogues)
    // formula is d20 + mods > x = player goes first
    if ((dice(1, 20) + init_player) >= (dice(1, 20) + init_mob)) { // determine turn order
      // you get to go first this round!
      choice = player_turn(select, game_text, stats, player, &monster, combat_prompt);
      if (choice_key[choice] == 2) break; // get out, you fled
      if (monster.cur_hp < 1) {
        result = 1;
        break; // you won!
      }
      // now monster goes
      npc_turn(select, game_text, stats, player, &monster);
      if (player->cur_hp < 1) {
        result = 13;
        break; // you died, so sad
      }
    } else {
      // monster goes first
      npc_turn(select, game_text, stats, player, &monster);
      if (player->cur_hp <= 0) {
        result = 13;
        break; // you died. later, call game over function
      }
      // then player goes
      choice = player_turn(select, game_text, stats, player, &monster, combat_prompt);
      if (choice_key[choice] == 2) break; // get out, you fled
      if (monster.cur_hp < 1) {
        result = 1;
        break; // you won!
      }
    }
    wclear(game_text);
  }
  wclear(game_text);
  wattron(game_text, COLOR_PAIR(4));

  return result;
}