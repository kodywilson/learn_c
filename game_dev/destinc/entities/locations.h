// game locations - town, dungeon, tavern, etc.
// each location will start with a list of options

#define ARMORY 4            // number of options in armory
#define TOWN 5              // number of options in town
#define TAVERN 4            // number of options in tavern
#define MAP_Y 12            // size of dungeon in rows
#define MAP_X 12            // size of dungeon in columns

// These lists are used with the xxxxxx_choices() functions to build menus
// Town
char *town_list[TOWN] = {"The Armory", "Ye Olde Tavern", "The Dungeon", "View Character", "Exit Game"};

// Tavern
// base list, later add options depending on class, quest, etc.
char *tavern_list[TAVERN] = {"Order some food", "Buy a drink", "Rest", "Leave the tavern"};

// Armory
char *armory_list[ARMORY] = {"Look at armor", "Look at weapons", "Look at shields", "Leave the armory"};

// these functions use the lists above to present options to the player
int armory_choices() {
  int num_choices = 0;

  for (int i = 0; i < ARMORY; i++) {
    strncpy(choices[num_choices], armory_list[i], MAX_CHOICE_LEN); choice_key[num_choices] = num_choices; num_choices++;
  }

  return num_choices;
}

int town_choices() {
  int num_choices = 0;

  for (int i = 0; i < TOWN; i++) {
    strncpy(choices[num_choices], town_list[i], MAX_CHOICE_LEN); choice_key[num_choices] = num_choices; num_choices++;
  }

  return num_choices;
}

int tavern_choices() {
  int num_choices = 0;

  for (int i = 0; i < TAVERN; i++) {
    strncpy(choices[num_choices], tavern_list[i], MAX_CHOICE_LEN); choice_key[num_choices] = num_choices; num_choices++;
  }

  return num_choices;
}

int view_and_buy(WINDOW *game_text, WINDOW *select, int coin, item viewing) {
  int choice, num_choices;

  // First show item stats
  wclear(game_text);
  wattron(game_text, COLOR_PAIR(5) | A_BOLD);
  mvwprintw(game_text, 0, 0, "---==| Viewing: %s |==---", viewing.name);
  wattroff(game_text, COLOR_PAIR(5) | A_BOLD);
  wattron(game_text, COLOR_PAIR(6) | A_BOLD);
  mvwprintw(game_text, 0, 7, "Viewing: %s", viewing.name);
  wattroff(game_text, COLOR_PAIR(6) | A_BOLD);
  mvwaddstr(game_text, 1, 0, "          ");
  wattron(game_text, COLOR_PAIR(5));  // later show certain things based on armor vs. weapon
  mvwprintw(game_text, 2, 0, "Description:  %s", viewing.desc);
  mvwaddstr(game_text, 3, 0, "          ");
  mvwprintw(game_text, 4, 0, "Armor:  %d", viewing.armor_val);
  mvwprintw(game_text, 5, 0, "Damage: %dd%d", viewing.dice_num, viewing.dmg_dice);
  mvwaddstr(game_text, 6, 0, "          ");
  mvwprintw(game_text, 7, 0, "Cost:  %d", viewing.cost);
  wattroff(game_text, COLOR_PAIR(5));
  wrefresh(game_text);
  // determine if the player can afford the armor
  if (coin >= viewing.cost) {
    reset_choices();
    num_choices = y_n();
    choice = choose(select, num_choices, "Would you like to purchase this item?");
  } else {
    wrefresh(game_text);
    wclear(select);
    mvwaddstr(select, 0, 0, "Press any key to continue...");
    wrefresh(select);
    getch();
    choice = 1;
  }

  return choice;
}

