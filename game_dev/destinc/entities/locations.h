// game locations - town, dungeon, tavern, etc.
// each location will start with a list of options

#define TOWN 3
#define TAVERN 4
#define MAP_Y 12
#define MAP_X 12

// Town
char *town_list[TOWN] = {"The Dungeon", "Ye Olde Tavern", "Exit Game"};


// ## Tavern
// base list, later add options depending on class, quest, etc.
char *tavern_list[TAVERN] = {
  "Order some food",
  "Buy a drink",
  "Rest",
  "Leave the tavern"
};
// char *tavern_list[TAVERN] = {
//   "Buy some food.       | Cost: 1 coin",
//   "Buy a drink.         | Cost: 1 coin",
//   "Rest.                | Cost: 2 coins",
//   "Leave the tavern."
// };

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
        player->cur_hp = player->max_hp * player->lvl; // food restores health
        player->coin-=food_cost;  // pay for food
      } else {
        mvwaddstr(game_text, 1, 1, "You can't afford a meal! Go to the dungeon and earn some money!");
      } break;
      case 1: if (player->coin >= drink_cost) {
        mvwaddstr(game_text, 1, 1, tavern_bar);
        player->cur_mana = player->max_mana * player->lvl; // drink restores mana
        player->coin-=drink_cost;  // pay for drink
      } else {
        mvwaddstr(game_text, 1, 1, "You can't afford wine, you churl! Go to the dungeon and earn some money!");
      } break;
      case 2: if (player->coin >= rest_cost) {
        mvwaddstr(game_text, 1, 1, tavern_rest);
        player->cur_hp = player->max_hp * player->lvl; // resting restores health
        player->cur_mana = player->max_mana * player->lvl; // resting restores mana
        player->coin-=rest_cost;  // pay for room
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
  int choice, num_choices, y_pos = 2, x_pos = 0; // starting position in the dungeon
  char dungeon_prompt[96];                       // later, make this something you pass in

  snprintf(dungeon_prompt, 95, "Where to now, %s?", player->name);

  wclear(game_text);
  mvwaddstr(game_text, 0, 0, "Stepping into the dungeon, you prepare for adventure.");
  wrefresh(game_text);
  if ((strcmp(player->role, "Wizard") == 0) && class_buff < 1 ) {
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
  while(1) {
    mvwprintw(game_text, 9, 1, "Dungeon position: %c", dungeon_map[y_pos][x_pos]);
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
    choice = choose(select, num_choices, dungeon_prompt); // make choice based on options built above where we test each direction
    // DEBUG
    // mvwprintw(game_text, 10, 1, "You selected %d: %s", choice, choices[choice]);
    // wrefresh(game_text);
    // getch();
    wclear(game_text);
    // handle movement
    switch (choice_key[choice]) {
      case 0: y_pos--; break;
      case 1: x_pos++; break;
      case 2: y_pos++; break;
      case 3: x_pos--; break;
      case 4: mvwaddstr(game_text, 1, 1, "Great choice!"); break; // this needs some thought! how to handle custom options
      case 5: mvwaddstr(game_text, 1, 1, "Great choice!"); break;
      default: break;
    }
    // then handle special choice
    // if (choice_key[choice] > 3 ) handle special action. Use lookup tables
    if (dice(1, 20) < COMBAT_PROBABILITY) combat(game_text, select, stats, player, 0, class_buff);
    refresh_stats(stats, player); // update stats window
    wrefresh(game_text);
    if (dungeon_map[y_pos][x_pos] == 'E') {
      reset_choices();
      num_choices = y_n();
      choice = choose(select, num_choices, "You are at the dungeon entrance. Would you like to leave?");
      if (choice == 0) break; // end dungeon loop
    }
  }
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