// you are visiting the armory
void armory(WINDOW *game_text, WINDOW *select, WINDOW *stats, mob *player) {
  int choice, armor_limit; // these limits are how we tune what options appear for each player
  char armory_prompt[96];  // for instance, a Knight will see all armors as available while a cleric only light and medium, etc.
  item viewing;

  snprintf(armory_prompt, 95, "What gear would you like to view, %s?", player->name);
  if (strcmp(player->role, "Wizard") == 0) armor_limit = 1;
  if (strcmp(player->role, "Rogue") == 0) armor_limit = 4;
  if (strcmp(player->role, "Cleric") == 0) armor_limit = 9;
  if (strcmp(player->role, "Knight") == 0) armor_limit = ALL_ARMOR; // knights have no armor restrictions

  wclear(game_text);
  mvwaddstr(game_text, 0, 0, "You enter Owen's Armory. The loud clanging from the back of the shop stops and then Owen appears from the back.");
  mvwaddstr(game_text, 1, 0, "Owen wipes his hands on a rag and asks 'How can I help you?'");
  wrefresh(game_text);
  while(1) {
    //getch(); // DEBUG
    viewing = empty_slot;
    reset_choices();
    num_choices = armory_choices();
    choice = choose(select, num_choices, armory_prompt);
    wclear(game_text);
    switch (choice) {
      case 0: wclear(game_text);
              mvwprintw(game_text, 0, 0, "Excellent, %s, these are the available armors for a %s such as yourself.", player->name, player->role);
              mvwaddstr(game_text, 1, 0, "          ");
              num_choices = 0;
              reset_choices();
              strncpy(choices[num_choices], "Keep browsing...", MAX_CHOICE_LEN);
              num_choices++;
              for (int i = 0; i < armor_limit; i++) {
                mvwprintw(game_text, 2 + i, 0, "[%d]: %s", i + 1, armors[i].name);
                strncpy(choices[num_choices], armors[i].name, MAX_CHOICE_LEN);
                choice_key[num_choices] = i;
                num_choices++;
              }
              wrefresh(game_text);
              wclear(game_text);
              if (num_choices > 1) {
                choice = choose(select, num_choices, "Please choose: ");
                if (choice == 0) {
                  mvwprintw(game_text, 0, 0, "Right on, %s, thanks for looking.", player->name);
                } else {
                  viewing = armors[choice_key[choice]];
                  if ((view_and_buy(game_text, select, player->coin, viewing)) == 0) {
                    wclear(game_text);
                    mvwprintw(game_text, 0, 0, "Buying %s and moving it to your backpack.", viewing.name);
                    player->coin-=viewing.cost;
                    for (int i = 0; i < BAG_SLOTS; i++) {
                      if (strcmp(player->backpack[i].name, "- empty -") == 0) {
                        player->backpack[i] = viewing; // move bought item to first open slot in backpack
                        break; // exit loop
                      }
                    }
                  } else {
                    wclear(game_text);
                    mvwprintw(game_text, 0, 0, "Ok, how else can I help you, %s?", player->name);
                  }
                }
              } else {
                mvwprintw(game_text, 0, 0, "%s, it doesn't look like we have an armor option for you...", player->name);
              }

              wrefresh(game_text);
              wclear(select);
              mvwaddstr(select, 0, 0, "Press any key to continue...");
              wrefresh(select);
              getch();
              break;
      case 1: wclear(game_text);
              mvwprintw(game_text, 0, 0, "Excellent, %s, these are the available weapons for a %s such as yourself.", player->name, player->role);
              mvwaddstr(game_text, 1, 0, "          ");
              num_choices = 0;
              reset_choices();
              strncpy(choices[num_choices], "Keep browsing...", MAX_CHOICE_LEN);
              num_choices++;
              for (int i = 0; i < ALL_WEAPONS; i++) {
                if (i < 14) mvwprintw(game_text, 2 + i, 0, "[%d]: %s", i + 1, weapons[i].name);
                if (i >= 14) mvwprintw(game_text, 2 + i - 14, 50, "[%d]: %s", i + 1, weapons[i].name);
                // later fix this to only show weapons the player class can actually use
                strncpy(choices[num_choices], weapons[i].name, MAX_CHOICE_LEN);
                choice_key[num_choices] = i;
                num_choices++;
              }
              wrefresh(game_text);
              wclear(game_text);
              if (num_choices > 1) {
                choice = choose(select, num_choices, "Please choose: ");
                if (choice == 0) {
                  mvwprintw(game_text, 0, 0, "Right on, %s, thanks for looking.", player->name);
                } else {
                  mvwprintw(game_text, 0, 0, "Buying %s and moving it to your backpack.", weapons[choice_key[choice]].name);
                  player->coin-=weapons[choice_key[choice]].cost;
                  for (int i = 0; i < BAG_SLOTS; i++) {
                    if (strcmp(player->backpack[i].name, "- empty -") == 0) {
                      player->backpack[i] = weapons[choice_key[choice]]; // move bought item to first open slot in backpack
                      break; // exit loop
                    }
                  }
                }
              } else {
                mvwprintw(game_text, 0, 0, "%s, it doesn't look like we have a weapon option for you...", player->name);
              }
              wrefresh(game_text);
              wclear(select);
              mvwaddstr(select, 0, 0, "Press any key to continue...");
              wrefresh(select);
              getch();
              break;
      case 2: wclear(game_text);
              if (strcmp(player->role, "Rogue") == 0 || strcmp(player->role, "Wizard") == 0) {
                mvwprintw(game_text, 0, 0, "Sorry, %s, %s's cannot use shields.", player->name, player->role);
              } else {
                mvwprintw(game_text, 0, 0, "Excellent, %s, these are the available shields for a %s such as yourself.", player->name, player->role);
                mvwaddstr(game_text, 1, 0, "          ");
                num_choices = 0;
                reset_choices();
                strncpy(choices[num_choices], "Keep browsing...", MAX_CHOICE_LEN);
                num_choices++;
                for (int i = 0; i < ALL_SHIELDS; i++) {
                  if (i < 14) mvwprintw(game_text, 2 + i, 0, "[%d]: %s", i + 1, shields[i].name);
                  if (i >= 14) mvwprintw(game_text, 2 + i - 14, 50, "[%d]: %s", i + 1, shields[i].name);
                  strncpy(choices[num_choices], shields[i].name, MAX_CHOICE_LEN);
                  choice_key[num_choices] = i;
                  num_choices++;
                }
                wrefresh(game_text);
                wclear(game_text);
                if (num_choices > 1) {
                  choice = choose(select, num_choices, "Please choose: ");
                  if (choice == 0) {
                    mvwprintw(game_text, 0, 0, "Right on, %s, thanks for looking.", player->name);
                  } else {
                    mvwprintw(game_text, 0, 0, "Buying %s and moving it to your backpack.", shields[choice_key[choice]].name);
                    player->coin-=shields[choice_key[choice]].cost;
                    for (int i = 0; i < BAG_SLOTS; i++) {
                      if (strcmp(player->backpack[i].name, "- empty -") == 0) {
                        player->backpack[i] = shields[choice_key[choice]]; // move bought item to first open slot in backpack
                        break; // exit loop
                      }
                    }
                  }
                } else {
                  mvwprintw(game_text, 0, 0, "%s, it doesn't look like we have a shield option for you...", player->name);
                }
              }
              wrefresh(game_text);
              wclear(select);
              mvwaddstr(select, 0, 0, "Press any key to continue...");
              wrefresh(select);
              getch();
              break;break;
      case 3: mvwaddstr(game_text, 1, 1, "You finish your business with Owen and head back to the town center."); break;
      default: break;
    }
    refresh_stats(stats, player); // update stats window
    wrefresh(game_text);
    napms(250);
    if (choice == 3) break; // end armory loop
  }
  wclear(select);
  mvwaddstr(select, 0, 0, "Press any key to continue...");
  wrefresh(select);
  getch();
}

// you are visiting the tavern
void tavern(WINDOW *game_text, WINDOW *select, WINDOW *stats, mob *player) {
  int choice, drink_cost, food_cost, rest_cost;
  char tavern_prompt[96];

  drink_cost = player->lvl * 1;  // tweak these at some point
  food_cost  = player->lvl * 1;  // later this will give buff, for now restore health
  rest_cost  = player->lvl * 2;  // later this will give buff, for now restore mana

  snprintf(tavern_prompt, 95, "What would you like to do in the tavern, %s?", player->name);

  wclear(game_text);
  mvwaddstr(game_text, 1, 1, "You enter the tavern. The air is thick with smoke, but the fire in the hearth is warm and inviting.");
  wrefresh(game_text);
  while(1) {
    //getch(); // DEBUG
    reset_choices();
    num_choices = tavern_choices();
    choice = choose(select, num_choices, tavern_prompt);
    wclear(game_text);
    switch (choice) {
      case 0: if (player->coin >= food_cost) {
        mvwaddstr(game_text, 1, 1, tavern_table);
        player->cur_hp+= dice(2, (player->max_hp / 2)) * player->lvl; // food restores some health and adds buff
        if (player->cur_hp > player->max_hp * player->lvl) player->cur_hp = player->max_hp * player->lvl;
        player->buffs[0] = 1;  // this buff lasts through one dungeon trip - chance to restore health
        player->coin-=food_cost;  // pay for food
      } else {
        mvwaddstr(game_text, 1, 1, "You can't afford a meal! Go to the dungeon and earn some money!");
      } break;
      case 1: if (player->coin >= drink_cost) {
        mvwaddstr(game_text, 1, 1, tavern_bar);
        player->cur_mana+= dice(2, (player->max_mana / 2)) * player->lvl; // drink restores some mana and adds buff
        if (player->cur_mana > player->max_mana * player->lvl) player->cur_mana = player->max_mana * player->lvl;
        player->buffs[1] = 1;  // this buff lasts through one dungeon trip - chance to restore mana
        player->coin-=drink_cost;  // pay for drink
      } else {
        mvwaddstr(game_text, 1, 1, "You can't afford wine, you churl! Go to the dungeon and earn some money!");
      } break;
      case 2: if (player->coin >= rest_cost) {
        if ((player->cur_hp < player->max_hp * player->lvl) || (player->cur_mana < player->max_mana * player->lvl)) {
          mvwaddstr(game_text, 1, 1, tavern_rest);
          player->cur_hp = player->max_hp * player->lvl; // resting restores health
          player->cur_mana = player->max_mana * player->lvl; // resting restores mana
          player->coin-=rest_cost;  // pay for room
        } else {
          mvwaddstr(game_text, 1, 1, "You don't need to rest, your health and mana are already full...");
        }
      } else {
        mvwaddstr(game_text, 1, 1, "You can't afford a room! Hit the dungeon and earn some money!");
      } break;
      case 3: mvwaddstr(game_text, 1, 1, "Feeling much better, you step out of the tavern and back into town. Come back soon!"); break;
      default: break;
    }
    refresh_stats(stats, player); // update stats window
    wrefresh(game_text);
    napms(250);
    if (choice == 3) break; // end tavern loop
  }
  wclear(select);
  mvwaddstr(select, 0, 0, "Press any key to continue...");
  wrefresh(select);
  getch();
}

// DUNGEON

// Options for dungeon maps: array of maps, randomly select one. Static, carefully created maps.
//                           randomly generated maps (might be cool for some sort of tower challenge)
//                           Could also consider using a Dungeon struct. Would contain map(s) + special
//                           locations, bosses, etc. A generic Location struct would work too, with the type
//                           set to dungeon, overland, city, etc.
//                           Might make it easy to support 2d map traversal vs. only text mode

// A tiny dungeon for testing
char dungeon_map[MAP_Y][MAP_X] = {
  "###$$$######",
  "#$$$#$$$$$$T",
  "E$###$######",
  "S####$$$####",
  "B######$$$##",
  "$$#######$##",
  "#$#######$##",
  "#$###T$$$$##",
  "#$####$##$##",
  "#$$$#$$#$$$#",
  "#T#$$$##$B$#",
  "############",
};
// dungeon key: E = entrance, # = wall, $ = path, B = boss, T = chance for treasure, S = secret passage

// been here? Track if square has already been visited on this trip to the dungeon
int been_here(int y_pos, int x_pos, int square_stack[10][2]) {
  int found = 0;

  for (int i = 0; i < 10; i++)
    if ((square_stack[i][0] == y_pos) && (square_stack[i][1] == x_pos)) found = 1;

  return found;
}

// send current position and direction you are testing
// directions are 0 = north, 1 = east, 2 = south, 3 = west
int can_move(int y, int x, int direction) {
  int orig_y = y, orig_x = x;

  switch (direction) {
    case 0: y--; break;
    case 1: x++; break;
    case 2: y++; break;
    case 3: x--; break;
    default: break;
  }
  // now test potential move - would be better to see if potential move is in a list of valid moves
  if (y < 0 || x < 0 || y > MAP_Y - 1 || x > MAP_X - 1) return 0; // stay within bounds of dungeon map // send bounds as parameters
  if (dungeon_map[y][x] == '$' || dungeon_map[y][x] == 'E' || dungeon_map[y][x] == 'T' || dungeon_map[y][x] == 'B') return 1;
  if (dungeon_map[y][x] == 'S' && dungeon_map[orig_y][orig_x] == 'B') return 1;  // one way secret passage after Boss
  else return 0;
}

// you are visiting the dungeon
void dungeon(WINDOW *game_text, WINDOW *select, WINDOW *stats, mob *player) {
  int buff, choice, lucky_coin, num_choices, specials = 0, y_pos = 2, x_pos = 0; // starting position in the dungeon
  int distance, start_coin, start_xp, mob_count, boss_count, result;
  char dungeon_prompt[96];                       // later, make this something you pass in
  int square_stack[10][2];                       // keep track of special squares, you can only do them once per dungeon trip

  snprintf(dungeon_prompt, 95, "Where to now, %s?", player->name);

  // initialize special square stack
  for (int i = 0; i < 10; i++)
    for (int j = 0; j < 2; j++) square_stack[i][j] = 0;

  // initialize dungeon delving stats
  distance = boss_count = mob_count = 0;
  start_coin = player->coin;
  start_xp   = player->xp;

  wclear(game_text);
  mvwaddstr(game_text, 0, 0, "You stop at the bottom of the stairs and light a torch.");
  wrefresh(game_text);
  // consider moving these to a new buff function in character.h
  if ((strcmp(player->role, "Cleric") == 0) && (player->buffs[2] != 1)) {
    mvwaddstr(game_text, 2, 0, "As you pray for insight, you feel danger here...");
    wrefresh(game_text);
    reset_choices();
    num_choices = y_n();
    choice = choose(select, num_choices, "Would you like to cast a buff?");
    if (choice == 0) {
      mvwprintw(game_text, 4, 0, "%s bows in prayer and asks for the aid of Teseldor.", player->name);
      napms(250);
      mvwaddstr(game_text, 6, 0, "A soothing feeling passes through your body and you are ready for anything.");
      player->buffs[2] = 1;
      player->cur_mana-=player->lvl*2;
    }
  }
  if ((strcmp(player->role, "Knight") == 0) && (player->buffs[2] != 1)) {
    mvwaddstr(game_text, 2, 0, "You've trained hard, but somehow you feel like you could use some help...");
    wrefresh(game_text);
    reset_choices();
    num_choices = y_n();
    choice = choose(select, num_choices, "Would you like to cast a buff?");
    if (choice == 0) {
      mvwprintw(game_text, 4, 0, "%s bows in prayer and asks for the aid of The Divine.", player->name);
      napms(250);
      mvwaddstr(game_text, 6, 0, "You feel divine strength flow through you.");
      player->buffs[2] = 1;
      player->cur_mana-=player->lvl*2;
    }
  }
  if ((strcmp(player->role, "Rogue") == 0) && (player->buffs[2] != 1)) {
    mvwaddstr(game_text, 2, 0, "Your finely tuned senses tell you this place is dangerous.");
    wrefresh(game_text);
    reset_choices();
    num_choices = y_n();
    choice = choose(select, num_choices, "Would you like to take a moment to prepare for what lies ahead?");
    if (choice == 0) {
      mvwprintw(game_text, 4, 0, "%s clears their mind and strengthens their awareness and senses.", player->name);
      napms(250);
      mvwaddstr(game_text, 6, 0, "Now you are ready.");
      player->buffs[2] = 1;
      player->cur_mana-=player->lvl*2;
    }
  }
  if ((strcmp(player->role, "Wizard") == 0) && (player->buffs[2] != 1)) {
    mvwaddstr(game_text, 2, 0, "Your wizard senses tingle...");
    wrefresh(game_text);
    reset_choices();
    num_choices = y_n();
    choice = choose(select, num_choices, "Would you like to summon a familiar?");
    if (choice == 0) {
      mvwprintw(game_text, 4, 0, "%s concentrates intently while casting a familiar spell...", player->name);
      napms(250);
      mvwaddstr(game_text, 6, 0, "A tiny dragon appears and curls up on your shoulder, snoring loudly.");
      player->buffs[2] = 1;
      player->cur_mana-=player->lvl*2;
    }
  }
  while(1) {
    lucky_coin = 0;
    result = 0;
    // random chance that food and drink buffs will restore some mana or health
    if (player->buffs[0] == 1) { // this is food buff
      if (dice(1, 20) > 15) player->cur_hp+= dice(1, 4); // tune this as needed
      if (player->cur_hp > player->max_hp * player->lvl) player->cur_hp = player->max_hp * player->lvl;
    }
    if (player->buffs[1] == 1) { // this is drink buff
      if (dice(1, 20) > 15) player->cur_mana+= dice(1, 4); // tune this as needed
      if (player->cur_mana > player->max_mana * player->lvl) player->cur_mana = player->max_mana * player->lvl;
    }
    // wizards rely exclusively on spells for damage (if they want to survive, lol) so let familiar help restore mana
    if ((strcmp(player->role, "Wizard") == 0) && (player->buffs[2] == 1)) {
      if (dice(1, 20) > 12) player->cur_mana+= dice(1, 2); // tune this as needed
      if (player->cur_mana > player->max_mana * player->lvl) player->cur_mana = player->max_mana * player->lvl;
    };
    refresh_stats(stats, player); // update stats window
    //mvwprintw(game_text, 9, 1, "Dungeon position: %c", dungeon_map[y_pos][x_pos]); // DEBUG
    //mvwprintw(game_text, 9, 1, "Food Buff: %d | Drink Buff: %d | Class Buff: %d", player->buffs[0], player->buffs[1], player->buffs[2]); // DEBUG
    wrefresh(game_text);
    //getch(); // DEBUG
    // clear previous list of choices - this could probably be a function
    num_choices = 0;
    // DEBUG
    // mvwaddstr(game_text, 3, 1, "Trying to clear choices");
    // wrefresh(game_text);
    // getch();
    for (int i = 0; i < MAX_CHOICES; i++) {
      memset(choices[i], 0, MAX_CHOICE_LEN);
      choice_key[i] = 99;           // "null" array
    }
    // DEBUG
    // mvwaddstr(game_text, 4, 1, "Nulled out previous choices");
    // wrefresh(game_text);
    // getch();
    // build movement choices based on current position - test each direction
    for (int i = 0; i < 4; i++) {    // directions: 0 = north, 1 = east, 2 = south, 3 = west
      if (can_move(y_pos, x_pos, i)) {
        switch (i) {
          case 0: strncpy(choices[num_choices], "North", MAX_CHOICE_LEN); choice_key[num_choices] = 0; num_choices++; break;
          case 1: strncpy(choices[num_choices], "East", MAX_CHOICE_LEN);  choice_key[num_choices] = 1; num_choices++; break;
          case 2: strncpy(choices[num_choices], "South", MAX_CHOICE_LEN); choice_key[num_choices] = 2; num_choices++; break;
          case 3: strncpy(choices[num_choices], "West", MAX_CHOICE_LEN);  choice_key[num_choices] = 3; num_choices++; break;
          default: break;
        }
      }
    }
    // now we would add any custom choices, ie. Search pile of rubble
    // strncpy(choices[num_choices], "Search rubble", MAX_CHOICE_LEN); choice_key[++num_choices] = 101; // number code for action
    // could have a table of number codes and corresponding actions: 101 = search rubble, 102 = open door, 103 = examine bookshelf
    // link that table to results table (ie. you search rubble and find coins, a rat pops out and attacks, etc.)
    // Each room in the dungeon we will roll for random combat anyway. Here we could roll for random interesting thing. Then roll
    // for random results from taking that action. Stats and class abilities could influence the rolls...
    wclear(game_text);
    // DEBUG
    // for (int i = 0; i < 4; i++) {
    //   mvwprintw(game_text, i, 1, "Choice %d: %s", i, choices[i]);
    //   wrefresh(game_text);
    //   getch();
    // }
    // later, treasure square will have a small chance to be ambushed by a boss mob if you choose to open the chest... :)
    if (dungeon_map[y_pos][x_pos] == 'T') {   // a treasure square!
      if (been_here(y_pos, x_pos, square_stack)) {}
      else {
        mvwprintw(game_text, 0, 0, "You see a treasure chest nearby. Today may be your lucky day %s!", player->name);
        wrefresh(game_text);
        strncpy(choices[num_choices], "Open treasure chest", MAX_CHOICE_LEN);  choice_key[num_choices] = 7; num_choices++;
        square_stack[specials][0] = y_pos;
        square_stack[specials][1] = x_pos;
        specials++;  // increment specials
      }
    }
    choice = choose(select, num_choices, dungeon_prompt); // make choice based on options built above where we test each direction
    // now add options for special squares
    // DEBUG
    // mvwprintw(game_text, 10, 1, "You selected %d: %s", choice, choices[choice]);
    // wrefresh(game_text);
    // getch();
    wclear(game_text);
    // handle movement
    switch (choice_key[choice]) {
      case 0: y_pos--; mvwaddstr(game_text, 0, 0, "You head north."); break;
      case 1: x_pos++; mvwaddstr(game_text, 0, 0, "You head east."); break;
      case 2: y_pos++; mvwaddstr(game_text, 0, 0, "You head south."); break;
      case 3: x_pos--; mvwaddstr(game_text, 0, 0, "You head west."); break;
      case 4: mvwaddstr(game_text, 0, 0, "You head up."); break; // 4 and 5 will be up and down for stairs and ladders
      case 5: mvwaddstr(game_text, 0, 0, "You head down."); break;
      case 7: mvwaddstr(game_text, 4, 0, "You carefully open the treasure chest and collect the coins inside."); player->coin+=dice(1, 4); break;
      default: break;
    }
    if (choice_key[choice] < 6) distance++;  // you explored another room
    // then handle special choice
    // if (choice_key[choice] > 3 ) handle special action. Use lookup tables
    if (dungeon_map[y_pos][x_pos] == '$') { // random stuff happens on general spaces, not special ones like T or B
      // random flavor text
      if (dice(1, 20) > 12) mvwprintw(game_text, 1, 0, "%s", rand_move_text[dice(1, MOVE_TEXT) - 1]);
      // random chance at coin
      if (dice(1, 20) > 19) {
        lucky_coin+=dice(1, 3);
        mvwprintw(game_text, 3, 0, "%s, it's your lucky day! You find %d coin(s) in a small pile of rubble!", player->name, lucky_coin);
        player->coin+=lucky_coin;
      }
      // now check for random combat
      if (dice(1, 20) < COMBAT_PROBABILITY) {
        result = combat(game_text, select, stats, player, 0);
        if (result == 1) mob_count++;
      }
    }
    if (dungeon_map[y_pos][x_pos] == 'B') {
      if (been_here(y_pos, x_pos, square_stack)) {}
      else {
        mvwprintw(game_text, 2, 0, "%s", rand_boss_text[dice(1, BOSS_TEXT) - 1]);
        result = combat(game_text, select, stats, player, 1);
        if (result == 1) boss_count++;
        square_stack[specials][0] = y_pos;
        square_stack[specials][1] = x_pos;
        specials++;  // increment specials
      }
    }
    refresh_stats(stats, player); // update stats window
    wrefresh(game_text);
    if (dungeon_map[y_pos][x_pos] == 'E') {
      reset_choices();
      num_choices = y_n();
      choice = choose(select, num_choices, "You are at the dungeon entrance. Would you like to leave?");
      if (choice == 0) break; // end dungeon loop
    }
  }
  wclear(game_text);
  bigly(game_text, DOOM, "YAY");
  napms(500);
  wclear(game_text);
  //celebrate(game_text);
  mvwaddstr(game_text, 0, 0, "Congratulations! You made it back out of the dungeon in one piece!");
  if (distance > 0) { // later, tailor message to how much the player earned while exploring the dungeon
    mvwprintw(game_text, 2, 0, "%s, you traveled %d squares, earned %d coin(s), %d XP, and defeated %d monster(s) and %d boss(es)...", player->name, distance, player->coin - start_coin, player->xp - start_xp, mob_count, boss_count);
  }
  wrefresh(game_text);
  celebrate(game_text);
  // Remove player buffs
  if ((strcmp(player->role, "Wizard") == 0) && (player->buffs[2] == 1)) {
    mvwaddstr(game_text, 7, 0, "Drako wishes you well and fades away, ready to help another day.");
  };
  buff = 0;
  for (int i = 0; i < MAX_BUFFS; i++) {
    if (buff == 0) {
      if (player->buffs[i] == 1) {
        mvwaddstr(game_text, 5, 0, "Your buffs fade. Hit the Tavern for more!");
        buff = 1;
      }
    }
    player->buffs[i] = 0;
  }
  wrefresh(game_text);
  wclear(select);
  mvwaddstr(select, 0, 0, "Press any key to continue...");
  wrefresh(select);
  getch();
}

// you are visiting the town
int town(WINDOW *game_text, WINDOW *select, WINDOW *stats, mob *player) {
  int choice, done = 1;

  while(done) {
    wclear(game_text);
    mvwaddstr(game_text, 1, 1, "You walk into town, looking here and there.");
    mvwaddstr(game_text, 3, 1, "Warmth and cheer emanate from an old tavern to the west.");
    mvwaddstr(game_text, 5, 1, "To the east, a sign says 'dungeon this way'.");
    wrefresh(game_text);
    reset_choices();
    num_choices = town_choices();
    choice = choose(select, num_choices, "Please choose where you will head next:");
    switch (choice) {
      case 0: armory(game_text, select, stats, player); break; // maybe add some text about walking to the armory?
      case 1: tavern(game_text, select, stats, player); break;
      case 2: wclear(game_text);
              wclear(select);
              mvwaddstr(game_text, 1, 1, "You follow the eastern path toward the dungeon, stopping");
              mvwaddstr(game_text, 2, 1, "when you reach battered gates at the entrance.");
              mvwaddstr(game_text, 4, 1, "Bracing yourself, you step down into the darkness.");
              mvwaddstr(select, 0, 0, "Press any key to continue...");
              wrefresh(game_text);
              wrefresh(select);
              getch();
              dungeon(game_text, select, stats, player);
              break;
      case 3: character_sheet(game_text, select, stats, player); break;
      case 4: wclear(game_text);
              mvwaddstr(game_text, 1, 1, "Thanks for playing, see you next time!");
              done = 0; break;
      default: break;
    }
  }

  wrefresh(game_text);
  
  return done;
}

// later add more variety for what you can do at these locations
// like maybe you can chat with the barkeep, buy a drink, etc. at the bar
// order food, chat with waitress, examine room, etc. while seated at a table
// // ### Tavern - Table
// char *table_list[4] = {
//     "Buy some food.       | Cost: 1 coin",
//     "Buy a drink.         | Cost: 1 coin",
//     "Rest.                | Cost: 2 coins",
//     "Leave the tavern."
// };

// // ### Tavern - Bar
// char *bar_list[4] = {
//     "Buy some food.       | Cost: 1 coin",
//     "Buy a drink.         | Cost: 1 coin",
//     "Rest.                | Cost: 2 coins",
//     "Leave the tavern."
// };